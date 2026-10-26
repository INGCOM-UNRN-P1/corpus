/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_ejercicio4_pendiente)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio4_pendiente);
    return TEST_REPORT();
}
