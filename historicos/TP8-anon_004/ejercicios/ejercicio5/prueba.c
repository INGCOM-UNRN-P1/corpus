/**
 * @file prueba.c
 * @brief Pruebas del Ejercicio 5 a diseñar por el estudiante.
 */

#include <stdio.h>
#include "p1_test.h"
#include "strassen.h"

TEST(prueba_ejercicio5_placeholder)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio5_placeholder);
    return TEST_REPORT();
}
