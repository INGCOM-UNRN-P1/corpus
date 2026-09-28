#!/usr/bin/env python3
"""Corre los analizadores sobre cada caso del corpus y compara con lo esperado.

Cada caso es una carpeta con `caso.toml`:

    descripcion = "..."
    origen = "sintético"            # o "real-anonimizado"
    hallazgo = "N-GAFF-05"          # hallazgo de la revisión que protege (opcional)

    [herramientas.gaff]
    comando = ["gaff", "check", "main.c", "--json"]

y en `esperado/<herramienta>.json` la firma esperada de su salida: el veredicto
(`ok`, `exito` o `passed`) y la lista de hallazgos como [código, línea]. Se
compara la firma y no el texto, para que mejorar la redacción de un mensaje no
rompa el corpus pero sí lo haga un falso positivo o un falso negativo.

Uso:
    correr.py [CASO ...] [--actualizar] [--solo HERRAMIENTA]

Sale con 1 si alguna firma difiere de la esperada. `--actualizar` reescribe
los esperados con la salida actual (revisar el diff antes de commitear).
"""

from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
import tomllib
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
CASOS = RAIZ / "casos"
VEREDICTOS = ("ok", "exito", "passed")
# Clave que identifica el hallazgo en cada herramienta (gaff/kaneda/spunkmeyer usan
# `codigo`; daedalus, el `flag` de gcc).
CLAVES_CODIGO = ("codigo", "regla", "flag", "code")


def firma(datos) -> dict:
    """Veredicto y hallazgos [código, línea] de una salida JSON, en cualquier profundidad."""
    hallazgos: list[list] = []

    def recorrer(nodo) -> None:
        if isinstance(nodo, dict):
            clave = next((c for c in CLAVES_CODIGO if c in nodo), None)
            if clave and "linea" in nodo:
                hallazgos.append([str(nodo[clave]), nodo["linea"]])
            for valor in nodo.values():
                recorrer(valor)
        elif isinstance(nodo, list):
            for valor in nodo:
                recorrer(valor)

    recorrer(datos)
    veredicto = next((datos[k] for k in VEREDICTOS if isinstance(datos, dict) and k in datos), None)
    return {"veredicto": veredicto, "hallazgos": sorted(hallazgos, key=lambda h: (h[1] or 0, h[0]))}


def casos(filtro: list[str]) -> list[Path]:
    todos = sorted(p.parent for p in CASOS.rglob("caso.toml"))
    return [c for c in todos if not filtro or c.name in filtro or str(c.relative_to(CASOS)) in filtro]


def correr_caso(caso: Path, actualizar: bool, solo: str | None) -> list[str]:
    config = tomllib.loads((caso / "caso.toml").read_text(encoding="utf-8"))
    diferencias = []
    for herramienta, datos in config.get("herramientas", {}).items():
        if solo and herramienta != solo:
            continue
        comando = datos["comando"]
        if shutil.which(comando[0]) is None:
            diferencias.append(f"{caso.name}/{herramienta}: {comando[0]} no está instalado")
            continue
        proc = subprocess.run(comando, cwd=caso, capture_output=True, text=True, timeout=300,
                              env={**os.environ, "NO_COLOR": "1", "TERM": "dumb", "COLUMNS": "200"})
        try:
            actual = firma(json.loads(proc.stdout))
        except json.JSONDecodeError:
            diferencias.append(f"{caso.name}/{herramienta}: no devolvió JSON (código {proc.returncode}): "
                               f"{(proc.stderr or proc.stdout).strip()[:200]}")
            continue
        esperado_ruta = caso / "esperado" / f"{herramienta}.json"
        if actualizar:
            esperado_ruta.parent.mkdir(exist_ok=True)
            esperado_ruta.write_text(json.dumps(actual, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
            continue
        if not esperado_ruta.exists():
            diferencias.append(f"{caso.name}/{herramienta}: falta {esperado_ruta.relative_to(RAIZ)} (usá --actualizar)")
            continue
        esperado = json.loads(esperado_ruta.read_text(encoding="utf-8"))
        if actual != esperado:
            sobran = [h for h in actual["hallazgos"] if h not in esperado["hallazgos"]]
            faltan = [h for h in esperado["hallazgos"] if h not in actual["hallazgos"]]
            detalle = []
            if actual["veredicto"] != esperado["veredicto"]:
                detalle.append(f"veredicto {esperado['veredicto']} → {actual['veredicto']}")
            if sobran:
                detalle.append(f"hallazgos nuevos (¿falsos positivos?): {sobran}")
            if faltan:
                detalle.append(f"hallazgos que desaparecieron (¿falsos negativos?): {faltan}")
            diferencias.append(f"{caso.name}/{herramienta}: " + "; ".join(detalle))
    return diferencias


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("casos", nargs="*")
    parser.add_argument("--actualizar", action="store_true")
    parser.add_argument("--solo", metavar="HERRAMIENTA")
    args = parser.parse_args(argv)

    seleccion = casos(args.casos)
    diferencias = [d for caso in seleccion for d in correr_caso(caso, args.actualizar, args.solo)]
    for d in diferencias:
        print(f"✗ {d}")
    print(f"\nCasos: {len(seleccion)} · diferencias: {len(diferencias)}")
    return 1 if diferencias else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
