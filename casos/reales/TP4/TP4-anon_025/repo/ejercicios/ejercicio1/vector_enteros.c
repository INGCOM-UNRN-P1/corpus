/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    

    if (origen == NULL || cantidad == 0) 
    {
        return NULL;
    }

    int *clon = (int *)malloc(cantidad * sizeof(int));

    if (clon == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        clon[i] = origen[i];
    }

    return clon;
    
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    

    if (origen == NULL|| cantidad_origen == 0 || cantidad_pares == NULL)
    {
        if (cantidad_pares != NULL)
        {
            *cantidad_pares = 0;
        }
        return NULL;
    }

    size_t contador_pares = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (origen[i] % 2 == 0)
        {
            contador_pares++;
        }
    }
    if (contador_pares == 0)
    {
        *cantidad_pares = 0;
        return NULL;
    }

    int *pares = (int *)malloc(contador_pares * sizeof(int));
    size_t indice_nuevo = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (origen[i] % 2 == 0)
        {
            pares[indice_nuevo] = origen[i];
            indice_nuevo++;
        }
    }
    *cantidad_pares = contador_pares;
    return pares;
}
