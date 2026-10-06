#!/usr/bin/env python3
"""Sustituye los repositorios Git dentro de `casos/` por repositorios nuevos con historial anonimizado.

Para cada directorio `repo` que contenga `.git`:
- Identifica el identificador de usuario anónimo (ej: `anon_001`) a partir del directorio contenedor `TPn-<usuario>`.
- Reconstruye el historial de commits manteniendo la secuencia, fechas y mensajes.
- El primer commit (commit raíz/inicial) se asigna al usuario de sistema:
    Nombre: "Sistema"
    Email:  "sistema@example.com"
- Los commits subsiguientes se asignan al usuario de la entrega:
    Nombre: "<usuario>"
    Email:  "<usuario>@example.com"
- Reemplaza el subdirectorio `.git` por el nuevo repositorio limpio y anonimizado.

Uso:
    scripts/anonimizar_git.py [CASOS_DIR] [--dry-run]
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

SISTEMA_NOMBRE = "Sistema"
SISTEMA_EMAIL = "sistema@example.com"


def detectar_usuario(repo_path: Path) -> str:
    """Extrae el usuario anonimizado asociado a un directorio repo buscando TPn-<usuario> en sus ancestros."""
    for part in reversed(repo_path.parts):
        m = PATRON_ENTREGA.match(part)
        if m and m.group(1) != "submissions":
            return m.group(1)
    return "estudiante"


def reconstruir_repo_git(repo_path: Path, usuario: str, dry_run: bool = False) -> bool:
    """Reconstruye el historial de Git del repositorio en un nuevo repositorio anonimizado."""
    git_dir = repo_path / ".git"
    if not git_dir.is_dir():
        return False

    # Limpiar posibles bloqueos de background gc/maintenance previos
    maintenance_lock = git_dir / "objects" / "maintenance.lock"
    if maintenance_lock.exists():
        maintenance_lock.unlink(missing_ok=True)

    # Obtener el nombre de la rama actual (por defecto main si detached)
    res_branch = subprocess.run(
        ["git", "-C", str(repo_path), "branch", "--show-current"],
        capture_output=True,
        text=True,
    )
    branch_name = res_branch.stdout.strip() or "main"

    # Obtener la lista ordenada de commits desde la raíz hasta HEAD
    res_commits = subprocess.run(
        ["git", "-C", str(repo_path), "rev-list", "--reverse", "HEAD"],
        capture_output=True,
        text=True,
    )
    if res_commits.returncode != 0:
        print(f"Error al listar commits en {repo_path}: {res_commits.stderr.strip()}", file=sys.stderr)
        return False

    commits = [c for c in res_commits.stdout.strip().splitlines() if c]
    if not commits:
        return True

    if dry_run:
        print(f"[dry-run] Reconstruyendo {repo_path} ({len(commits)} commits, usuario: {usuario})")
        return True

    with tempfile.TemporaryDirectory() as tmpdir:
        dest_repo = Path(tmpdir) / "nuevo_repo"
        dest_repo.mkdir()

        # Inicializar repositorio destino con la misma rama principal y deshabilitar gc/maintenance en segundo plano
        subprocess.run(
            ["git", "init", "-b", branch_name],
            cwd=dest_repo,
            check=True,
            capture_output=True,
        )
        subprocess.run(["git", "config", "gc.auto", "0"], cwd=dest_repo, check=True)
        subprocess.run(["git", "config", "maintenance.auto", "false"], cwd=dest_repo, check=True)

        for idx, commit_hash in enumerate(commits):
            # Limpiar contenido del worktree destino
            subprocess.run(["git", "rm", "-rf", "."], cwd=dest_repo, capture_output=True)

            # Extraer archivos del commit histórico hacia dest_repo
            proc_archive = subprocess.Popen(
                ["git", "-C", str(repo_path), "archive", commit_hash],
                stdout=subprocess.PIPE,
            )
            subprocess.run(["tar", "-x", "-C", str(dest_repo)], stdin=proc_archive.stdout, check=True)
            proc_archive.wait()

            # Obtener autoría y metadatos
            meta = subprocess.run(
                ["git", "-C", str(repo_path), "log", "-1", "--format=%ad%x00%cd%x00%B", commit_hash],
                capture_output=True,
                text=True,
                check=True,
            ).stdout
            ad, cd, msg = meta.split("\x00", 2)

            if idx == 0:
                autor_nombre = SISTEMA_NOMBRE
                autor_email = SISTEMA_EMAIL
            else:
                autor_nombre = usuario
                autor_email = f"{usuario}@example.com"

            env = os.environ.copy()
            env["GIT_AUTHOR_NAME"] = autor_nombre
            env["GIT_AUTHOR_EMAIL"] = autor_email
            env["GIT_AUTHOR_DATE"] = ad
            env["GIT_COMMITTER_NAME"] = autor_nombre
            env["GIT_COMMITTER_EMAIL"] = autor_email
            env["GIT_COMMITTER_DATE"] = cd

            subprocess.run(["git", "add", "-A"], cwd=dest_repo, check=True, capture_output=True)
            subprocess.run(
                [
                    "git",
                    "-c", "gc.auto=0",
                    "-c", "maintenance.auto=false",
                    "commit",
                    "--allow-empty",
                    "-m", msg,
                ],
                cwd=dest_repo,
                env=env,
                check=True,
                capture_output=True,
            )

        # Empaquetar y podar para dejar los objetos en un solo pack file compacto y sin archivos efímeros
        subprocess.run(
            ["git", "-c", "gc.auto=0", "-c", "maintenance.auto=false", "repack", "-a", "-d"],
            cwd=dest_repo,
            check=True,
            capture_output=True,
        )
        subprocess.run(
            ["git", "-c", "gc.auto=0", "-c", "maintenance.auto=false", "prune"],
            cwd=dest_repo,
            check=True,
            capture_output=True,
        )

        # Copiar de forma atómica: crear directorio temporal en el repo original y luego sustituir
        git_staging = repo_path / ".git_reconstruido"
        if git_staging.exists():
            shutil.rmtree(git_staging)

        shutil.copytree(dest_repo / ".git", git_staging)
        shutil.rmtree(git_dir)
        git_staging.rename(git_dir)

    return True


def procesar_todos_los_repos(base_dir: Path, dry_run: bool = False) -> int:
    repos = sorted(p for p in base_dir.rglob("repo") if (p / ".git").is_dir())
    print(f"Encontrados {len(repos)} repositorios Git en {base_dir}")

    exitos = 0
    errores = 0

    for idx, repo in enumerate(repos, 1):
        usuario = detectar_usuario(repo)
        ok = reconstruir_repo_git(repo, usuario, dry_run=dry_run)
        if ok:
            exitos += 1
        else:
            errores += 1

    print(f"\nProceso finalizado: {exitos} repositorios procesados, {errores} errores.")
    return 1 if errores else 0


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("directorio", nargs="?", default=RAIZ / "casos", type=Path)
    parser.add_argument("--dry-run", action="store_true", help="Simula sin modificar los repositorios.")
    args = parser.parse_args(argv)

    base_dir = args.directorio.resolve()
    if not base_dir.is_dir():
        print(f"Error: {base_dir} no es un directorio válido.", file=sys.stderr)
        return 1

    return procesar_todos_los_repos(base_dir, dry_run=args.dry_run)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
