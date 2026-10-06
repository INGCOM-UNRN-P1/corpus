/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv_valida)
{
    
    const char *linea = "Juan,Perez,30,Programador";
    size_t cant = 0;

    char **tokens = dividir_linea_csv(linea, ',', &cant);

    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(4, (int)cant);

    ASSERT_STR_EQ("Juan", tokens[0]);
    ASSERT_STR_EQ("Perez", tokens[1]);
    ASSERT_STR_EQ("30", tokens[2]);
    ASSERT_STR_EQ("Programador", tokens[3]);

    liberar_arreglo_cadenas(&tokens, cant);
    ASSERT_PTR_NULL(tokens);
}

TEST(prueba_dividir_linea_csv_delimitador_personalizado)
{
    const char *linea = "id;nombre;precio";
    size_t cant = 0;

    char **tokens = dividir_linea_csv(linea, ';', &cant);

    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(3, (int)cant);

    ASSERT_STR_EQ("id", tokens[0]);
    ASSERT_STR_EQ("nombre", tokens[1]);
    ASSERT_STR_EQ("precio", tokens[2]);

    liberar_arreglo_cadenas(&tokens, cant);
    ASSERT_PTR_NULL(tokens);
}

TEST(prueba_dividir_linea_csv_parametros_null)
{
    size_t cant = 0;
    char **tokens1 = dividir_linea_csv(NULL, ',', &cant);
    ASSERT_PTR_NULL(tokens1);

    char **tokens2 = dividir_linea_csv("a,b,c", ',', NULL);
    ASSERT_PTR_NULL(tokens2);
}

TEST(prueba_liberar_arreglo_null_seguro)
{
    char **arreglo = NULL;
    liberar_arreglo_cadenas(&arreglo, 0);
    ASSERT_PTR_NULL(arreglo);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv_valida);
    RUN_TEST(prueba_dividir_linea_csv_delimitador_personalizado);
    RUN_TEST(prueba_dividir_linea_csv_parametros_null);
    RUN_TEST(prueba_liberar_arreglo_null_seguro);
    return TEST_REPORT();
}
