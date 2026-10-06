/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    const int *ptr = buscar_primero(arr, 5, 30);

    if (ptr != NULL) {
        long pos = distancia_punteros(arr, ptr);
        printf("Encontrado %d en el indice: %ld\n", *ptr, pos);
    }

    return 0;
}