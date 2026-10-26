/**
 * @file prueba.c
 * @brief Pruebas del Ejercicio 3 a diseñar por el estudiante.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_potencia.h"

TEST(prueba_ejercicio3_placeholder)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio3_placeholder);
    return TEST_REPORT();
}
