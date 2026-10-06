/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include "vector.h"
#include "vector_enteros.h"
#include <stdio.h>

/**
 * @brief Descripción de la función ejecutar_ejercio_1.
 */
void ejecutar_ejercio_1(void)
{
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");
    size_t cantidad = 5;
    size_t cantidad_pares = 0;
    int *arreglo = crear_bloque_enteros(cantidad);
    for (size_t indice = 0; indice < cantidad; ++indice)
    {
        arreglo[indice] = (int)(indice + 1);
    }

    int *clon = clonar_arreglo_enteros(arreglo, cantidad);
    // imprimo el clon mediante arigmetica de punteros
    if (clon != NULL)
    {
        printf("Arreglo clonado: ");
        for (size_t indice = 0; indice < cantidad; indice++)
        {
            printf("%d", *(clon + indice));
        }

        printf("Memoria Stack (original): %p | Memoria Heap (clon): %p.\n",
               (void *)arreglo, (void *)clon);

        liberar_bloque_enteros(&clon);
    }
    else
    {
        printf("Error: no se pudo asignar memoria a clon.\n");
    }

    int *pares = filtrar_arreglo_pares(arreglo, cantidad, &cantidad_pares);
    // imprimo la cantidad de parees
    if (pares != NULL)
    {
        printf("Arreglo pares: ");
        for (size_t indice = 0; indice < cantidad_pares; indice++)
        {
            printf("%d", *(pares + indice));
        }

        printf("Memoria Stack (original): %p | Memoria Heap (clon): %p.\n",
               (void *)arreglo, (void *)pares);

        liberar_bloque_enteros(&pares);
    }
    else
    {
        printf("Error: no se pudo asignar memoria a pares.\n");
    }
}
int main(void)
{
    ejecutar_ejercio_1();
    return 0;
}
