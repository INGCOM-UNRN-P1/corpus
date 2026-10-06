/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"
#include<string.h>

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if(origen == NULL || cantidad == 0)
    {
        return NULL;
    }
   
    int *heap_origen = (int *)malloc(cantidad * sizeof(int));
  

    if(heap_origen == NULL)
    {
        return NULL;
    }
    
    memcpy(heap_origen, origen, cantidad * sizeof(int));
    
    return heap_origen;
}




int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    *cantidad_pares = 0;

    if (origen == NULL || cantidad_origen == 0) 
    {
        return NULL;
    }

    size_t contador = 0;
    for (size_t i = 0; i < cantidad_origen; i++) 
    {
        if (origen[i] % 2 == 0) 
        {
            contador++;
        }
    }

    if (contador == 0) 
    {
        return NULL;
    }

    int *resultado = (int *)malloc(contador * sizeof(int));
    
    if (resultado == NULL) 
    {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < cantidad_origen; i++) 
    {
        if (origen[i] % 2 == 0) 
        {
            resultado[j] = origen[i];
            j++;
        }
    }
    *cantidad_pares = contador;
    return resultado;
}
