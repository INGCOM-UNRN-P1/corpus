/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "busqueda.h"

int main(void)
{
    printf("Ejercicio 4: Búsqueda con punteros\n");
    
    //---------------------------------------------------------------------------------------------------------
    printf("\n===== Buscar Primero =====\n");

    int arreglo[] = {1,2,3,4,5,4,3,2,1};
    size_t cantidad_arreglo = sizeof(arreglo)/sizeof(arreglo[0]);

    printf("ARREGLO: ");
    for (size_t i = 0; i < cantidad_arreglo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");

    int valor_buscado = 3;

    const int *ptr_a_valor = buscar_primero(arreglo, cantidad_arreglo, valor_buscado);
    
    if (ptr_a_valor == NULL)
    {
        printf("Valor no encontrado\n");
    }
    else
    {
        printf("Valor buscado: %d\n"
            "Contenido del puntero: %d\n", valor_buscado, *ptr_a_valor);
    }

    //---------------------------------------------------------------------------------------------------------
    printf("\n===== Distancia Punteros =====\n");

    int arreglo2[] = {10,9,8,7,6,5,4,3,2,1,0};
    size_t cantidad_arreglo2 = sizeof(arreglo2)/sizeof(arreglo2[0]);

    printf("ARREGLO: ");
    for (size_t i = 0; i < cantidad_arreglo2; i++)
    {
        printf("%d, ", arreglo2[i]);
    }
    printf("\n");

    int valor_buscado2 = 7;
    const int *ptr_a_valor2 = buscar_primero(arreglo2, cantidad_arreglo2, valor_buscado2);
    long long int indice = distancia_punteros(arreglo2, cantidad_arreglo2, ptr_a_valor2);

    if (ptr_a_valor2 == NULL)
    {
        printf("Valor no encontrado\n");
    }
    else
    {
        printf("Valor buscado: %d\n"
                "Contenido del puntero: %d\n"
                "Indice del elemento: %lld\n"
                , valor_buscado2, *ptr_a_valor2, indice);
    }

    return 0;
}
