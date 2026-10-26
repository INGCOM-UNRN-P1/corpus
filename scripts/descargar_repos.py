#!/usr/bin/env python3
"""Descarga o clona repositorios de una organización de GitHub según prefijo.

Por defecto busca en la organización INGCOM-UNRN-P1 todos los repositorios
cuyo nombre comience con 'tp' (insensible a mayúsculas y minúsculas).

Uso:
    scripts/descargar_repos.py [DESTINO] [OPCIONES]

Ejemplos:
    scripts/descargar_repos.py descargas/
    scripts/descargar_repos.py descargas/ --dry-run
    scripts/descargar_repos.py descargas/ --protocolo ssh --jobs 8
    scripts/descargar_repos.py descargas/ --depth 1 --actualizar
"""

from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
import urllib.error
import urllib.parse
import urllib.request
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from typing import TypedDict


class InfoRepo(TypedDict):
    name: str
    url: str
    sshUrl: str


def obtener_repos_gh(org: str, limite: int = 5000) -> list[InfoRepo]:
    """Obtiene la lista de repositorios usando el CLI de GitHub (`gh`)."""
    if not shutil.which("gh"):
        raise RuntimeError("CLI 'gh' no encontrado en el sistema.")

    cmd = [
        "gh",
        "repo",
        "list",
        org,
        "--limit",
        str(limite),
        "--json",
        "name,url,sshUrl",
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    if res.returncode != 0:
        raise RuntimeError(f"Error al listar con gh:\n{res.stderr.strip()}")

    data = json.loads(res.stdout)
    return [
        InfoRepo(
            name=item["name"],
            url=item.get("url", f"https://github.com/{org}/{item['name']}"),
            sshUrl=item.get("sshUrl", f"git@github.com:{org}/{item['name']}.git"),
        )
        for item in data
    ]


def obtener_repos_api(org: str, token: str | None = None, limite: int = 5000) -> list[InfoRepo]:
    """Obtiene la lista de repositorios consumiendo directamente la API REST de GitHub."""
    token = token or os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN")
    repos: list[InfoRepo] = []
    page = 1
    per_page = 100

    while True:
        url = f"https://api.github.com/orgs/{urllib.parse.quote(org)}/repos?per_page={per_page}&page={page}"
        req = urllib.request.Request(
            url,
            headers={
                "Accept": "application/vnd.github+json",
                "User-Agent": "corpus-downloader",
                **({"Authorization": f"Bearer {token}"} if token else {}),
            },
        )
        try:
            with urllib.request.urlopen(req) as resp:
                data = json.loads(resp.read().decode("utf-8"))
        except urllib.error.HTTPError as e:
            raise RuntimeError(f"Error HTTP {e.code} al consultar la API de GitHub: {e.reason}") from e
        except urllib.error.URLError as e:
            raise RuntimeError(f"Error de red al consultar la API de GitHub: {e.reason}") from e

        if not data:
            break

        for item in data:
            repos.append(
                InfoRepo(
                    name=item["name"],
                    url=item.get("html_url", f"https://github.com/{org}/{item['name']}"),
                    sshUrl=item.get("ssh_url", f"git@github.com:{org}/{item['name']}.git"),
                )
            )
            if len(repos) >= limite:
                return repos[:limite]

        if len(data) < per_page:
            break

        page += 1

    return repos


def listar_repositorios(org: str, limite: int = 5000) -> list[InfoRepo]:
    """Obtiene los repositorios intentando con `gh` y recurriendo a la API REST si es necesario."""
    try:
        return obtener_repos_gh(org, limite=limite)
    except Exception as e:
        print(f"Aviso: Falló la consulta con 'gh' ({e}). Probando API REST...", file=sys.stderr)
        return obtener_repos_api(org, limite=limite)


def filtrar_repos_por_prefijo(repos: list[InfoRepo], prefijo: str) -> list[InfoRepo]:
    """Filtra repositorios cuyo nombre comience con el prefijo indicado (case-insensitive)."""
    prefijo_norm = prefijo.lower()
    return [r for r in repos if r["name"].lower().startswith(prefijo_norm)]


def procesar_repo(
    repo: InfoRepo,
    destino_dir: Path,
    protocolo: str = "https",
    depth: int | None = None,
    actualizar: bool = False,
) -> tuple[bool, str]:
    """Clona o actualiza un repositorio individual.

    Retorna (éxito, mensaje).
    """
    repo_dir = destino_dir / repo["name"]
    clone_url = repo["sshUrl"] if protocolo == "ssh" else repo["url"]

    if repo_dir.exists():
        if (repo_dir / ".git").is_dir():
            if actualizar:
                res = subprocess.run(
                    ["git", "-C", str(repo_dir), "pull"],
                    capture_output=True,
                    text=True,
                )
                if res.returncode != 0:
                    return False, f"[{repo['name']}] Error al actualizar:\n{res.stderr.strip()}"
                return True, f"[{repo['name']}] Actualizado con git pull"
            return True, f"[{repo['name']}] Omitido (ya existe)"
        return False, f"[{repo['name']}] El destino existe pero no es un repositorio Git válido"

    cmd = ["git", "clone"]
    if depth is not None and depth > 0:
        cmd.extend(["--depth", str(depth)])
    cmd.extend([clone_url, str(repo_dir)])

    res = subprocess.run(cmd, capture_output=True, text=True)
    if res.returncode != 0:
        return False, f"[{repo['name']}] Error al clonar:\n{res.stderr.strip()}"
    return True, f"[{repo['name']}] Clonado exitosamente"


def descargar_repos(
    org: str = "INGCOM-UNRN-P1",
    prefijo: str = "tp",
    destino: Path | None = None,
    protocolo: str = "https",
    jobs: int = 4,
    depth: int | None = None,
    actualizar: bool = False,
    dry_run: bool = False,
    limite: int = 5000,
) -> int:
    """Función principal para buscar y descargar los repositorios correspondientes."""
    destino_dir = (destino or Path("descargas")).resolve()

    print(f"Consultando repositorios de la organización '{org}'...")
    try:
        todos = listar_repositorios(org, limite=limite)
    except Exception as e:
        print(f"Error: No se pudieron obtener los repositorios de '{org}': {e}", file=sys.stderr)
        return 1

    coincidentes = filtrar_repos_por_prefijo(todos, prefijo)
    print(
        f"Total repositorios encontrados: {len(todos)}. "
        f"Coincidentes con prefijo '{prefijo}' (case-insensitive): {len(coincidentes)}"
    )

    if dry_run:
        print("\nModo dry-run activado. Repositorios que se descargarían:")
        for r in coincidentes:
            url = r["sshUrl"] if protocolo == "ssh" else r["url"]
            print(f" - {r['name']} ({url})")
        return 0

    if not coincidentes:
        print("No se encontraron repositorios para descargar.")
        return 0

    destino_dir.mkdir(parents=True, exist_ok=True)
    print(f"Descargando en: {destino_dir} (concurrencia: {jobs}, protocolo: {protocolo})...\n")

    errores = 0
    con_exito = 0

    with ThreadPoolExecutor(max_workers=max(1, jobs)) as pool:
        futuros = {
            pool.submit(
                procesar_repo,
                repo,
                destino_dir,
                protocolo=protocolo,
                depth=depth,
                actualizar=actualizar,
            ): repo
            for repo in coincidentes
        }

        for fut in as_completed(futuros):
            ok, mensaje = fut.result()
            print(mensaje)
            if ok:
                con_exito += 1
            else:
                errores += 1

    print(f"\nFinalizado: {con_exito} procesados exitosamente, {errores} errores.")
    return 1 if errores > 0 else 0


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="Descarga todos los repositorios de una organización que inicien con un prefijo."
    )
    parser.add_argument(
        "destino",
        nargs="?",
        default="descargas",
        help="Directorio donde clonar los repositorios (por defecto: descargas)",
    )
    parser.add_argument(
        "--org",
        default="INGCOM-UNRN-P1",
        help="Organización de GitHub (por defecto: INGCOM-UNRN-P1)",
    )
    parser.add_argument(
        "--prefijo",
        default="tp",
        help="Prefijo para filtrar los nombres de repositorios (por defecto: tp)",
    )
    parser.add_argument(
        "--protocolo",
        choices=["https", "ssh"],
        default="https",
        help="Protocolo de clonación Git: https o ssh (por defecto: https)",
    )
    parser.add_argument(
        "-j",
        "--jobs",
        type=int,
        default=4,
        help="Cantidad de descargas en paralelo (por defecto: 4)",
    )
    parser.add_argument(
        "--depth",
        type=int,
        default=None,
        help="Profundidad de clonado para repositorios nuevos (ej: 1 para shallow clone)",
    )
    parser.add_argument(
        "--actualizar",
        action="store_true",
        help="Si el repositorio ya existe localmente, ejecuta git pull",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Muestra qué repositorios coinciden sin descargarlos",
    )
    parser.add_argument(
        "--limite",
        type=int,
        default=5000,
        help="Límite máximo de repositorios a consultar en la organización (por defecto: 5000)",
    )

    args = parser.parse_args(argv)
    return descargar_repos(
        org=args.org,
        prefijo=args.prefijo,
        destino=Path(args.destino),
        protocolo=args.protocolo,
        jobs=args.jobs,
        depth=args.depth,
        actualizar=args.actualizar,
        dry_run=args.dry_run,
        limite=args.limite,
    )


if __name__ == "__main__":
    sys.exit(main())
