#!/usr/bin/env python3
"""Detecta (y con --corregir, reemplaza) datos personales en los casos del corpus.

Antes de sumar una entrega real hay que tener el consentimiento del estudiante
(ver CONSENTIMIENTO.md) y quitarle todo lo que lo identifique: nombre en los
comentarios de autoría, correo, legajo, DNI y usuario de GitHub. Este script
revisa todos los archivos de texto de `casos/` y sale con 1 si encuentra algo.

Uso:
    anonimizar.py [RUTA ...] [--corregir]
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
EXTENSIONES = {".c", ".h", ".md", ".txt", ".toml", ".in", ".out", ".json", ".mk", ""}

# (descripción, patrón, reemplazo)
PATRONES = [
    ("correo", re.compile(r"[\w.+-]+@[\w-]+(?:\.[\w-]+)+"), "estudiante@example.com"),
    # Los reemplazos quedan excluidos de cada patrón para que un archivo corregido pase la revisión.
    ("DNI", re.compile(r"\b(?!00\.000\.000\b)\d{1,2}\.\d{3}\.\d{3}\b"), "00.000.000"),
    ("DNI sin puntos", re.compile(r"(?i)\b(dni|documento)\s*[:#]?\s*(?!00000000\b)\d{7,8}\b"), r"\1 00000000"),
    (
        "legajo",
        re.compile(r"(?i)\b(legajo|leg\.|matr[ií]cula)\s*[:#]?\s*(?!00000\b|UNRN-00000\b)(?:UNRN-\d+|\d{3,})"),
        r"\1 00000",
    ),
    (
        "autoría",
        re.compile(
            r"(?im)^(\s*(?:/?\*+|//|-)?\s*(?:\*{1,2})?(?:@?autor(?:a|es)?|@author|alumn[oa]s?|estudiantes?|nombre\s+y\s+apellido|integrantes?)(?:\*{1,2})?\s*:?\s+)(?!\[anonimizado\]|`?anon_\d+`?(?:\s*-\s*`?anon_\d+`?)*$).+$"
        ),
        r"\1[anonimizado]",
    ),
    (
        "cadena con dato personal",
        re.compile(
            r'"([^"\n]*?\b(?:Autor(?:a|es)?|Alumn[oa]|Estudiante|Legajo|Matr[ií]cula|DNI)\s*:\s*)(?!\s*\[anonimizado\])[^"\n]+"',
            re.IGNORECASE,
        ),
        r'"\1[anonimizado]"',
    ),
    (
        "usuario de GitHub",
        re.compile(r"github\.com/(?!INGCOM-UNRN\b|orgs/|estudiante\b|anon_\d+\b)[A-Za-z0-9-]+"),
        "github.com/estudiante",
    ),
]
PERMITIDOS = {"estudiante@example.com", "sistema@example.com"}
RE_CORREO_ANON = re.compile(r"^anon_\d+(?:-anon_\d+)*@example\.com$")


def _es_permitido(valor: str) -> bool:
    return valor in PERMITIDOS or bool(RE_CORREO_ANON.match(valor))


def revisar(texto: str) -> list[tuple[str, int, str]]:
    hallados = []
    for nombre, patron, _ in PATRONES:
        for m in patron.finditer(texto):
            if _es_permitido(m.group(0)):
                continue
            linea = texto.count("\n", 0, m.start()) + 1
            hallados.append((nombre, linea, m.group(0).strip()))
    return hallados


def corregir(texto: str) -> str:
    for _, patron, reemplazo in PATRONES:
        texto = patron.sub(lambda m, r=reemplazo: m.group(0) if _es_permitido(m.group(0)) else m.expand(r), texto)
    return texto


def _es_binario(archivo: Path) -> bool:
    try:
        with archivo.open("rb") as fh:
            return b"\x00" in fh.read(4096)
    except OSError:
        return True


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("rutas", nargs="*", type=Path)
    parser.add_argument("--corregir", action="store_true")
    args = parser.parse_args(argv)

    archivos = []
    for base in args.rutas or [RAIZ / "casos"]:
        archivos += [base] if base.is_file() else [p for p in sorted(base.rglob("*")) if p.is_file()]
    total = 0
    for archivo in archivos:
        if (
            archivo.suffix not in EXTENSIONES
            or "esperado" in archivo.parts
            or ".git" in archivo.parts
            or _es_binario(archivo)
        ):
            continue
        texto = archivo.read_text(encoding="utf-8", errors="replace")
        hallados = revisar(texto)
        if hallados and args.corregir:
            archivo.write_text(corregir(texto), encoding="utf-8")
        for nombre, linea, valor in hallados:
            print(f"{'corregido' if args.corregir else 'dato personal'}: {archivo}:{linea}: {nombre} «{valor}»")
        total += len(hallados)
    print(f"\nDatos personales {'corregidos' if args.corregir else 'encontrados'}: {total}")
    return 1 if total and not args.corregir else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
