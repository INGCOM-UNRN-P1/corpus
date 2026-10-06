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

TEST(prueba_buscar_puntero_minimo)
{
    SUBCASE("Buscar minimo en arreglo desordenado");
    int arr[] = {10, 5, 8, 2, 9};
    const int *min = buscar_puntero_minimo(arr, arr + 5);
    ASSERT_TRUE(min != NULL);
    ASSERT_INT_EQ(2, *min);

    SUBCASE("Buscar minimo con rango parcial");
    const int *min_parcial = buscar_puntero_minimo(arr + 1, arr + 4); // Rango: {5, 8, 2}
    ASSERT_TRUE(min_parcial != NULL);
    ASSERT_INT_EQ(2, *min_parcial);

    SUBCASE("Buscar minimo con punteros nulos o rango invalido");
    ASSERT_TRUE(buscar_puntero_minimo(NULL, arr + 5) == NULL);
    ASSERT_TRUE(buscar_puntero_minimo(arr + 5, arr) == NULL); // Rango invertido
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Ordenar arreglo desordenado de enteros");
    int arr[] = {64, 25, 12, 22, 11};
    ordenar_seleccion_punteros(arr, 5);
    
    ASSERT_INT_EQ(11, arr[0]);
    ASSERT_INT_EQ(12, arr[1]);
    ASSERT_INT_EQ(22, arr[2]);
    ASSERT_INT_EQ(25, arr[3]);
    ASSERT_INT_EQ(64, arr[4]);

    SUBCASE("Ordenar arreglo ya ordenado y de un solo elemento");
    int ordenado[] = {1, 2, 3, 4};
    ordenar_seleccion_punteros(ordenado, 4);
    ASSERT_INT_EQ(1, ordenado[0]);
    ASSERT_INT_EQ(4, ordenado[3]);

    int unico[] = {42};
    ordenar_seleccion_punteros(unico, 1);
    ASSERT_INT_EQ(42, unico[0]);

    SUBCASE("Ordenar con arreglo nulo o cantidad menor a 2");
    ordenar_seleccion_punteros(NULL, 5); // No debe romper
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6 (Ordenamiento por Selección)", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
