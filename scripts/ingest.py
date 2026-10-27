#!/usr/bin/env python3
"""Sanitizador e importador de entregas históricas para el corpus (`corpus ingest --anon`).

Purga durante la importación o en sitio:
1. Artefactos compilados/temporales (binarios ELF, `.o`, `.out`, `.exe`, `.stackdump`, `.bak`)
   y carpetas de entregas anidadas (`TP*-submissions`, `entrega_*_og`).
2. Historial de commits de Git (`Sistema <sistema@example.com>` para el commit inicial y
   `<anon_id> <<anon_id>@example.com>` para los siguientes, más sanitización de mensajes y
   desconexión de remotes, empaquetando en `repo.bundle` cuando corresponde).
3. Comentarios de bloque/banners con nombres o legajos (conservando solo docblocks Doxygen),
   comentarios de línea y cadenas literales con datos personales.
4. Verificación final con `scripts/anonimizar.py` garantizando 0 datos personales antes del archivado.

Uso:
    corpus ingest --anon RUTA [RUTA ...] [--tp TPn] [--id anon_XXX] [--destino DIR] [--in-place]
"""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
if str(RAIZ) not in sys.path:
    sys.path.insert(0, str(RAIZ))

from scripts import anonimizar as mod_anon
from scripts import anonimizar_entregas as mod_entregas
from scripts import anonimizar_git as mod_git
from scripts import empaquetar_git as mod_bundle

EXTENSIONES_BASURA = {".o", ".out", ".exe", ".stackdump", ".bak", ".dll", ".so", ".dylib", ".a"}
CARPETAS_ANIDADAS = re.compile(r"^(?:TP\d+-submissions|entrega_\d+_og)$", re.IGNORECASE)
PATRON_CARPETA_TP = re.compile(r"(?i)^tp[-_]?(c?\d+)-(.+)$")


def es_ejecutable_elf(ruta: Path) -> bool:
    """Devuelve True si el archivo regular comienza con la firma mágica ELF."""
    try:
        with ruta.open("rb") as fh:
            return fh.read(4) == b"\x7fELF"
    except OSError:
        return False


def _repo_ancestro(ruta: Path) -> Path | None:
    for p in [ruta, *ruta.parents]:
        if p.name == "repo" and p.is_dir():
            return p
    return None


def purgar_artefactos_y_anidados(base_dir: Path) -> tuple[int, int, set[Path]]:
    """Elimina carpetas de entregas anidadas y binarios/temporales en base_dir."""
    repos_tocados: set[Path] = set()
    carpetas_borradas = 0
    for d in sorted(base_dir.rglob("*"), reverse=True):
        if d.is_dir() and CARPETAS_ANIDADAS.match(d.name):
            rep = _repo_ancestro(d.parent)
            if rep:
                repos_tocados.add(rep)
            shutil.rmtree(d)
            carpetas_borradas += 1

    archivos_borrados = 0
    for f in sorted(base_dir.rglob("*")):
        if not f.is_file() or ".git" in f.parts:
            continue
        if f.suffix.lower() in EXTENSIONES_BASURA or es_ejecutable_elf(f):
            rep = _repo_ancestro(f.parent)
            if rep:
                repos_tocados.add(rep)
            f.unlink(missing_ok=True)
            archivos_borrados += 1

    return carpetas_borradas, archivos_borrados, repos_tocados


def sanitizar_archivos_fuente_y_texto(base_dir: Path, codigo_anon_default: str = "anon_001") -> tuple[int, set[Path]]:
    """Purga comentarios con nombres/legajos y cadenas con datos personales en base_dir."""
    usuarios = mod_entregas.recolectar_usuarios(base_dir)
    re_ya_anon = re.compile(r"^anon_\d+(?:-anon_\d+)*$")
    usados = {u for u in usuarios if re_ya_anon.match(u)}
    mapeo: dict[str, str] = {}
    sig = 1
    for u in sorted(usuarios):
        if re_ya_anon.match(u):
            mapeo[u] = u
        else:
            while f"anon_{sig:03d}" in usados:
                sig += 1
            anon = f"anon_{sig:03d}"
            usados.add(anon)
            mapeo[u] = anon
            sig += 1

    patron_reemplazo = (
        re.compile("|".join(re.escape(u) for u in sorted(mapeo, key=lambda s: (-len(s), s))))
        if mapeo
        else None
    )

    modificados = 0
    repos_tocados: set[Path] = set()
    for archivo in sorted(base_dir.rglob("*")):
        if not archivo.is_file() or ".git" in archivo.parts or "esperado" in archivo.parts:
            continue
        if mod_anon._es_binario(archivo):
            continue
        try:
            contenido = archivo.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            continue

        nuevo = contenido
        codigo_anon = codigo_anon_default
        for parte in reversed(archivo.parts):
            m = PATRON_CARPETA_TP.match(parte)
            if m and m.group(2).lower() != "submissions":
                u_orig = m.group(2)
                codigo_anon = mapeo.get(u_orig, u_orig)
                break

        nuevo = mod_entregas.reemplazar_lineas_autor(nuevo, codigo_anon)
        if archivo.suffix.lower() in {".c", ".h", ".cpp", ".hpp"}:
            nuevo = mod_entregas.remover_comentarios_no_doc(nuevo)
        if patron_reemplazo:
            nuevo = patron_reemplazo.sub(lambda m: mapeo[m.group(0)], nuevo)
        nuevo = mod_anon.corregir(nuevo)

        if nuevo != contenido:
            archivo.write_text(nuevo, encoding="utf-8")
            modificados += 1
            rep = _repo_ancestro(archivo.parent)
            if rep:
                repos_tocados.add(rep)

    return modificados, repos_tocados


def sanitizar_git_y_bundles(
    base_dir: Path,
    codigo_anon_default: str = "anon_001",
    repos_bundle_tocados: set[Path] | None = None,
) -> int:
    """Anonimiza historiales Git (.git y repo.bundle modificados) dentro de base_dir."""
    procesados = 0

    # 1. Repositorios con repo.bundle (como casos/reales/TPn/TPn-anon_XXX)
    bundles = sorted(base_dir.rglob("repo.bundle"))
    for bundle in bundles:
        repo_dir = bundle.parent / "repo"
        if not repo_dir.is_dir():
            continue
        if repos_bundle_tocados is not None and repo_dir.resolve() not in repos_bundle_tocados:
            continue
        # Guardar snapshot del árbol de trabajo ya sanitizado
        backup_files: dict[Path, bytes] = {}
        for p in repo_dir.rglob("*"):
            if p.is_file() and ".git" not in p.parts:
                backup_files[p.relative_to(repo_dir)] = p.read_bytes()

        if not (repo_dir / ".git").exists():
            mod_bundle.restaurar_repo(bundle)

        if (repo_dir / ".git").exists():
            # Restaurar estado sanitizado sobre el worktree antes de empaquetar
            for p in list(repo_dir.rglob("*")):
                if p.is_file() and ".git" not in p.parts and p.relative_to(repo_dir) not in backup_files:
                    p.unlink(missing_ok=True)
            for rel, data in backup_files.items():
                dest = repo_dir / rel
                dest.parent.mkdir(parents=True, exist_ok=True)
                dest.write_bytes(data)

            usuario = mod_git.detectar_usuario(repo_dir)
            if usuario == "estudiante":
                usuario = codigo_anon_default
            mod_git.reconstruir_repo_git(repo_dir, usuario, dry_run=False)
            mod_bundle.empaquetar_repo(repo_dir)
            procesados += 1

    # 2. Directorios con .git directo (en la raíz de la entrega o en subcarpeta repo/)
    git_dirs = sorted(p.parent for p in base_dir.rglob(".git") if p.is_dir())
    for repo_dir in git_dirs:
        usuario = mod_git.detectar_usuario(repo_dir)
        if usuario == "estudiante":
            usuario = codigo_anon_default
        if mod_git.reconstruir_repo_git(repo_dir, usuario, dry_run=False):
            if repo_dir.name == "repo":
                mod_bundle.empaquetar_repo(repo_dir)
            procesados += 1

    return procesados


def inicializar_bundle_si_no_existe(entrega_dir: Path, usuario: str) -> bool:
    """Garantiza que una entrega importada en casos/reales tenga repo/ y repo.bundle anonimizados."""
    repo_dir = entrega_dir / "repo"
    bundle_path = entrega_dir / "repo.bundle"
    if bundle_path.exists():
        return True
    if not repo_dir.is_dir():
        return False

    if not (repo_dir / ".git").is_dir():
        subprocess.run(["git", "init", "-b", "main"], cwd=repo_dir, check=True, capture_output=True)
        subprocess.run(["git", "config", "gc.auto", "0"], cwd=repo_dir, check=True)
        subprocess.run(["git", "config", "maintenance.auto", "false"], cwd=repo_dir, check=True)
        env = {
            ** subprocess.os.environ,
            "GIT_AUTHOR_NAME": usuario,
            "GIT_AUTHOR_EMAIL": f"{usuario}@example.com",
            "GIT_COMMITTER_NAME": usuario,
            "GIT_COMMITTER_EMAIL": f"{usuario}@example.com",
        }
        subprocess.run(["git", "add", "-A"], cwd=repo_dir, check=True, capture_output=True)
        subprocess.run(
            ["git", "-c", "gc.auto=0", "-c", "maintenance.auto=false", "commit", "--allow-empty", "-m", "entrega anonimizada"],
            cwd=repo_dir,
            env=env,
            check=True,
            capture_output=True,
        )
    else:
        mod_git.reconstruir_repo_git(repo_dir, usuario, dry_run=False)

    return mod_bundle.empaquetar_repo(repo_dir)


def ingerir_entrega(
    origen: Path,
    destino_raiz: Path,
    tp: str | None = None,
    anon_id: str | None = None,
) -> Path:
    """Importa y anonimiza una entrega desde `origen` hacia `destino_raiz/<TP>/<TP>-<anon_id>`."""
    origen = origen.resolve()
    if not origen.exists():
        raise FileNotFoundError(f"No existe el origen: {origen}")

    m = PATRON_CARPETA_TP.match(origen.name)
    tp_norm = (tp or (f"TP{m.group(1).upper()}" if m else "TP1")).upper()
    if not tp_norm.startswith("TP"):
        tp_norm = f"TP{tp_norm}"

    uid = anon_id or (m.group(2) if m and m.group(2).startswith("anon_") else "anon_001")
    nombre_entrega = f"{tp_norm}-{uid}"
    destino_entrega = destino_raiz / tp_norm / nombre_entrega
    if destino_entrega.exists():
        shutil.rmtree(destino_entrega)

    if (origen / "repo").is_dir():
        shutil.copytree(origen, destino_entrega)
    else:
        repo_dest = destino_entrega / "repo"
        repo_dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(origen, repo_dest)

    _, _, tocados_art = purgar_artefactos_y_anidados(destino_entrega)
    _, tocados_txt = sanitizar_archivos_fuente_y_texto(destino_entrega, codigo_anon_default=uid)
    sanitizar_git_y_bundles(destino_entrega, codigo_anon_default=uid, repos_bundle_tocados=tocados_art | tocados_txt)
    inicializar_bundle_si_no_existe(destino_entrega, uid)
    return destino_entrega


def main(argv: list[str] | None = None) -> int:
    lista = list(sys.argv[1:] if argv is None else argv)
    if lista and lista[0] == "ingest":
        lista = lista[1:]

    parser = argparse.ArgumentParser(
        prog="corpus ingest",
        description="Importa y sanitiza entregas del corpus purgando metadatos de Git y datos personales.",
    )
    parser.add_argument("rutas", nargs="+", type=Path, help="Directorios o entregas a importar/sanitizar.")
    parser.add_argument("--anon", action="store_true", required=True, help="Activa la sanitización de autoría, Git, comentarios y cadenas.")
    parser.add_argument("--tp", help="Identificador de TP destino (ej. TP5).")
    parser.add_argument("--id", dest="anon_id", help="Identificador anónimo (ej. anon_004).")
    parser.add_argument("--destino", type=Path, default=RAIZ / "casos" / "reales", help="Directorio raíz de destino para importación.")
    parser.add_argument("--in-place", action="store_true", help="Sanitiza directamente las rutas indicadas sin copiarlas a otro destino.")
    args = parser.parse_args(lista)

    objetivos: list[Path] = []
    for ruta in args.rutas:
        if args.in_place or (args.tp is None and args.anon_id is None and ruta.resolve().is_relative_to(RAIZ)):
            base = ruta.resolve()
            carpetas, archivos, tocados_art = purgar_artefactos_y_anidados(base)
            modificados, tocados_txt = sanitizar_archivos_fuente_y_texto(base)
            repos = sanitizar_git_y_bundles(base, repos_bundle_tocados=tocados_art | tocados_txt)
            print(
                f"Sanitizado in-place {base}: {carpetas} carpetas anidadas purgadas, "
                f"{archivos} binarios/temporales eliminados, {modificados} archivos sanitizados, "
                f"{repos} repos/bundles procesados."
            )
            objetivos.append(base)
        else:
            dest = ingerir_entrega(ruta, args.destino.resolve(), tp=args.tp, anon_id=args.anon_id)
            print(f"Entrega importada y anonimizada en: {dest}")
            objetivos.append(dest)

    # Verificación estricta de 0 datos personales antes de finalizar
    rc = mod_anon.main([str(p) for p in objetivos])
    return rc


if __name__ == "__main__":
    sys.exit(main())
