/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"
 
TEST(prueba_dividir_linea_csv)
{
    SUBCASE("Division de una linea normal");
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("Ana,23,Bariloche", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("Ana", tokens[0]);
    ASSERT_STR_EQ("23", tokens[1]);
    ASSERT_STR_EQ("Bariloche", tokens[2]);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);
 
    SUBCASE("Campo vacio y linea nula");
    tokens = dividir_linea_csv("a,,b", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("", tokens[1]);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad));
}
 
TEST(prueba_liberar_arreglo_cadenas)
{
    SUBCASE("Liberacion segura con punteros nulos");
    char **nulo = NULL;
    liberar_arreglo_cadenas(&nulo, 0);
    liberar_arreglo_cadenas(NULL, 0);
    ASSERT_PTR_NULL(nulo);
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_liberar_arreglo_cadenas);
    return TEST_REPORT();
}
