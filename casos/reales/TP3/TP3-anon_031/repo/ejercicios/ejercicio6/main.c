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
    int datos[] = {64, 25, 12, 22, 11};
    size_t cantidad = 5;

    printf("Ejercicio 6: Ordenamiento por seleccion con punteros\n");

    printf("Antes de ordenar:\n");
    mostrar_arreglo(datos, cantidad);

    if (ordenar_seleccion_punteros(datos, cantidad))
    {
        printf("Despues de ordenar:\n");
        mostrar_arreglo(datos, cantidad);
    }
    else
    {
        printf("No se pudo ordenar el arreglo.\n");
    }

    return 0;
}
