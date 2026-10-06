/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");
    int arreglo[] = {5, 2, 8, 1, 4};
    size_t cantidad = sizeof(arreglo) / sizeof(*arreglo);
    printf("Antes: ");

    for (int *p = arreglo; p < arreglo + cantidad; p++)
    {
        printf("%d ", *p);
    }

    printf("\n");

    bool ordenado = ordenar_seleccion_punteros(arreglo, cantidad);
    if (ordenado)
    {
        printf("Ordenado: ");

        for (int *p = arreglo; p < arreglo + cantidad; p++)
        {
            printf("%d ", *p);
        }

        printf("\n");
    }
    else
    {
        printf("No se pudo ordenar el arreglo.\n");
    }
    return 0;
}
