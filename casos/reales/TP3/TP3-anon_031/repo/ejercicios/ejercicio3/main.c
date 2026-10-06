/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

static void mostrar_arreglo(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        printf("%d", *actual);

        if (actual + 1 < fin)
        {
            printf(" ");
        }

        actual++;
    }

    printf("\n");
}

int main(void)
{
    int origen[] = {10, 20, 30, 40, 50};
    int destino[] = {0, 0, 0, 0, 0};
    size_t cantidad = 5;

    printf("Ejercicio 3: Recorrido e inversion con punteros\n");

    printf("\nArreglo origen:\n");
    mostrar_arreglo(origen, cantidad);

    if (copiar_arreglo(origen, destino, cantidad))
    {
        printf("Copia del arreglo:\n");
        mostrar_arreglo(destino, cantidad);
    }
    else
    {
        printf("No se pudo copiar el arreglo.\n");
    }

    if (invertir_arreglo(destino, cantidad))
    {
        printf("Arreglo invertido:\n");
        mostrar_arreglo(destino, cantidad);
    }
    else
    {
        printf("No se pudo invertir el arreglo.\n");
    }

    return 0;
}
