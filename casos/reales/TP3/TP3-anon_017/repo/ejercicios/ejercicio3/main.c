/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <stdio.h>
#include "recorrido.h"

int main(void)
{
    printf("Ejercicio 3: Copia e Inversion con Punteros\n");

    
    int arreglo_origen[] = {10, 20, 30, 40, 50};
    size_t capacidad_origen = sizeof(arreglo_origen) / sizeof(arreglo_origen[0]);

    int arreglo_destino[5] = {0, 0, 0, 0, 0}; 
    size_t capacidad_destino = sizeof(arreglo_destino) / sizeof(arreglo_destino[0]);


    printf("Destino antes de copiar: ");
    for(size_t i = 0; i < capacidad_destino; i++)
    {
        printf("%d ", arreglo_destino[i]);
    }
    printf("\n");

    bool estado_copia = copiar_arreglo(arreglo_origen, capacidad_origen, arreglo_destino, capacidad_destino);

    if(estado_copia == true)
    {
        printf("Destino despues de copiar: ");
        for(size_t i = 0; i < capacidad_destino; i++)
        {
            printf("%d ", arreglo_destino[i]);
        }
        printf("\n");
    }

    int arreglo_invertir[] = {1, 2, 3, 4, 5};
    size_t total_elementos = sizeof(arreglo_invertir) / sizeof(arreglo_invertir[0]);

    printf("Antes de invertir: ");
    for(size_t i = 0; i < total_elementos; i++)
    {
        printf("%d ", arreglo_invertir[i]);
    }
    printf("\n");

    bool estado_inversion = invertir_arreglo(arreglo_invertir, total_elementos);

    if(estado_inversion == true)
    {
        printf("Despues de invertir: ");
        for(size_t i = 0; i < total_elementos; i++)
        {
            printf("%d ", arreglo_invertir[i]);
        }
    }

    return 0;
}
