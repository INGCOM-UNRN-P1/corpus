/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("uno,dos,tres", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_TRUE(cantidad == 3);
    if (tokens != NULL)
    {
        ASSERT_STR_EQ("uno", *tokens);
        ASSERT_STR_EQ("dos", *(tokens + 1));
        ASSERT_STR_EQ("tres", *(tokens + 2));
        liberar_arreglo_cadenas(&tokens, cantidad);
        ASSERT_PTR_NULL(tokens);
    }
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad));
    ASSERT_PTR_NULL(dividir_linea_csv("texto", ',', NULL));
    ASSERT_TRUE(true);
}

TEST(prueba_liberar_arreglo_null)
{
    char **arreglo = NULL;
    liberar_arreglo_cadenas(&arreglo, 0);
    ASSERT_PTR_NULL(arreglo);    
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_liberar_arreglo_null);
    return TEST_REPORT();
}
