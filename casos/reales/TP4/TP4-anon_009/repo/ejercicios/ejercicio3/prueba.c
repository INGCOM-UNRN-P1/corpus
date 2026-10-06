/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_cadena)
{
    SUBCASE("clonar cadena valida");
    const char *original = "Algoritmos";
    char *clon = clonar_cadena(original);
    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ(original, clon);
    free(clon);
    SUBCASE("entrada NULL");
    char *clon_null = clonar_cadena(NULL);
    ASSERT_PTR_NULL(clon_null);
    SUBCASE("cadena vacia");
    char *clon_vacio = clonar_cadena("");
    ASSERT_PTR_NOT_NULL(clon_vacio);
    ASSERT_STR_EQ("", clon_vacio);
    free(clon_vacio);
    ASSERT_TRUE(true);
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("concatenacion valida");
    char *unida = unir_cadenas_dinamicas("Buenas ", "tardes");
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Buenas tardes", unida);
    free(unida);
    SUBCASE("primera entrada NULL");
    char *null_1 = unir_cadenas_dinamicas(NULL, "Texto");
    ASSERT_PTR_NULL(null_1);
    SUBCASE("segunda entrada NULL");
    char *null_2 = unir_cadenas_dinamicas("Texto", NULL);
    ASSERT_PTR_NULL(null_2);
    SUBCASE("ambas entradas NULL");
    char *null_ambas = unir_cadenas_dinamicas(NULL, NULL);
    ASSERT_PTR_NULL(null_ambas);
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
