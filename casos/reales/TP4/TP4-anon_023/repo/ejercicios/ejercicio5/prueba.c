/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(test_dividir_linea_csv_estandar)
{
    const char *linea = "Juan,Perez,30,Bariloche";
    size_t cant = 0;
    char **tokens = dividir_linea_csv(linea, ',', &cant);

    ASSERT_TRUE(tokens != NULL);
    ASSERT_TRUE(cant == 4);
    ASSERT_TRUE(strcmp(*(tokens + 0), "Juan") == 0);
    ASSERT_TRUE(strcmp(*(tokens + 1), "Perez") == 0);
    ASSERT_TRUE(strcmp(*(tokens + 2), "30") == 0);
    ASSERT_TRUE(strcmp(*(tokens + 3), "Bariloche") == 0);

    liberar_arreglo_cadenas(&tokens, cant);
    ASSERT_TRUE(tokens == NULL);
}

TEST(test_dividir_linea_csv_un_solo_token)
{
    const char *linea = "SoloUnElemento";
    size_t cant = 0;
    char **tokens = dividir_linea_csv(linea, ',', &cant);

    ASSERT_TRUE(tokens != NULL);
    ASSERT_TRUE(cant == 1);
    ASSERT_TRUE(strcmp(*(tokens + 0), "SoloUnElemento") == 0);

    liberar_arreglo_cadenas(&tokens, cant);
    ASSERT_TRUE(tokens == NULL);
}

TEST(test_dividir_linea_csv_campos_vacios)
{
    const char *linea = "a,,c";
    size_t cant = 0;
    char **tokens = dividir_linea_csv(linea, ',', &cant);

    ASSERT_TRUE(tokens != NULL);
    ASSERT_TRUE(cant == 3);
    ASSERT_TRUE(strcmp(*(tokens + 0), "a") == 0);
    ASSERT_TRUE(strcmp(*(tokens + 1), "") == 0);
    ASSERT_TRUE(strcmp(*(tokens + 2), "c") == 0);

    liberar_arreglo_cadenas(&tokens, cant);
    ASSERT_TRUE(tokens == NULL);
}

TEST(test_dividir_linea_csv_parametros_nulos)
{
    size_t cant = 0;
    char **tokens1 = dividir_linea_csv(NULL, ',', &cant);
    char **tokens2 = dividir_linea_csv("a,b", ',', NULL);

    ASSERT_TRUE(tokens1 == NULL);
    ASSERT_TRUE(tokens2 == NULL);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(test_dividir_linea_csv_estandar);
    RUN_TEST(test_dividir_linea_csv_un_solo_token);
    RUN_TEST(test_dividir_linea_csv_campos_vacios);
    RUN_TEST(test_dividir_linea_csv_parametros_nulos);
    return TEST_REPORT();
}
