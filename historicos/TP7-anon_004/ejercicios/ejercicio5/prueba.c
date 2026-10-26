/**
 * @file prueba.c
 * @brief Pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "estadisticas_csv.h"

TEST(prueba_ejercicio5_pendiente)
{
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio5_pendiente);
    return TEST_REPORT();
}
