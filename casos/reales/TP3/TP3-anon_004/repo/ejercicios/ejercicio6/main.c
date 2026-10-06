/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

static void mostrar_lista(const int *arreglo, size_t cantidad)
{
    const int *actual = arreglo;
    const int *limite = arreglo + cantidad;

    while (actual < limite)
    {
        printf("%d ", *actual);
        actual++;
    }
    printf("\n");
}

int main(void)
{
    int lista[8] = {64, 25, 12, 22, 11, -5, 0, 33};

    printf("--- Ejercicio 6: Selection Sort con Punteros ---\n\n");
    printf("Arreglo antes de ordenar: ");
    mostrar_lista(lista, 8);

    ordenar_seleccion_punteros(lista, 8);

    printf("Arreglo ordenado in-place: ");
    mostrar_lista(lista, 8);

    return 0;
}
