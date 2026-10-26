/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "mergesort.h"

void ordenar_mergesort(int *arreglo, size_t n);

TEST(prueba_mergesort_completo)
{
    SUBCASE("Arreglo impar desordenado");
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    ordenar_mergesort(arr, 7);
    ASSERT_INT_EQ(3, arr[0]);
    ASSERT_INT_EQ(9, arr[1]);
    ASSERT_INT_EQ(10, arr[2]);
    ASSERT_INT_EQ(27, arr[3]);
    ASSERT_INT_EQ(38, arr[4]);
    ASSERT_INT_EQ(43, arr[5]);
    ASSERT_INT_EQ(82, arr[6]);

    SUBCASE("Arreglo ya ordenado");
    int ordenado[] = {1, 2, 3, 4, 5};
    ordenar_mergesort(ordenado, 5);
    ASSERT_INT_EQ(1, ordenado[0]);
    ASSERT_INT_EQ(5, ordenado[4]);

    SUBCASE("Arreglo invertido");
    int invertido[] = {5, 4, 3, 2, 1};
    ordenar_mergesort(invertido, 5);
    ASSERT_INT_EQ(1, invertido[0]);
    ASSERT_INT_EQ(2, invertido[1]);
    ASSERT_INT_EQ(3, invertido[2]);
    ASSERT_INT_EQ(4, invertido[3]);
    ASSERT_INT_EQ(5, invertido[4]);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2", conteo_args, argumentos);
    RUN_TEST(prueba_mergesort_completo);
    return TEST_REPORT();
}
