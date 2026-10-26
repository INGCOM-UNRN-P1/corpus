/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "quicksort.h"

void ordenar_quicksort(int *arreglo, size_t n);

TEST(prueba_quicksort_completo)
{
    SUBCASE("Arreglo desordenado común");
    int arr[] = {34, 7, 23, 32, 5, 62};
    ordenar_quicksort(arr, 6);
    ASSERT_INT_EQ(5, arr[0]);
    ASSERT_INT_EQ(7, arr[1]);
    ASSERT_INT_EQ(23, arr[2]);
    ASSERT_INT_EQ(32, arr[3]);
    ASSERT_INT_EQ(34, arr[4]);
    ASSERT_INT_EQ(62, arr[5]);

    SUBCASE("Arreglo con elementos repetidos y negativos");
    int arr2[] = {-3, 10, -3, 0, 5, -10};
    ordenar_quicksort(arr2, 6);
    ASSERT_INT_EQ(-10, arr2[0]);
    ASSERT_INT_EQ(-3, arr2[1]);
    ASSERT_INT_EQ(-3, arr2[2]);
    ASSERT_INT_EQ(0, arr2[3]);
    ASSERT_INT_EQ(5, arr2[4]);
    ASSERT_INT_EQ(10, arr2[5]);

    SUBCASE("Casos de borde: 0 o 1 elemento");
    ordenar_quicksort(NULL, 0);
    int unitario[] = {42};
    ordenar_quicksort(unitario, 1);
    ASSERT_INT_EQ(42, unitario[0]);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1", conteo_args, argumentos);
    RUN_TEST(prueba_quicksort_completo);
    return TEST_REPORT();
}
