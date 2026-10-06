/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(test_clonar_cadena_valida)
{
    const char *texto = "Programacion C11";
    char *clon = clonar_cadena(texto);

    ASSERT_TRUE(clon != NULL);
    ASSERT_TRUE(strcmp(clon, texto) == 0);
    ASSERT_TRUE(clon != texto);

    free(clon);
    clon = NULL;
}

TEST(test_clonar_cadena_vacia)
{
    const char *vacia = "";
    char *clon = clonar_cadena(vacia);

    ASSERT_TRUE(clon != NULL);
    ASSERT_TRUE(strcmp(clon, "") == 0);

    free(clon);
    clon = NULL;
}

TEST(test_clonar_cadena_null)
{
    char *clon = clonar_cadena(NULL);
    ASSERT_TRUE(clon == NULL);
}

TEST(test_unir_cadenas_validas)
{
    const char *str1 = "Hola, ";
    const char *str2 = "Mundo!";
    char *resultado = unir_cadenas_dinamicas(str1, str2);

    ASSERT_TRUE(resultado != NULL);
    ASSERT_TRUE(strcmp(resultado, "Hola, Mundo!") == 0);

    free(resultado);
    resultado = NULL;
}

TEST(test_unir_cadenas_con_vacia)
{
    const char *str1 = "SoloTexto";
    const char *str2 = "";
    char *resultado = unir_cadenas_dinamicas(str1, str2);

    ASSERT_TRUE(resultado != NULL);
    ASSERT_TRUE(strcmp(resultado, "SoloTexto") == 0);

    free(resultado);
    resultado = NULL;
}

TEST(test_unir_cadenas_entradas_null)
{
    char *res1 = unir_cadenas_dinamicas(NULL, "Texto");
    char *res2 = unir_cadenas_dinamicas("Texto", NULL);
    char *res3 = unir_cadenas_dinamicas(NULL, NULL);

    ASSERT_TRUE(res1 == NULL);
    ASSERT_TRUE(res2 == NULL);
    ASSERT_TRUE(res3 == NULL);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(test_clonar_cadena_valida);
    RUN_TEST(test_clonar_cadena_vacia);
    RUN_TEST(test_clonar_cadena_null);
    RUN_TEST(test_unir_cadenas_validas);
    RUN_TEST(test_unir_cadenas_con_vacia);
    RUN_TEST(test_unir_cadenas_entradas_null);
    return TEST_REPORT();
}