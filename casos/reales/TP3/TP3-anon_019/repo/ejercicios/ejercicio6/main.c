/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por seleccion con punteros\n");

    int datos[] = {64, 25, 12, 22, 11};
    size_t cantidad = 5;
    int *fin = datos + cantidad;

    printf("Arreglo original: ");
    for (int *p = datos; p < fin; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");

    if (ordenar_seleccion_punteros(datos, cantidad))
    {
        printf("Arreglo ordenado: ");
        for (int *p = datos; p < fin; p++)
        {
            printf("%d ", *p);
        }
        printf("\n");
    }
    else
    {
        printf("Error al ordenar el arreglo.\n");
    }

    return 0;
}