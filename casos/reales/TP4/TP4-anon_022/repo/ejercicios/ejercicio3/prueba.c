/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_cadena)
{
    SUBCASE("Clonar una cadena normal");

    char origen[] = "Hola mundo";
    char *copia = clonar_cadena(origen);

    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("Hola mundo", copia);
    ASSERT_PTR_NE(origen, copia);

    cadena_liberar_segura(&copia);


    SUBCASE("Clonar una cadena vacía");

    copia = clonar_cadena("");

    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("", copia);

    cadena_liberar_segura(&copia);


    SUBCASE("Clonar una cadena NULL");

    copia = clonar_cadena(NULL);

    ASSERT_PTR_NULL(copia);


    SUBCASE("La copia es independiente de la cadena original");

    char cadena[] = "Hola";
    copia = clonar_cadena(cadena);

    ASSERT_PTR_NOT_NULL(copia);

    cadena[0] = 'X';

    ASSERT_STR_EQ("Hola", copia);

    cadena_liberar_segura(&copia);
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Concatenar dos cadenas");

    char *resultado = unir_cadenas_dinamicas("Hola", " mundo");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("Hola mundo", resultado);

    cadena_liberar_segura(&resultado);


    SUBCASE("Primera cadena vacía");

    resultado = unir_cadenas_dinamicas("", "Hola");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("Hola", resultado);

    cadena_liberar_segura(&resultado);


    SUBCASE("Segunda cadena vacía");

    resultado = unir_cadenas_dinamicas("Hola", "");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("Hola", resultado);

    cadena_liberar_segura(&resultado);


    SUBCASE("Ambas cadenas vacías");

    resultado = unir_cadenas_dinamicas("", "");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("", resultado);

    cadena_liberar_segura(&resultado);


    SUBCASE("Primera cadena NULL");

    resultado = unir_cadenas_dinamicas(NULL, "Hola");

    ASSERT_PTR_NULL(resultado);


    SUBCASE("Segunda cadena NULL");

    resultado = unir_cadenas_dinamicas("Hola", NULL);

    ASSERT_PTR_NULL(resultado);


    SUBCASE("Ambas cadenas NULL");

    resultado = unir_cadenas_dinamicas(NULL, NULL);

    ASSERT_PTR_NULL(resultado);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 3",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);

    return TEST_REPORT();
}