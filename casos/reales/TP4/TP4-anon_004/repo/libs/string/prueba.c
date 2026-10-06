/**
 * @file prueba.c
 * @brief Pruebas unitarias de libstring con p1_test.
 */

#include <stdio.h>

#include "p1_test.h"
#include "cadenas.h"


TEST(prueba_cadena_duplicar_segura)
{
    char *dup = NULL;

    SUBCASE("Duplicacion de cadena valida");

    dup = cadena_duplicar_segura("Programacion 1", 30);

    ASSERT_PTR_NOT_NULL(dup);
    ASSERT_STR_EQ("Programacion 1", dup);

    cadena_liberar_segura(&dup);

    ASSERT_PTR_NULL(dup);


    SUBCASE("Cadena vacia");

    dup = cadena_duplicar_segura("", 10);

    ASSERT_PTR_NOT_NULL(dup);
    ASSERT_STR_EQ("", dup);

    cadena_liberar_segura(&dup);

    ASSERT_PTR_NULL(dup);


    SUBCASE("Cadena nula o capacidad cero");

    ASSERT_PTR_NULL(
        cadena_duplicar_segura(NULL, 10)
    );

    ASSERT_PTR_NULL(
        cadena_duplicar_segura("hola", 0)
    );
}


TEST(prueba_cadena_unir_dinamica)
{
    char *unida = NULL;

    SUBCASE("Union exitosa en heap");

    unida = cadena_unir_dinamica(
        "Hola ",
        10,
        "Mundo",
        10
    );

    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola Mundo", unida);

    cadena_liberar_segura(&unida);

    ASSERT_PTR_NULL(unida);


    SUBCASE("Union de cadenas vacias");

    unida = cadena_unir_dinamica(
        "",
        1,
        "",
        1
    );

    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("", unida);

    cadena_liberar_segura(&unida);


    SUBCASE("Primera cadena vacia");

    unida = cadena_unir_dinamica(
        "",
        1,
        "Mundo",
        10
    );

    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Mundo", unida);

    cadena_liberar_segura(&unida);


    SUBCASE("Segunda cadena vacia");

    unida = cadena_unir_dinamica(
        "Hola",
        10,
        "",
        1
    );

    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola", unida);

    cadena_liberar_segura(&unida);


    SUBCASE("Argumentos invalidos");

    ASSERT_PTR_NULL(
        cadena_unir_dinamica(
            NULL,
            10,
            "test",
            10
        )
    );

    ASSERT_PTR_NULL(
        cadena_unir_dinamica(
            "test",
            10,
            NULL,
            10
        )
    );

    ASSERT_PTR_NULL(
        cadena_unir_dinamica(
            "test",
            0,
            "hola",
            10
        )
    );

    ASSERT_PTR_NULL(
        cadena_unir_dinamica(
            "test",
            10,
            "hola",
            0
        )
    );
}


TEST(prueba_cadena_liberar_segura)
{
    char *cadena = NULL;

    SUBCASE("Liberacion de cadena valida");

    cadena = cadena_duplicar_segura(
        "Programacion",
        20
    );

    ASSERT_PTR_NOT_NULL(cadena);

    cadena_liberar_segura(&cadena);

    ASSERT_PTR_NULL(cadena);


    SUBCASE("Liberacion segura de puntero nulo");

    cadena_liberar_segura(&cadena);

    ASSERT_PTR_NULL(cadena);

    cadena_liberar_segura(NULL);
}


TEST(prueba_cadena_subcadena_dinamica)
{
    char *sub = NULL;

    SUBCASE("Extraccion de subcadena valida");

    sub = cadena_subcadena_dinamica(
        "Universidad",
        20,
        3,
        4
    );

    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("vers", sub);

    cadena_liberar_segura(&sub);


    SUBCASE("Cantidad mayor al texto restante");

    sub = cadena_subcadena_dinamica(
        "Universidad",
        20,
        7,
        20
    );

    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("idad", sub);

    cadena_liberar_segura(&sub);


    SUBCASE("Inicio fuera de rango");

    sub = cadena_subcadena_dinamica(
        "UNRN",
        10,
        10,
        3
    );

    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("", sub);

    cadena_liberar_segura(&sub);


    SUBCASE("Cantidad cero");

    sub = cadena_subcadena_dinamica(
        "UNRN",
        10,
        1,
        0
    );

    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("", sub);

    cadena_liberar_segura(&sub);


    SUBCASE("Argumentos invalidos");

    ASSERT_PTR_NULL(
        cadena_subcadena_dinamica(
            NULL,
            10,
            0,
            3
        )
    );

    ASSERT_PTR_NULL(
        cadena_subcadena_dinamica(
            "hola",
            0,
            0,
            3
        )
    );
}


TEST(prueba_cadena_invertir_dinamica)
{
    char *inv = NULL;

    SUBCASE("Inversion de cadena valida");

    inv = cadena_invertir_dinamica(
        "hola",
        10
    );

    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("aloh", inv);

    cadena_liberar_segura(&inv);


    SUBCASE("Cadena de un caracter");

    inv = cadena_invertir_dinamica(
        "A",
        2
    );

    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("A", inv);

    cadena_liberar_segura(&inv);


    SUBCASE("Cadena vacia");

    inv = cadena_invertir_dinamica(
        "",
        1
    );

    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("", inv);

    cadena_liberar_segura(&inv);


    SUBCASE("Argumentos invalidos");

    ASSERT_PTR_NULL(
        cadena_invertir_dinamica(
            NULL,
            10
        )
    );

    ASSERT_PTR_NULL(
        cadena_invertir_dinamica(
            "hola",
            0
        )
    );
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: libstring",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_cadena_duplicar_segura);
    RUN_TEST(prueba_cadena_unir_dinamica);
    RUN_TEST(prueba_cadena_liberar_segura);
    RUN_TEST(prueba_cadena_subcadena_dinamica);
    RUN_TEST(prueba_cadena_invertir_dinamica);

    return TEST_REPORT();
}