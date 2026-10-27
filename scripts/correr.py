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
# `codigo`; zhora usa `rule_id`; daedalus, el `flag` de gcc).
CLAVES_CODIGO = ("codigo", "regla", "flag", "code", "rule_id")
CLAVES_LINEA = ("linea", "line_number", "line")

# Matriz de concordancia entre analizadores (05 §2.4, QoL #943, QoL #413):
# único dueño canónico para las reglas compartidas entre spunkmeyer, gaff, kaneda y zhora.
DUENO_UNICO_POR_REGLA = {
    "0x5004h": "kaneda",
    "0x5006h": "kaneda",
    "0x5008h": "kaneda",
    "0x500Ah": "zhora",
    "0x1008h": "gaff",
}


def firma(datos) -> dict:
    """Veredicto y hallazgos [código, línea] de una salida JSON, en cualquier profundidad."""
    hallazgos: list[list] = []

    def recorrer(nodo) -> None:
        if isinstance(nodo, dict):
            clave = next((c for c in CLAVES_CODIGO if c in nodo), None)
            clave_lin = next((l for l in CLAVES_LINEA if l in nodo), None)
            if clave and clave_lin is not None:
                hallazgos.append([str(nodo[clave]), nodo[clave_lin]])
            for clave_hija, valor in nodo.items():
                # `hallazgos` es la misma información en la forma común del ecosistema
                # (yutani.hallazgos): contarla duplicaría cada hallazgo.
                if clave_hija != "hallazgos":
                    recorrer(valor)
        elif isinstance(nodo, list):
            for valor in nodo:
                recorrer(valor)

    recorrer(datos)
    veredicto = next((datos[k] for k in VEREDICTOS if isinstance(datos, dict) and k in datos), None)
    return {"veredicto": veredicto, "hallazgos": sorted(hallazgos, key=lambda h: (h[1] or 0, h[0]))}


def verificar_concordancia_catalogos() -> list[str]:
    """Verifica que spunkmeyer, gaff, kaneda y zhora declaren un único dueño concordante por regla."""
    conflictos: list[str] = []
    comandos = {
        "gaff": ["gaff", "rules", "--json"],
        "spunkmeyer": ["spunkmeyer", "catalog", "--json"],
        "kaneda": ["kaneda", "rules", "--json"],
        "zhora": ["zhora", "rules", "--json"],
    }
    catalogos: dict[str, dict] = {}
    for nombre, cmd in comandos.items():
        if shutil.which(cmd[0]) is None:
            conflictos.append(f"concordancia: {cmd[0]} no está instalado")
            continue
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        try:
            catalogos[nombre] = json.loads(proc.stdout)
        except json.JSONDecodeError:
            conflictos.append(f"concordancia: {nombre} no emitió JSON válido")

    if len(catalogos) < 4:
        return conflictos

    gaff_duenos = {r["codigo"]: r.get("dueno") for r in catalogos["gaff"].get("reglas", [])}
    sp_duenos = {p["codigo"]: p.get("dueno") for p in catalogos["spunkmeyer"].get("patrones", [])}
    for cod, dueno_esperado in DUENO_UNICO_POR_REGLA.items():
        if gaff_duenos.get(cod) != dueno_esperado:
            conflictos.append(f"concordancia gaff[{cod}]: dueño {gaff_duenos.get(cod)} != {dueno_esperado}")
        if cod in sp_duenos and sp_duenos.get(cod) != dueno_esperado:
            conflictos.append(f"concordancia spunkmeyer[{cod}]: dueño {sp_duenos.get(cod)} != {dueno_esperado}")

    for cod, d_sp in sp_duenos.items():
        if cod in gaff_duenos and d_sp != gaff_duenos[cod]:
            conflictos.append(f"concordancia {cod}: spunkmeyer={d_sp} vs gaff={gaff_duenos[cod]}")

    for r in catalogos["kaneda"].get("reglas", []):
        if r.get("dueno") != "kaneda":
            conflictos.append(f"concordancia kaneda[{r.get('codigo')}]: dueño {r.get('dueno')} != kaneda")
    for r in catalogos["zhora"].get("reglas", []):
        if r.get("dueno") != "zhora":
            conflictos.append(f"concordancia zhora[{r.get('codigo')}]: dueño {r.get('dueno')} != zhora")

    return conflictos


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
    parser.add_argument("--concordancia", action="store_true", help="Verifica concordancia de dueño único entre analizadores.")
    args = parser.parse_args(argv)

    seleccion = casos(args.casos)
    diferencias = [d for caso in seleccion for d in correr_caso(caso, args.actualizar, args.solo)]
    if args.concordancia:
        diferencias.extend(verificar_concordancia_catalogos())
    for d in diferencias:
        print(f"✗ {d}")
    print(f"\nCasos: {len(seleccion)} · diferencias: {len(diferencias)}")
    return 1 if diferencias else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
