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
    SUBCASE("Clonacion correcta");
    char *clon = clonar_cadena("Hola");
    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ("Hola", clon);
    free(clon);

    SUBCASE("Clonacion de cadena vacia");
    clon = clonar_cadena("");
    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ("", clon);
    free(clon);

    SUBCASE("Entrada invalida");
    ASSERT_PTR_NULL(clonar_cadena(NULL));
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Union exitosa");
    char *unida = unir_cadenas_dinamicas("Hola", " Mundo");
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola Mundo", unida);
    free(unida);

    SUBCASE("Union con primera cadena vacia");
    unida = unir_cadenas_dinamicas("", "abc");
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("abc", unida);
    free(unida);

    SUBCASE("Union con segunda cadena vacia");
    unida = unir_cadenas_dinamicas("abc", "");
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("abc", unida);
    free(unida);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "x"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("x", NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}