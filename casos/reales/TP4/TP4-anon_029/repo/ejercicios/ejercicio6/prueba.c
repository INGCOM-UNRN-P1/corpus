/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include "consulta_csv.h"
#include "p1_test.h"
#include <stdio.h>

TEST(prueba_ejercicio6_pendiente)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                          argumentos);
    RUN_TEST(prueba_ejercicio6_pendiente);
    return TEST_REPORT();
}
