/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

static void mostrar_arreglo(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        printf("%d ", *actual);
        actual++;
    }

    printf("\n");
}

int main(void)
{
    int arreglo[] = {5, 2, 8, 1, 4};
    size_t cantidad = 5;

    printf("Ejercicio 6: Ordenamiento por seleccion con punteros\n");

    printf("Arreglo original: ");
    mostrar_arreglo(arreglo, cantidad);

    ordenar_seleccion_punteros(arreglo, cantidad);

    printf("Arreglo ordenado: ");
    mostrar_arreglo(arreglo, cantidad);

    return 0;
}
