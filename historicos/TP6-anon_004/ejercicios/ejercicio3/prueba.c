/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el TDA Conjunto (p1_test).
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar el contrato de conjunto.h.
 */

#include <stdio.h>
#include <stdbool.h>
#include "p1_test.h"
#include "conjunto.h"

TEST(prueba_ejercicio3_pendiente)
{
    
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3 (TDA Conjunto)", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio3_pendiente);
    return TEST_REPORT();
}
