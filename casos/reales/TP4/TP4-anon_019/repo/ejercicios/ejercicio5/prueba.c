/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    SUBCASE("Parseo CSV normal");
    {
        size_t cant = 0;
        char **tokens = dividir_linea_csv("manzana,pera,uva", ',', &cant);
        ASSERT_PTR_NOT_NULL(tokens);
        ASSERT_INT_EQ(3, (int)cant);
        ASSERT_STR_EQ("manzana", tokens[0]);
        ASSERT_STR_EQ("pera", tokens[1]);
        ASSERT_STR_EQ("uva", tokens[2]);
        
        liberar_arreglo_cadenas(&tokens, cant);
        ASSERT_PTR_NULL(tokens);
    }

    SUBCASE("Parseo CSV con campos vacios");
    {
        size_t cant = 0;
        char **tokens = dividir_linea_csv("uno,,tres,", ',', &cant);
        ASSERT_PTR_NOT_NULL(tokens);
        ASSERT_INT_EQ(4, (int)cant);
        ASSERT_STR_EQ("uno", tokens[0]);
        ASSERT_STR_EQ("", tokens[1]);
        ASSERT_STR_EQ("tres", tokens[2]);
        ASSERT_STR_EQ("", tokens[3]);
        
        liberar_arreglo_cadenas(&tokens, cant);
    }

    SUBCASE("Entradas nulas o invalidas");
    {
        size_t cant = 5;
        ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cant));
        ASSERT_INT_EQ(0, (int)cant);
        
        ASSERT_PTR_NULL(dividir_linea_csv("test", ',', NULL));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    return TEST_REPORT();
}