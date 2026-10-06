/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include "vector.h"
#include "vector_enteros.h"
#include <stdio.h>

int main(void)
{
    printf("Ejercicio 1: Vector Dinámico de Enteros\n");
    //______________________________________________________________________________________________________________

    printf("\n===== clonar_arreglo_enteros =====\n");

    int origen[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t cantidad_origen = sizeof(origen) / sizeof(origen[0]);

    printf("ARREGLO ORIGEN: ");
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        printf("%d, ", origen[i]);
    }
    printf("\n");

    int *ptr_heap = clonar_arreglo_enteros(origen, cantidad_origen);

    if (ptr_heap != NULL)
    {
        printf("ARREGLO HEAP: ");
        for (size_t i = 0; i < cantidad_origen; i++)
        {
            printf("%d, ", ptr_heap[i]);
        }
        printf("\n");
        liberar_bloque_enteros(&ptr_heap);
        printf("PUNTERO AL HEAP LIBERADO CON liberar_bloque_enteros()\n");
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL\n");
    }

    //______________________________________________________________________________________________________________

    printf("\n===== filtrar_arreglo_pares =====\n");

    printf("ARREGLO ORIGEN: ");
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        printf("%d, ", origen[i]);
    }
    printf("\n");

    size_t cantidad_pares = 0;
    ptr_heap = filtrar_arreglo_pares(origen, cantidad_origen, &cantidad_pares);

    if (ptr_heap != NULL)
    {
        printf("ARREGLO HEAP: ");
        for (size_t i = 0; i < cantidad_pares; i++)
        {
            printf("%d, ", ptr_heap[i]);
        }
        printf("\n");
        liberar_bloque_enteros(&ptr_heap);
        printf("PUNTERO AL HEAP LIBERADO CON liberar_bloque_enteros()\n");
    }
    else
    {
        printf("EL PUNTERO AL HEAP ES NULL, algo malio sal\n");
    }

    return 0;
}
