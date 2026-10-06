"""Tests de los scripts del corpus."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))

import anonimizar  # noqa: E402
import correr  # noqa: E402
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
