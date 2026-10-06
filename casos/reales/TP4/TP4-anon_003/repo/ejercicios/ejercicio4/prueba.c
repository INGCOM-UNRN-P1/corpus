/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz)
{
    size_t filas = 3;
    size_t columnas = 4;
    int **matriz = matriz_crear(filas, columnas);
    ASSERT_TRUE(matriz != NULL);
    ASSERT_TRUE(matriz[0] != NULL);
    matriz_destruir(matriz);

}
TEST (prueba_destruccion){
    matriz_destruir(NULL);
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz);
    RUN_TEST (prueba_destruccion);

    return TEST_REPORT();
}
