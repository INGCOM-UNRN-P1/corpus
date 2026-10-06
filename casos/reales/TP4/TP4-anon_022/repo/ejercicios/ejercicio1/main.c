/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

int main(void)
{
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");

    int origen[] = {3, 8, 5, 10, 7, 4};
    size_t cantidad = sizeof(origen) / sizeof(origen[0]);

    int *clon = clonar_arreglo_enteros(origen, cantidad);

    if (clon == NULL)
    {
        printf("No se pudo clonar el arreglo.\n");
        return 1;
    }

    printf("Arreglo clonado: ");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d ", clon[i]);
    }
    printf("\n");

    size_t cantidad_pares = 0;
    int *pares = filtrar_arreglo_pares(origen, cantidad, &cantidad_pares);

    if (pares == NULL)
    {
        printf("No se encontraron elementos pares.\n");
        liberar_bloque_enteros(&clon);
        return 1;
    }

    printf("Elementos pares: ");
    for (size_t i = 0; i < cantidad_pares; i++)
    {
        printf("%d ", pares[i]);
    }
    printf("\n");

    liberar_bloque_enteros(&clon);
    liberar_bloque_enteros(&pares);

    return 0;
}