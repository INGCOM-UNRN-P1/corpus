/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "ordenamiento.h"
#include "p1_test.h"

TEST(probar_buscar_puntero_minimo) {
    int arr[] = {15, 3, 8, 1, 20};

    // Encuentra el puntero al menor elemento en el rango [arr, arr+5)
    const int *min_ptr = buscar_puntero_minimo(arr, arr + 5);
    ASSERT_PTR_EQ(min_ptr, &arr[3]);

    // Rango invalido o NULL
    ASSERT_PTR_EQ(buscar_puntero_minimo(NULL, arr + 5), NULL);
    ASSERT_PTR_EQ(buscar_puntero_minimo(arr + 5, arr), NULL);
}

TEST(probar_ordenar_seleccion_punteros) {
    int arr[] = {42, -5, 10, 0, 3};
    int esperado[] = {-5, 0, 3, 10, 42};

    // Ordenamiento correcto
    ordenar_seleccion_punteros(arr, 5);
    ASSERT_ARRAY_INT_EQ(arr, esperado, 5);

    // Caso invalido (NULL)
    ordenar_seleccion_punteros(NULL, 5);
}

int main(void) {
    RUN_TEST(probar_buscar_puntero_minimo);
    RUN_TEST(probar_ordenar_seleccion_punteros);

    return 0;
}