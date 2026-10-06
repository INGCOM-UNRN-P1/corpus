/**
 * @file prueba.c
 * @brief Pruebas de integracion de Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "operaciones.h"
#include "arreglos.h"

TEST(prueba_calcular_promedio)
{
    int valores[] = {10, 20, 30};

    ASSERT_DOUBLE_EQ(0.0, calcular_promedio(NULL, 0), 0.001);
    ASSERT_DOUBLE_EQ(20.0, calcular_promedio(valores, 3), 0.001);
}

TEST(prueba_contiene_valor)
{
    int valores[] = {10, 20, 30};

    ASSERT_TRUE(contiene_valor(valores, 3, 20));
    ASSERT_FALSE(contiene_valor(valores, 3, 99));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 1",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_calcular_promedio);
    RUN_TEST(prueba_contiene_valor);

    return TEST_REPORT();
}
