"""Tests de los scripts del corpus."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))

import anonimizar  # noqa: E402
import correr  # noqa: E402
import descargar_repos  # noqa: E402
import empaquetar_git  # noqa: E402
import limpiar_repos  # noqa: E402


def test_firma_de_salidas_anidadas():
    salida = {"schema_version": "1.0.0", "ok": False, "archivos": [
        {"archivo": "main.c", "violaciones": [
            {"codigo": "0x0006h", "linea": 15, "mensaje": "Línea larga"},
            {"codigo": "0x000Ah", "linea": 3, "mensaje": "Espacio"},
        ]}]}
    assert correr.firma(salida) == {"veredicto": False, "hallazgos": [["0x000Ah", 3], ["0x0006h", 15]]}


def test_firma_con_flag_de_gcc_y_sin_hallazgos():
    salida = {"exito": True, "diagnosticos": [{"flag": "-Wunused-variable", "linea": 6, "archivo": "/abs/main.c"}]}
    assert correr.firma(salida) == {"veredicto": True, "hallazgos": [["-Wunused-variable", 6]]}
    assert correr.firma({"passed": True, "results": [{"handled_gracefully": True}]}) == {
        "veredicto": True, "hallazgos": []}


def test_los_casos_tienen_esperados():
    for caso in correr.casos([]):
        herramientas = correr.tomllib.loads((caso / "caso.toml").read_text(encoding="utf-8"))["herramientas"]
        for nombre in herramientas:
            assert (caso / "esperado" / f"{nombre}.json").exists(), f"{caso.name}/{nombre}"


def test_detecta_datos_personales():
    texto = ("/* Autor: Juana Pérez - legajo 12345\n"
             " * juana.perez@gmail.com, DNI 30.123.456\n"
             " * https://github.com/juanaperez/tp1 */\n")
    tipos = {nombre for nombre, _, _ in anonimizar.revisar(texto)}
    assert tipos == {"autoría", "legajo", "correo", "DNI", "usuario de GitHub"}


def test_corrige_y_queda_limpio():
    texto = "// autor: Juan Gómez <jgomez@unrn.edu.ar>\nint x; // leg. 4567\n"
    corregido = anonimizar.corregir(texto)
    assert anonimizar.revisar(corregido) == []
    assert "int x;" in corregido and "Juan" not in corregido


def test_los_casos_del_corpus_no_tienen_datos_personales():
    assert anonimizar.main([]) == 0


def test_limpiar_repos_desconecta_remotes(tmp_path):
    import subprocess

    repo_dir = tmp_path / "caso_test" / "repo"
    repo_dir.mkdir(parents=True)
    subprocess.run(["git", "init", str(repo_dir)], check=True, capture_output=True)
    subprocess.run(
        ["git", "-C", str(repo_dir), "remote", "add", "origin", "https://example.com/repo.git"],
        check=True,
        capture_output=True,
    )

    # Verificar existencia inicial del remote
    res = subprocess.run(["git", "-C", str(repo_dir), "remote"], check=True, capture_output=True, text=True)
    assert "origin" in res.stdout

    # Limpiar repos desconecta el remote
    assert limpiar_repos.limpiar_repos(tmp_path) == 0

    res_post = subprocess.run(["git", "-C", str(repo_dir), "remote"], check=True, capture_output=True, text=True)
    assert res_post.stdout.strip() == ""

    # Segunda corrida es idempotente si ya no hay remote
    assert limpiar_repos.limpiar_repos(tmp_path) == 0


def test_empaquetar_y_restaurar_bundle(tmp_path):
    import subprocess

    caso_dir = tmp_path / "TP1-anon_001"
    repo_dir = caso_dir / "repo"
    repo_dir.mkdir(parents=True)
    subprocess.run(["git", "init", "-b", "main", str(repo_dir)], check=True, capture_output=True)
    subprocess.run(["git", "config", "user.name", "Tester"], cwd=repo_dir, check=True)
    subprocess.run(["git", "config", "user.email", "tester@example.com"], cwd=repo_dir, check=True)
    (repo_dir / "codigo.c").write_text("int main() { return 0; }")
    subprocess.run(["git", "-C", str(repo_dir), "add", "."], check=True, capture_output=True)
    subprocess.run(["git", "-C", str(repo_dir), "commit", "-m", "commit 1"], check=True, capture_output=True)

    # Agregar cambios pendientes sin commitear en el worktree
    (repo_dir / "codigo.c").write_text("int main() { return 1; }")

    # 1. Empaquetar
    assert empaquetar_git.ejecutar("empaquetar", tmp_path) == 0
    assert (caso_dir / "repo.bundle").exists()
    assert not (repo_dir / ".git").exists()
    assert (repo_dir / "codigo.c").read_text() == "int main() { return 1; }"

    # 2. Restaurar
    assert empaquetar_git.ejecutar("restaurar", tmp_path) == 0
    assert (repo_dir / ".git").exists()
    # Verifica que el historial se recuperó y no tiene remotes
    res_log = subprocess.run(["git", "-C", str(repo_dir), "log", "--oneline"], capture_output=True, text=True, check=True)
    assert "anonimizar entrega" in res_log.stdout
    assert "commit 1" in res_log.stdout
    res_remotes = subprocess.run(["git", "-C", str(repo_dir), "remote"], capture_output=True, text=True, check=True)
    assert res_remotes.stdout.strip() == ""

    # 3. Limpiar .git
    assert empaquetar_git.ejecutar("limpiar", tmp_path) == 0
    assert not (repo_dir / ".git").exists()
    assert (caso_dir / "repo.bundle").exists()


def test_filtrar_repos_por_prefijo():
    repos = [
        {"name": "tp1-algo", "url": "https://example.com/tp1", "sshUrl": "git@example.com:tp1.git"},
        {"name": "TP2-otro", "url": "https://example.com/TP2", "sshUrl": "git@example.com:TP2.git"},
        {"name": "Tp3-caso", "url": "https://example.com/Tp3", "sshUrl": "git@example.com:Tp3.git"},
        {"name": "p1-2026-tp6-estudiante", "url": "https://example.com/p1", "sshUrl": "git@example.com:p1.git"},
        {"name": "corpus", "url": "https://example.com/corpus", "sshUrl": "git@example.com:corpus.git"},
    ]
    filtrados = descargar_repos.filtrar_repos_por_prefijo(repos, "tp")
    nombres = [r["name"] for r in filtrados]
    assert nombres == ["tp1-algo", "TP2-otro", "Tp3-caso"]


def test_descargar_repos_procesar_y_actualizar(tmp_path):
    import subprocess

    # Crear un repositorio de origen local simulando el remoto
    origen_dir = tmp_path / "remoto_tp"
    origen_dir.mkdir()
    subprocess.run(["git", "init", "-b", "main", str(origen_dir)], check=True, capture_output=True)
    subprocess.run(["git", "config", "user.name", "Tester"], cwd=origen_dir, check=True)
    subprocess.run(["git", "config", "user.email", "tester@example.com"], cwd=origen_dir, check=True)
    (origen_dir / "README.md").write_text("# Hola")
    subprocess.run(["git", "-C", str(origen_dir), "add", "."], check=True, capture_output=True)
    subprocess.run(["git", "-C", str(origen_dir), "commit", "-m", "init"], check=True, capture_output=True)

    destino_dir = tmp_path / "descargas"
    repo_info = {
        "name": "TP-remoto",
        "url": str(origen_dir),
        "sshUrl": str(origen_dir),
    }

    # 1. Clonar
    ok, msg = descargar_repos.procesar_repo(repo_info, destino_dir, protocolo="https")
    assert ok
    assert "Clonado" in msg
    clon_dir = destino_dir / "TP-remoto"
    assert (clon_dir / "README.md").read_text() == "# Hola"

    # 2. Sin actualizar: omitir
    ok, msg = descargar_repos.procesar_repo(repo_info, destino_dir, protocolo="https", actualizar=False)
    assert ok
    assert "Omitido" in msg

    # 3. Con cambios en origen y actualizar=True: git pull
    (origen_dir / "README.md").write_text("# Hola actualizado")
    subprocess.run(["git", "-C", str(origen_dir), "commit", "-am", "update"], check=True, capture_output=True)

    ok, msg = descargar_repos.procesar_repo(repo_info, destino_dir, protocolo="https", actualizar=True)
    assert ok
    assert "Actualizado" in msg
    assert (clon_dir / "README.md").read_text() == "# Hola actualizado"


def test_corpus_ingest_anon_purga_git_comentarios_cadenas_y_binarios(tmp_path):
    import subprocess
    import ingest

    origen = tmp_path / "TP5-juanperez"
    origen.mkdir()
    subprocess.run(["git", "init", "-b", "main", str(origen)], check=True, capture_output=True)
    subprocess.run(["git", "config", "user.name", "Juan Perez"], cwd=origen, check=True)
    subprocess.run(["git", "config", "user.email", "juan.perez@alumno.unrn.edu.ar"], cwd=origen, check=True)

    # Banner con nombre/legajo, comentario de línea con DNI, cadena con dato personal y docblock Doxygen real
    (origen / "main.c").write_text(
        "/**********************************************\n"
        " * Autor: Juan Perez - Legajo: UNRN-99887\n"
        " * Correo: juan.perez@alumno.unrn.edu.ar\n"
        " **********************************************/\n"
        "/**\n"
        " * @brief Suma dos enteros.\n"
        " * @author Juan Perez\n"
        " * @param a Primer operando.\n"
        " * @return Suma.\n"
        " */\n"
        "// Alumno: Juan Perez DNI 42.111.222\n"
        '#include <stdio.h>\n'
        'int main(void) {\n'
        '    printf("Alumno: Juan Perez - Legajo: 99887\\n");\n'
        '    return 0;\n'
        '}\n',
        encoding="utf-8",
    )
    # Artefacto binario ELF simulado y carpeta de entregas anidada
    (origen / "ejecutable_elf").write_bytes(b"\x7fELF\x02\x01\x01\x00")
    anidada = origen / "TP1-submissions"
    anidada.mkdir()
    (anidada / "extra.c").write_text("int x;\n", encoding="utf-8")

    subprocess.run(["git", "-C", str(origen), "add", "-A"], check=True, capture_output=True)
    subprocess.run(
        ["git", "-C", str(origen), "commit", "-m", "Entrega de juan.perez@alumno.unrn.edu.ar"],
        check=True,
        capture_output=True,
    )

    destino_reales = tmp_path / "reales"
    rc = ingest.main([
        "ingest",
        "--anon",
        str(origen),
        "--tp",
        "TP5",
        "--id",
        "anon_099",
        "--destino",
        str(destino_reales),
    ])
    assert rc == 0

    entrega = destino_reales / "TP5" / "TP5-anon_099"
    assert (entrega / "repo.bundle").is_file()
    assert not (entrega / "repo" / "ejecutable_elf").exists()
    assert not (entrega / "repo" / "TP1-submissions").exists()

    codigo = (entrega / "repo" / "main.c").read_text(encoding="utf-8")
    assert "Juan Perez" not in codigo
    assert "99887" not in codigo
    assert "42.111.222" not in codigo
    assert "@brief Suma dos enteros." in codigo
    assert anonimizar.revisar(codigo) == []


def test_casos_reales_tp1_a_tp8_conectados_y_concordancia():
    nombres = {c.name for c in correr.casos([])}
    for esperado in (
        "TP1-anon_001",
        "TP2-anon_001",
        "TP3-anon_003",
        "TP4-anon_003",
        "TP5-anon_001",
        "TP6-anon_002",
        "TP6-anon_004",
        "TP7-anon_005",
        "TP8-anon_003",
    ):
        assert esperado in nombres, f"Falta conectar {esperado} en casos/"
    assert correr.verificar_concordancia_catalogos() == []

