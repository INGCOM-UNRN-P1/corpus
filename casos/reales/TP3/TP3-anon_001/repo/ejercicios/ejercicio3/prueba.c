/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "recorrido.h"
#include "p1_test.h"

TEST(probar_copiar_arreglo) {
    int orig[] = {1, 2, 3, 4};
    int dest[4] = {0};
    int esperado[] = {1, 2, 3, 4};

    // Caso exitoso
    ASSERT_TRUE(copiar_arreglo(orig, dest, 4));
    ASSERT_ARRAY_INT_EQ(dest, esperado, 4);

    // Casos con NULL
    ASSERT_FALSE(copiar_arreglo(NULL, dest, 4));
    ASSERT_FALSE(copiar_arreglo(orig, NULL, 4));
}

TEST(probar_invertir_arreglo) {
    int arr[] = {1, 2, 3, 4, 5};
    int esperado[] = {5, 4, 3, 2, 1};

    // Caso exitoso
    ASSERT_TRUE(invertir_arreglo(arr, 5));
    ASSERT_ARRAY_INT_EQ(arr, esperado, 5);

    // Caso con NULL
    ASSERT_FALSE(invertir_arreglo(NULL, 5));
}

int main(void) {
    RUN_TEST(probar_copiar_arreglo);
    RUN_TEST(probar_invertir_arreglo);

    return 0;
}