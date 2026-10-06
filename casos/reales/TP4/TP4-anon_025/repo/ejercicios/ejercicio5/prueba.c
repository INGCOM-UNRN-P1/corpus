/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"
#include <stdlib.h>

TEST(prueba_dividir_linea_csv)
{
    
    SUBCASE("Parseo de texto normal con separadores");
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("manzana,pera,banana", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("manzana", tokens[0]);
    ASSERT_STR_EQ("pera", tokens[1]);
    ASSERT_STR_EQ("banana", tokens[2]);
    liberar_arreglo_cadena(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);
    SUBCASE ("Casos vorde de tokens nulos o vacios");
    size_t n = 0;
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &n));

    char **vacios = dividir_linea_csv("a,,b", ',', &cantidad);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("a", vacios[0]);
    ASSERT_STR_EQ("", vacios[1]);
    ASSERT_STR_EQ("b", vacios[2]);
    liberar_arreglo_cadena(&vacios, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    return TEST_REPORT();
}
