"""Tests de los scripts del corpus."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))

import anonimizar  # noqa: E402
import correr  # noqa: E402


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
