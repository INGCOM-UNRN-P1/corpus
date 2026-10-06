/**
 * @file main.c
 * @brief Programa principal interactivo y demostrativo del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    printf("[ ");
    while (actual < fin)
    {
        printf("%d ", *actual);
        actual++;
    }
    printf("]\n");
}

int main(void)
{
    printf("=== Demostracion Ejercicio 3: Copia e Inversion con Punteros ===\n\n");

    int origen[5] = {10, 25, 30, 45, 50};
    int copia[5] = {0};

    printf("1. Arreglo original: ");
    imprimir_arreglo(origen, 5);

    if (copiar_arreglo(copia, origen, 5))
    {
        printf("2. Arreglo copiado con exito: ");
        imprimir_arreglo(copia, 5);
    }

    if (invertir_arreglo(copia, 5))
    {
        printf("3. Arreglo invertido in-place: ");
        imprimir_arreglo(copia, 5);
    }

    return 0;
}
