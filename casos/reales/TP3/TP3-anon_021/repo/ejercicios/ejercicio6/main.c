/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ordenamiento por Selección con Punteros \n");

    int datos[] = {29, 10, 14, 37, 13, 9, 21};
    size_t tam = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo original desordenado:\n[ ");
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d ", datos[i]);
    }
    printf("]\n\n");
    ordenar_seleccion_punteros(datos, tam);

    printf("Arreglo ordenado ascendentemente con Selection Sort:\n[ ");
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d ", datos[i]);
    }
    printf("]\n\n");

    return 0;
}