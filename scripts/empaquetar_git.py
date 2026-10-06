#!/usr/bin/env python3
"""Gestiona los repositorios Git en `casos/` empaquetándolos como bundles o restaurándolos.

Para cada directorio `repo`:
- empaquetar (default):
    1. Si hay cambios pendientes en el worktree, los commitea con autor anonimizado.
    2. Desconecta cualquier remote Git.
    3. Genera un `repo.bundle` autocontenido con todo el historial.
    4. Elimina la carpeta `.git` para que los archivos del repositorio queden planos.
- restaurar:
    1. Si existe `repo.bundle` y no existe `repo/.git`, restaura `.git` desde el bundle.
    2. Elimina cualquier remote configurado por `git clone`.
- limpiar:
    1. Si existe `repo/.git` y existe `repo.bundle`, elimina `repo/.git`.

Uso:
    scripts/empaquetar_git.py [empaquetar|restaurar|limpiar] [CASOS_DIR]
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
PATRON_ENTREGA = re.compile(r"^TP\d+-(.+)$")


def detectar_usuario(repo_path: Path) -> str:
    """Extrae el usuario anonimizado asociado al directorio repo a partir de TPn-<usuario>."""
    for part in reversed(repo_path.parts):
        m = PATRON_ENTREGA.match(part)
        if m and m.group(1) != "submissions":
            return m.group(1)
    return "estudiante"


def desconectar_remotes(repo_path: Path) -> list[str]:
    """Elimina todos los remotes de un repositorio Git."""
    if not (repo_path / ".git").exists():
        return []

    res = subprocess.run(
        ["git", "-C", str(repo_path), "remote"],
        capture_output=True,
        text=True,
    )
    if res.returncode != 0:
        return []

    remotes = [r.strip() for r in res.stdout.splitlines() if r.strip()]
    eliminados = []
    for r in remotes:
        subprocess.run(
            ["git", "-C", str(repo_path), "remote", "remove", r],
            capture_output=True,
            text=True,
        )
        eliminados.append(r)
    return eliminados


def empaquetar_repo(repo_path: Path) -> bool:
    """Empaqueta el historial en repo.bundle y elimina repo/.git."""
    git_dir = repo_path / ".git"
    if not git_dir.exists():
        return False

    bundle_path = repo_path.parent / "repo.bundle"

    # Si hay cambios sin commitear en el worktree, commitearlos con autor anonimizado
    res_status = subprocess.run(
        ["git", "-C", str(repo_path), "status", "--porcelain"],
        capture_output=True,
        text=True,
    )
    if res_status.stdout.strip():
        usuario = detectar_usuario(repo_path)
        env = os.environ.copy()
        env["GIT_AUTHOR_NAME"] = usuario
        env["GIT_AUTHOR_EMAIL"] = f"{usuario}@example.com"
        env["GIT_COMMITTER_NAME"] = usuario
        env["GIT_COMMITTER_EMAIL"] = f"{usuario}@example.com"

        subprocess.run(["git", "-C", str(repo_path), "add", "-A"], check=True, capture_output=True)
        subprocess.run(
            [
                "git",
                "-c", "gc.auto=0",
                "-c", "maintenance.auto=false",
                "-C", str(repo_path),
                "commit",
                "-m", "anonimizar entrega",
            ],
            env=env,
            check=True,
            capture_output=True,
        )

    desconectar_remotes(repo_path)

    # Crear bundle con todas las ramas y tags
    res_bundle = subprocess.run(
        ["git", "-C", str(repo_path), "bundle", "create", str(bundle_path), "--all"],
        capture_output=True,
        text=True,
    )
    if res_bundle.returncode != 0:
        print(f"Error al crear bundle en {repo_path}:\n{res_bundle.stderr.strip()}", file=sys.stderr)
        return False

    # Eliminar .git para dejar archivos planos
    shutil.rmtree(git_dir)
    return True


def restaurar_repo(bundle_path: Path) -> bool:
    """Restaura repo/.git a partir de repo.bundle si no existe."""
    repo_path = bundle_path.parent / "repo"
    git_dir = repo_path / ".git"
    if git_dir.exists():
        return True

    repo_path.mkdir(exist_ok=True)
    with tempfile.TemporaryDirectory() as td:
        tmp_dst = Path(td) / "clone"
        res_clone = subprocess.run(
            ["git", "clone", "-q", str(bundle_path), str(tmp_dst)],
            capture_output=True,
            text=True,
        )
        if res_clone.returncode != 0:
            print(f"Error al clonar bundle {bundle_path}:\n{res_clone.stderr.strip()}", file=sys.stderr)
            return False

        shutil.move(tmp_dst / ".git", git_dir)

    desconectar_remotes(repo_path)
    return True


def limpiar_repo(repo_path: Path) -> bool:
    """Elimina repo/.git si ya existe repo.bundle."""
    bundle_path = repo_path.parent / "repo.bundle"
    git_dir = repo_path / ".git"
    if git_dir.exists() and bundle_path.exists():
        shutil.rmtree(git_dir)
        return True
    return False


def ejecutar(accion: str, base_dir: Path) -> int:
    if not base_dir.is_dir():
        print(f"Error: {base_dir} no es un directorio válido.", file=sys.stderr)
        return 1

    if accion == "empaquetar":
        repos = sorted(p for p in base_dir.rglob("repo") if (p / ".git").exists())
        print(f"Empaquetando {len(repos)} repositorios Git en {base_dir}...")
        exitos = 0
        for r in repos:
            if empaquetar_repo(r):
                exitos += 1
                # Actualizar el índice del repositorio corpus si aplica
                bundle = r.parent / "repo.bundle"
                try:
                    subprocess.run(
                        ["git", "rm", "--cached", "--quiet", "--ignore-unmatch", str(r.relative_to(RAIZ))],
                        cwd=RAIZ,
                        capture_output=True,
                    )
                    subprocess.run(
                        ["git", "add", str(r.relative_to(RAIZ)), str(bundle.relative_to(RAIZ))],
                        cwd=RAIZ,
                        capture_output=True,
                    )
                except Exception:
                    pass
        print(f"Empaquetado finalizado: {exitos}/{len(repos)} procesados.")
        return 0

    elif accion == "restaurar":
        bundles = sorted(base_dir.rglob("repo.bundle"))
        print(f"Restaurando {len(bundles)} repositorios Git desde bundles en {base_dir}...")
        exitos = 0
        for b in bundles:
            if restaurar_repo(b):
                exitos += 1
        print(f"Restauración finalizada: {exitos}/{len(bundles)} procesados.")
        return 0

    elif accion == "limpiar":
        repos = sorted(p for p in base_dir.rglob("repo") if (p / ".git").exists())
        print(f"Limpiando {len(repos)} directorios .git en {base_dir}...")
        exitos = 0
        for r in repos:
            if limpiar_repo(r):
                exitos += 1
        print(f"Limpieza finalizada: {exitos}/{len(repos)} directorios .git eliminados.")
        return 0

    else:
        print(f"Acción desconocida: {accion}", file=sys.stderr)
        return 1


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "accion",
        nargs="?",
        default="empaquetar",
        choices=["empaquetar", "restaurar", "limpiar"],
        help="Acción a realizar (por defecto: empaquetar).",
    )
    parser.add_argument("directorio", nargs="?", default=RAIZ / "casos", type=Path)
    args = parser.parse_args(argv)

    return ejecutar(args.accion, args.directorio.resolve())


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
