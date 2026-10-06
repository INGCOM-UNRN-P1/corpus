
/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadenas.h"
#include "texto_dinamico.h"

TEST(prueba_cadena_recortar_espacios)
{
    char *limpio = NULL;
    char *vacio = NULL;

    SUBCASE("Recorte de espacios iniciales y finales");

    limpio = cadena_recortar_espacios(
        "   hola mundo   "
    );

    ASSERT_PTR_NOT_NULL(limpio);
    ASSERT_STR_EQ("hola mundo", limpio);

    cadena_liberar_segura(&limpio);

    ASSERT_PTR_NULL(limpio);


    SUBCASE("Cadena solo de espacios");

    vacio = cadena_recortar_espacios(
        "     "
    );

    ASSERT_PTR_NULL(vacio);
}


TEST(prueba_cadena_repetir)
{
    char *repetido = NULL;
    char *cero = NULL;

    SUBCASE("Repetir patron");

    repetido = cadena_repetir(
        "abc",
        3
    );

    ASSERT_PTR_NOT_NULL(repetido);
    ASSERT_STR_EQ("abcabcabc", repetido);

    cadena_liberar_segura(&repetido);

    ASSERT_PTR_NULL(repetido);


    SUBCASE("Repetir cero veces");

    cero = cadena_repetir(
        "abc",
        0
    );

    ASSERT_PTR_NOT_NULL(cero);
    ASSERT_STR_EQ("", cero);

    cadena_liberar_segura(&cero);

    ASSERT_PTR_NULL(cero);
}


TEST(prueba_texto_casos_borde)
{
    char original[] = "  a  b\t  ";
    char *resultado = NULL;


    SUBCASE("No recorta tabulaciones ni espacios interiores");

    resultado = cadena_recortar_espacios(
        original
    );

    ASSERT_PTR_NOT_NULL(resultado);

    ASSERT_STR_EQ(
        "a  b\t",
        resultado
    );

    ASSERT_STR_EQ(
        "  a  b\t  ",
        original
    );

    cadena_liberar_segura(&resultado);

    ASSERT_PTR_NULL(resultado);


    SUBCASE("Cadena vacia");

    resultado = cadena_recortar_espacios(
        ""
    );

    ASSERT_PTR_NULL(resultado);


    SUBCASE("Entradas invalidas");

    ASSERT_PTR_NULL(
        cadena_recortar_espacios(NULL)
    );

    ASSERT_PTR_NULL(
        cadena_repetir(NULL, 1)
    );


    SUBCASE("Repetir cadena vacia");

    resultado = cadena_repetir(
        "",
        5
    );

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("", resultado);

    cadena_liberar_segura(&resultado);

    ASSERT_PTR_NULL(resultado);
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 2",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_cadena_recortar_espacios);
    RUN_TEST(prueba_cadena_repetir);
    RUN_TEST(prueba_texto_casos_borde);

    return TEST_REPORT();
}
