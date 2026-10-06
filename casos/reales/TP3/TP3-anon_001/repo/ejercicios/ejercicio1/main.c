/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void) {
    // 1. Prueba de ordenar_par
    int x = 10, y = 3;
    printf("--- Pruebas de Ordenamientp ---\n");
    printf("Par antes : %d, %d\n", x, y);
    ordenar_par(&x, &y);
    printf("Par despues: %d, %d\n\n", x, y);

    // 2. Prueba de ordenar_tria
    int a = 9, b = 2, c = 5;
    printf("Tria antes : %d, %d, %d\n", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf("Tria despues: %d, %d, %d\n\n", a, b, c);

    // 3. Prueba de sumar_acumulado
    int arr[] = {10, 20, 30, 40};
    long long res = 0;
    
    printf("--- Prueba de Suma ---\n");
    if (sumar_acumulado(arr, 4, &res)) {
        printf("Suma total del arreglo: %lld\n", res);
    } else {
        printf("Error: Punteros nulos.\n");
    }

    return 0;
}