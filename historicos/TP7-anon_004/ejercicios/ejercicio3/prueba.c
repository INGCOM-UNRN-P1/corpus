/**
 * @file prueba.c
 * @brief Pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include "p1_test.h"
#include "transposicion.h"

TEST(prueba_ejercicio3_pendiente)
{
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio3_pendiente);
    return TEST_REPORT();
}
