/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "busqueda.h"
#include "p1_test.h"

TEST(probar_buscar_primero) {
    int arr[] = {10, 20, 30, 20, 50};

    // Encuentra la primera aparicion
    const int *res = buscar_primero(arr, 5, 20);
    ASSERT_PTR_EQ(res, &arr[1]);

    // No lo encuentra
    ASSERT_PTR_EQ(buscar_primero(arr, 5, 99), NULL);

    // Arreglo NULL
    ASSERT_PTR_EQ(buscar_primero(NULL, 5, 10), NULL);
}

TEST(probar_distancia_punteros) {
    int arr[] = {10, 20, 30, 40};

    // Calculo de distancia valido
    ASSERT_INT_EQ((int)distancia_punteros(arr, &arr[2]), 2);
    ASSERT_INT_EQ((int)distancia_punteros(arr, arr), 0);

    // Casos invalidos / NULL
    ASSERT_INT_EQ((int)distancia_punteros(arr, arr - 1), -1);
    ASSERT_INT_EQ((int)distancia_punteros(NULL, &arr[1]), -1);
    ASSERT_INT_EQ((int)distancia_punteros(arr, NULL), -1);
}

int main(void) {
    RUN_TEST(probar_buscar_primero);
    RUN_TEST(probar_distancia_punteros);

    return 0;
}