/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_ejercicio6_pendiente)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio6_pendiente);
    return TEST_REPORT();
}
