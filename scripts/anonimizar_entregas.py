#!/usr/bin/env python3
"""Anonimiza los casos del corpus reemplazando nombres de usuario y removiendo comentarios no de documentación.

Busca carpetas con el patrón `TPn-<nombreusuario>` dentro de `casos/` (o la ruta provista),
reemplaza los nombres de usuario en nombres de directorios, nombres de archivos y contenidos,
reemplaza las líneas de autoría ("Autor:", "**Autor:**", etc.) por el código anónimo correspondiente,
y remueve comentarios de bloque de C (`/* ... */`) que no comiencen con `/**`.

Opcionalmente, recopila todos los comentarios de línea (`// ...`) numerados en un archivo
de salida especificado por `--recopilar-lineas`.

Uso:
    scripts/anonimizar_entregas.py [CASOS_DIR] [--dry-run] [--recopilar-lineas ARCHIVO]
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[1]
PATRON_ENTREGA = re.compile(r"^TP\d+-(.+)$")

# Regex para proteger strings literales y caracteres mientras se remueven comentarios /* ... */
REGEX_COMENTARIOS_C = re.compile(
    r'("(?:\\.|[^"\\])*")|'          # String literal
    r"('(?:\\.|[^'\\])*')|"          # Carácter literal
    r"(/\*\*[\s\S]*?\*/)|"           # Comentario de documentación /** ... */
    r"(/\*[\s\S]*?\*/)"              # Comentario de bloque común /* ... */
)

# Regex para detectar comentarios de línea // ... respetando strings y comentarios de bloque
REGEX_COMENTARIOS_LINEA = re.compile(
    r'("(?:\\.|[^"\\])*")|'          # String literal
    r"('(?:\\.|[^'\\])*')|"          # Carácter literal
    r"(/\*[\s\S]*?\*/)|"             # Comentario de bloque /* ... */
    r"(//[^\n]*)"                    # Comentario de línea // ...
)

# Regex para detectar líneas con autoría (e.g., Autor: Juan, **Autor:** `Pedro`, * @autor Maria)
REGEX_LINEA_AUTOR = re.compile(
    r"(?im)^(\s*(?:/?\*+|//)?\s*(?:\*{1,2}@?autor(?:a|es)?:?\*{1,2}:?|@?autor(?:a|es)?:?|@author:?)\s+)(?:`[^`\n]+`|\[anonimizado\]|[^\n]+)$"
)


def remover_comentarios_no_doc(contenido: str) -> str:
    """Elimina comentarios de bloque /* ... */ conservando /** ... */ y strings literales."""
    def reemplazar(m: re.Match) -> str:
        if m.group(1):  # string literal
            return m.group(1)
        if m.group(2):  # char literal
            return m.group(2)
        if m.group(3):  # /** ... */
            return m.group(3)
        return ""  # /* ... */ no documental

    return REGEX_COMENTARIOS_C.sub(reemplazar, contenido)


def reemplazar_lineas_autor(contenido: str, codigo_anon: str) -> str:
    """Reemplaza el nombre de autor en líneas de autoría por el código anónimo."""
    def reemplazar(m: re.Match) -> str:
        prefijo = m.group(1)
        linea_completa = m.group(0)
        if "`" in linea_completa:
            return f"{prefijo}`{codigo_anon}`"
        return f"{prefijo}{codigo_anon}"

    return REGEX_LINEA_AUTOR.sub(reemplazar, contenido)


def extraer_comentarios_de_linea(contenido: str) -> list[tuple[int, str]]:
    """Extrae tuplas de (número_de_línea, texto_comentario) para comentarios de línea //."""
    comentarios = []
    for m in REGEX_COMENTARIOS_LINEA.finditer(contenido):
        linea_comentario = m.group(4)
        if linea_comentario:
            num_linea = contenido.count("\n", 0, m.start()) + 1
            comentarios.append((num_linea, linea_comentario))
    return comentarios


def recolectar_usuarios(base_dir: Path) -> list[str]:
    """Encuentra todos los nombres de usuario únicos basados en directorios TPn-<usuario>."""
    usuarios = set()
    for ruta in base_dir.rglob("*"):
        if ruta.is_dir():
            m = PATRON_ENTREGA.match(ruta.name)
            if m:
                u = m.group(1)
                if u != "submissions":
                    usuarios.add(u)
    # Ordenar por longitud descendente para evitar colisiones en prefijos
    return sorted(usuarios, key=lambda s: (-len(s), s))


def recopilar_comentarios_de_linea_corpus(
    base_dir: Path,
    archivo_salida: Path,
) -> int:
    """Busca en todos los archivos C/C++ de base_dir y escribe los comentarios numerados."""
    archivos = sorted(p for p in base_dir.rglob("*") if p.is_file() and p.suffix in {".c", ".h", ".cpp", ".hpp"})
    total = 0
    lineas_salida = []

    for archivo in archivos:
        try:
            contenido = archivo.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            continue

        hallados = extraer_comentarios_de_linea(contenido)
        for num_linea, comentario in hallados:
            total += 1
            rel_path = archivo.relative_to(base_dir)
            lineas_salida.append(f"{total:05d}: {rel_path}:{num_linea}: {comentario}\n")

    archivo_salida.parent.mkdir(parents=True, exist_ok=True)
    archivo_salida.write_text("".join(lineas_salida), encoding="utf-8")
    print(f"Recopilados {total} comentarios de línea en {archivo_salida}")
    return total


def procesar_archivos_y_directorios(
    base_dir: Path,
    mapeo_usuarios: dict[str, str],
    dry_run: bool = False,
) -> None:
    # 1. Modificar contenido de archivos
    todos_los_archivos = [p for p in base_dir.rglob("*") if p.is_file()]
    print(f"Procesando contenido de {len(todos_los_archivos)} archivos...")

    patron_reemplazo = re.compile(
        "|".join(re.escape(u) for u in mapeo_usuarios.keys())
    ) if mapeo_usuarios else None

    modificados_contenido = 0
    for archivo in todos_los_archivos:
        # Evitar binarios o git pack files
        if ".git" in archivo.parts:
            # En git procesamos archivos de texto si es necesario, pero evitamos objects/pack
            if "objects" in archivo.parts:
                continue

        try:
            contenido = archivo.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            # Archivo binario o codificación distinta
            continue

        nuevo_contenido = contenido

        # Determinar el usuario correspondiente según el directorio contenedor
        codigo_anon = None
        for parte in reversed(archivo.parent.parts):
            m = PATRON_ENTREGA.match(parte)
            if m and m.group(1) != "submissions":
                usuario_orig = m.group(1)
                codigo_anon = mapeo_usuarios.get(usuario_orig, usuario_orig)
                break

        # Reemplazar líneas de autoría si aplica
        if codigo_anon:
            nuevo_contenido = reemplazar_lineas_autor(nuevo_contenido, codigo_anon)

        # Remover comentarios no de documentación en archivos C/C++
        if archivo.suffix in {".c", ".h", ".cpp", ".hpp"}:
            nuevo_contenido = remover_comentarios_no_doc(nuevo_contenido)

        # Reemplazar usuarios
        if patron_reemplazo:
            nuevo_contenido = patron_reemplazo.sub(
                lambda m: mapeo_usuarios[m.group(0)], nuevo_contenido
            )

        if nuevo_contenido != contenido:
            modificados_contenido += 1
            if not dry_run:
                archivo.write_text(nuevo_contenido, encoding="utf-8")

    print(f"Archivos cuyo contenido fue modificado: {modificados_contenido}")

    # 2. Renombrar archivos individuales cuyos nombres contengan un usuario
    archivos_a_renombrar = []
    for archivo in sorted(base_dir.rglob("*")):
        if archivo.is_file():
            nuevo_nombre = archivo.name
            if patron_reemplazo:
                nuevo_nombre = patron_reemplazo.sub(lambda m: mapeo_usuarios[m.group(0)], nuevo_nombre)
            if nuevo_nombre != archivo.name:
                archivos_a_renombrar.append((archivo, archivo.parent / nuevo_nombre))

    print(f"Renombrando {len(archivos_a_renombrar)} archivos...")
    for origen, destino in archivos_a_renombrar:
        if not dry_run:
            origen.rename(destino)

    # 3. Renombrar directorios (de más profundo a menos profundo)
    directorios_a_renombrar = []
    for directorio in sorted(base_dir.rglob("*"), reverse=True):
        if directorio.is_dir():
            nuevo_nombre = directorio.name
            if patron_reemplazo:
                nuevo_nombre = patron_reemplazo.sub(lambda m: mapeo_usuarios[m.group(0)], nuevo_nombre)
            if nuevo_nombre != directorio.name:
                directorios_a_renombrar.append((directorio, directorio.parent / nuevo_nombre))

    print(f"Renombrando {len(directorios_a_renombrar)} directorios...")
    for origen, destino in directorios_a_renombrar:
        if not dry_run:
            origen.rename(destino)


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("directorio", nargs="?", default=RAIZ / "casos", type=Path)
    parser.add_argument("--dry-run", action="store_true", help="Solo reporta los cambios sin aplicarlos.")
    parser.add_argument(
        "--recopilar-lineas",
        type=Path,
        metavar="ARCHIVO",
        help="Recopila y numera todos los comentarios de línea (//) en el archivo indicado.",
    )
    args = parser.parse_args(argv)

    base_dir = args.directorio.resolve()
    if not base_dir.is_dir():
        print(f"Error: {base_dir} no es un directorio válido.", file=sys.stderr)
        return 1

    if args.recopilar_lineas:
        recopilar_comentarios_de_linea_corpus(base_dir, args.recopilar_lineas.resolve())

    usuarios = recolectar_usuarios(base_dir)
    print(f"Usuarios detectados ({len(usuarios)}):")
    mapeo_usuarios = {}
    for idx, u in enumerate(sorted(usuarios), 1):
        anon = f"anon_{idx:03d}"
        mapeo_usuarios[u] = anon

    # Reordenar diccionario por longitud de clave descendente para el regex
    mapeo_ordenado = {u: mapeo_usuarios[u] for u in sorted(usuarios, key=lambda s: (-len(s), s))}

    for u, a in sorted(mapeo_usuarios.items()):
        print(f"  {u} -> {a}")

    procesar_archivos_y_directorios(base_dir, mapeo_ordenado, dry_run=args.dry_run)
    print("Anonimización finalizada con éxito.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
