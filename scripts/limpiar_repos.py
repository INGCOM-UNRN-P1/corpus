#!/usr/bin/env python3
"""Limpia artefactos (`make clean`) y desconecta remotes de Git en los repositorios de `casos/`.

Uso:
    scripts/limpiar_repos.py [CASOS_DIR]
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]


def desconectar_remotes(repo: Path) -> tuple[bool, list[str]]:
    """Desconecta todos los remotes configurados en el repositorio Git.

    Retorna (éxito, lista_remotes_eliminados).
    """
    if not (repo / ".git").exists():
        return True, []

    res = subprocess.run(
        ["git", "-C", str(repo), "remote"],
        capture_output=True,
        text=True,
    )
    if res.returncode != 0:
        print(f"Error al listar remotes en {repo}:\n{res.stderr.strip()}", file=sys.stderr)
        return False, []

    remotes = [r.strip() for r in res.stdout.splitlines() if r.strip()]
    eliminados = []
    for r in remotes:
        res_rm = subprocess.run(
            ["git", "-C", str(repo), "remote", "remove", r],
            capture_output=True,
            text=True,
        )
        if res_rm.returncode != 0:
            print(f"Error al desconectar remote '{r}' en {repo}:\n{res_rm.stderr.strip()}", file=sys.stderr)
            return False, eliminados
        eliminados.append(r)

    return True, eliminados


def limpiar_repos(base_dir: Path) -> int:
    if not base_dir.is_dir():
        print(f"Error: El directorio {base_dir} no existe.", file=sys.stderr)
        return 1

    repos = sorted(p for p in base_dir.rglob("repo") if p.is_dir())
    print(f"Encontrados {len(repos)} directorios 'repo' en {base_dir}")

    errores = 0
    limpiados = 0
    remotes_desconectados = 0

    for repo in repos:
        makefile = repo / "Makefile"
        es_git = (repo / ".git").exists()

        if not makefile.exists() and not es_git:
            continue

        repo_error = False

        if makefile.exists():
            cmd = ["make", "-C", str(repo), "clean"]
            res = subprocess.run(
                cmd,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.PIPE,
                text=True,
            )
            if res.returncode != 0:
                repo_error = True
                print(f"Error al limpiar {repo}:\n{res.stderr.strip()}", file=sys.stderr)

        ok_remote, eliminados = desconectar_remotes(repo)
        if not ok_remote:
            repo_error = True
        elif eliminados:
            remotes_desconectados += len(eliminados)
            for r in eliminados:
                print(f"Desconectado remote '{r}' en {repo}")

        if repo_error:
            errores += 1
        else:
            limpiados += 1

    print(
        f"Limpieza completada: {limpiados} repositorios limpiados, "
        f"{remotes_desconectados} remotes desconectados, {errores} errores."
    )
    return 1 if errores else 0


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("directorio", nargs="?", default=RAIZ / "casos", type=Path)
    args = parser.parse_args(argv)

    return limpiar_repos(args.directorio)



if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
