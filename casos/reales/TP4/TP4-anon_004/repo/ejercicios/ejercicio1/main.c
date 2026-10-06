/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "vector.h"
#include "vector_enteros.h"

int main(void)
{
    int numeros[] = {12, 45, -3, 8, 27, 4};

    size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);
    size_t cantidad_pares = 0;
    size_t posicion = 0;

    int *copia = NULL;
    int *pares = NULL;

    copia = clonar_arreglo_enteros(numeros, cantidad);
    pares = filtrar_arreglo_pares(
        numeros,
        cantidad,
        &cantidad_pares
    );

    if (copia == NULL || pares == NULL)
    {
        fprintf(
            stderr,
            "No se pudo reservar memoria para los arreglos.\n"
        );

        liberar_bloque_enteros(&copia);
        liberar_bloque_enteros(&pares);

        return 1;
    }

    printf("=== Ejercicio 1: Arreglos dinamicos ===\n");

    printf("Copia: ");

    for (posicion = 0; posicion < cantidad; posicion++)
    {
        printf("%d ", copia[posicion]);
    }

    printf("\n");

    printf("Pares (%zu): ", cantidad_pares);

    for (posicion = 0; posicion < cantidad_pares; posicion++)
    {
        printf("%d ", pares[posicion]);
    }

    printf("\n");

    copia[0] = 99;

    printf(
        "Original[0]: %d; copia[0]: %d\n",
        numeros[0],
        copia[0]
    );

    liberar_bloque_enteros(&copia);
    liberar_bloque_enteros(&pares);

    return 0;
}
