/**
 * @file prueba.c
 * @brief Pruebas de libalgoritmos con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "algoritmos.h"

TEST(prueba_ordenamiento_insercion)
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    ordenar_insercion(arr, 6);
    ASSERT_INT_EQ(1, arr[0]);
    ASSERT_INT_EQ(2, arr[1]);
    ASSERT_INT_EQ(5, arr[2]);
    ASSERT_INT_EQ(5, arr[3]);
    ASSERT_INT_EQ(6, arr[4]);
    ASSERT_INT_EQ(9, arr[5]);
}

TEST(prueba_multiplicacion_matrices_bloque)
{
    
    int a[4] = {1, 2, 3, 4};
    int b[4] = {2, 0, 1, 2};
    int c[4] = {0, 0, 0, 0};

    ASSERT_TRUE(multiplicar_matrices_bloque(a, 2, 2, b, 2, c));
    ASSERT_INT_EQ(4, c[0]);
    ASSERT_INT_EQ(4, c[1]);
    ASSERT_INT_EQ(10, c[2]);
    ASSERT_INT_EQ(8, c[3]);
}

TEST(prueba_busqueda_binaria_recursiva)
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    ASSERT_INT_EQ(0, (int)busqueda_binaria_recursiva(arr, 0, 6, 2));
    ASSERT_INT_EQ(3, (int)busqueda_binaria_recursiva(arr, 0, 6, 8));
    ASSERT_INT_EQ(6, (int)busqueda_binaria_recursiva(arr, 0, 6, 14));
    ASSERT_INT_EQ(-1, (int)busqueda_binaria_recursiva(arr, 0, 6, 7));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libalgoritmos", conteo_args, argumentos);
    RUN_TEST(prueba_ordenamiento_insercion);
    RUN_TEST(prueba_multiplicacion_matrices_bloque);
    RUN_TEST(prueba_busqueda_binaria_recursiva);
    return TEST_REPORT();
}
