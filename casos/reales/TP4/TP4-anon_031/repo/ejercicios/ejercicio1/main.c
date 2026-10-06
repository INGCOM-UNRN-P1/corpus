/**
 * @file main.c
 * @brief Demostración del Ejercicio 1.
 */

#include <stdio.h>
#include "vector_enteros.h"

int main(void)
{
    int datos[] = {3, 8, 11, 14, 20, 25};
    size_t cantidad_datos = sizeof(datos) / sizeof(datos[0]);
    size_t cantidad_pares = 0U;
    int *clon = NULL;
    int *pares = NULL;
    size_t indice = 0U;

    clon = clonar_arreglo_enteros(datos, cantidad_datos);
    pares = filtrar_arreglo_pares(datos, cantidad_datos, &cantidad_pares);

    printf("Ejercicio 1: Vector Dinamico de Enteros\n");

    if (clon != NULL)
    {
        printf("Clon: ");
        for (indice = 0U; indice < cantidad_datos; indice++)
        {
            printf("%d ", clon[indice]);
        }
        printf("\n");
    }

    if (pares != NULL)
    {
        printf("Pares: ");
        for (indice = 0U; indice < cantidad_pares; indice++)
        {
            printf("%d ", pares[indice]);
        }
        printf("\n");
    }

    liberar_bloque_enteros(&clon);
    liberar_bloque_enteros(&pares);

    return 0;
}
