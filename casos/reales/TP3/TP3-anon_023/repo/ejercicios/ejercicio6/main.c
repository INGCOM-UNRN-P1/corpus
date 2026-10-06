/**
 * @file main.c
 * @brief Programa principal interactivo y demostrativo del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

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
    printf("=== Demostracion Ejercicio 6: Ordenamiento por Seleccion con Punteros ===\n\n");

    int datos[] = {89, 45, 68, 90, 29, 34, 17};
    size_t cantidad = sizeof(datos) / sizeof(*(datos + 0));

    printf("Arreglo desordenado inicial: ");
    imprimir_arreglo(datos, cantidad);

    if (ordenar_seleccion_punteros(datos, cantidad))
    {
        printf("Arreglo ordenado resultante: ");
        imprimir_arreglo(datos, cantidad);
    }

    return 0;
}
