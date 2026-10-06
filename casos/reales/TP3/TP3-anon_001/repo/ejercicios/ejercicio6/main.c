/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void) {
    int arr[] = {34, 12, 5, 89, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    ordenar_seleccion_punteros(arr, n);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}