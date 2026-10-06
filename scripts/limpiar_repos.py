#!/usr/bin/env python3
"""Limpia los artefactos de compilación ejecutando `make clean` en los repositorios de `casos/`.

Uso:
    scripts/limpiar_repos.py [CASOS_DIR]
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]


def limpiar_repos(base_dir: Path) -> int:
    if not base_dir.is_dir():
        print(f"Error: El directorio {base_dir} no existe.", file=sys.stderr)
        return 1

    repos = sorted(p for p in base_dir.rglob("repo") if p.is_dir())
    print(f"Encontrados {len(repos)} directorios 'repo' en {base_dir}")

    errores = 0
    limpiados = 0

    for repo in repos:
        makefile = repo / "Makefile"
        if not makefile.exists():
            continue

        cmd = ["make", "-C", str(repo), "clean"]
        res = subprocess.run(
            cmd,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.PIPE,
            text=True,
        )
        if res.returncode == 0:
            limpiados += 1
        else:
            errores += 1
            print(f"Error al limpiar {repo}:\n{res.stderr.strip()}", file=sys.stderr)

    print(f"Limpieza completada: {limpiados} repositorios limpiados, {errores} errores.")
    return 1 if errores else 0


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("directorio", nargs="?", default=RAIZ / "casos", type=Path)
    args = parser.parse_args(argv)

    return limpiar_repos(args.directorio)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
