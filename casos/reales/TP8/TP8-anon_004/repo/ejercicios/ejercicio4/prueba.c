/**
 * @file prueba.c
 * @brief Pruebas del Ejercicio 4 a diseñar por el estudiante.
 */

#include <stdio.h>
#include "p1_test.h"
#include "laberinto.h"

TEST(prueba_ejercicio4_placeholder)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio4_placeholder);
    return TEST_REPORT();
}
