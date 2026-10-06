/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

#define CANTIDAD_ELEMENTOS 8

static void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
    const int *fin = arreglo + cantidad;

    printf("[");

    for (const int *actual = arreglo; actual < fin; actual++)
    {
        if (actual == arreglo)
        {
            printf("%d", *actual);
        }
        else
        {
            printf(", %d", *actual);
        }
    }

    printf("]\n");
}

int main(void)
{
    int numeros[CANTIDAD_ELEMENTOS] = {42, -7, 15, 0, 23, -3, 8, 4};
    const int *minimo = NULL;

    printf("Ejercicio 6: Ordenamiento por selección con punteros\n\n");

    printf("Arreglo original:  ");
    imprimir_arreglo(numeros, CANTIDAD_ELEMENTOS);

    minimo = buscar_puntero_minimo(numeros,
                                   numeros + CANTIDAD_ELEMENTOS);

    if (minimo != NULL)
    {
        printf("Mínimo detectado:  %d\n", *minimo);
    }

    ordenar_seleccion_punteros(numeros, CANTIDAD_ELEMENTOS);

    printf("Arreglo ordenado:  ");
    imprimir_arreglo(numeros, CANTIDAD_ELEMENTOS);

    return 0;
}