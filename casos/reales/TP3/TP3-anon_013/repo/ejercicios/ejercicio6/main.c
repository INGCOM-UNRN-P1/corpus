/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "ordenamiento.h"

int main(void)
{
    printf("Ejercicio 6: Ordenamiento por selección con punteros\n");

    //---------------------------------------------------------------------------------------------------------
    printf("\n===== BUSCAR PUNTERO MINIMO =====\n");

    int arreglo[] = {9,9,9,9,1,9,9,9,9,9};
    size_t cantidad = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("ARREGLO: ");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");

    int *inicio = arreglo;
    int *fin = arreglo + cantidad - 1;
    const int *ptr_min = buscar_puntero_minimo(inicio, fin);

    printf("PTR ORIGEN: %p\n"
        "PTR FIN: %p\n"
        "PTR MINIMO: %p\n"
        "ELEMENTO MINIMO: %d\n"
        , inicio, fin, ptr_min, *ptr_min);

    //---------------------------------------------------------------------------------------------------------
    printf("\n===== ORDENAR SELECCION PUNTEROS =====\n");
    
    int arreglo2[] = {9,5,4,7,6,2,1,4,5,4,8,8,7,3,1,2,1,5};
    size_t cantidad2 = sizeof(arreglo2) / sizeof(arreglo2[0]);

    printf("ARREGLO ORIGINAL: ");
    for (size_t i = 0; i < cantidad2; i++)
    {
        printf("%d, ", arreglo2[i]);
    }
    printf("\n");

    ordenar_seleccion_punteros(arreglo2, cantidad2);

    printf("ARREGLO ORDENADO: ");
    for (size_t i = 0; i < cantidad2; i++)
    {
        printf("%d, ", arreglo2[i]);
    }
    printf("\n");

    return 0;
}
