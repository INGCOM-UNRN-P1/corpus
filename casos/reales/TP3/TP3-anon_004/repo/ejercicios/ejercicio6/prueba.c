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
#include "p1_arrays.h"

TEST(prueba_buscar_puntero_minimo)
{
    int lista[5] = {30, 10, 50, -5, 20};

    SUBCASE("Minimo en rango completo");
    int *minimo = buscar_puntero_minimo(lista, lista + 5);
    ASSERT_PTR_EQ(&lista[3], minimo);
    ASSERT_INT_EQ(-5, *minimo);

    SUBCASE("Minimo en subrango");
    minimo = buscar_puntero_minimo(lista, lista + 3);
    ASSERT_PTR_EQ(&lista[1], minimo);
    ASSERT_INT_EQ(10, *minimo);

    SUBCASE("Rango invalido o nulo");
    ASSERT_PTR_NULL(buscar_puntero_minimo(NULL, lista + 3));
    ASSERT_PTR_NULL(buscar_puntero_minimo(lista, NULL));
    ASSERT_PTR_NULL(buscar_puntero_minimo(lista + 3, lista + 1));
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Arreglo desordenado mixto");
    int datos[6] = {12, -4, 0, 7, -15, 3};
    int esperado[6] = {-15, -4, 0, 3, 7, 12};
    ordenar_seleccion_punteros(datos, 6);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 6);

    SUBCASE("Arreglo ya ordenado");
    int ordenados[4] = {1, 2, 3, 4};
    int esperado_ord[4] = {1, 2, 3, 4};
    ordenar_seleccion_punteros(ordenados, 4);
    ASSERT_ARRAY_INT_EQ(esperado_ord, ordenados, 4);

    SUBCASE("Casos de borde: arreglo nulo o unitario");
    int unico[1] = {99};
    ordenar_seleccion_punteros(unico, 1);
    ASSERT_INT_EQ(99, unico[0]);
    ordenar_seleccion_punteros(NULL, 5);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
