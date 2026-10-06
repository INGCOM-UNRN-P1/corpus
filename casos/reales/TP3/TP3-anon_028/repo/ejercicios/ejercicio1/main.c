/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");

    int x = 15, y = 5, z = 10;
    printf("Antes: x=%d, y=%d, z=%d\n", x, y, z);

    ordenar_tria(&x, &y, &z);
    printf("Despues de ordenar_tria: x=%d, y=%d, z=%d\n", x, y, z);

    int datos[] = {10, 20, 30, 40};
    long long total = 0;
    if (sumar_acumulado(datos, 4, &total)) {
        printf("Suma acumulada: %lld\n", total);
    }

    return 0;
}
