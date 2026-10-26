/**
 * @file prueba.c
 * @brief Pruebas de caja negra para el TDA Secuencia (p1_test).
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar el contrato de secuencia.h independientemente de la implementación.
 */

#include <stdio.h>
#include <stdbool.h>
#include "p1_test.h"
#include "secuencia.h"

TEST(prueba_ejercicio4_pendiente)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4 (TDA Secuencia)", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio4_pendiente);
    return TEST_REPORT();
}
