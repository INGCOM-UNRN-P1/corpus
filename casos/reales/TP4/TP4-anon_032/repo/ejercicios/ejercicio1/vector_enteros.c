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

    int *bloque = crear_bloque_enteros(cantidad);
    if (bloque == NULL)
    {
        return NULL;
    }
    
    for (size_t i = 0; i < cantidad; i++)
    {
        bloque[i] = origen[i];
    }
    return bloque;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    if (origen == NULL || cantidad_pares == NULL || cantidad_origen == 0)
    {
        return NULL;
    }
    
    *cantidad_pares = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if ((origen[i] % 2) == 0)
        {
            (*cantidad_pares)++;
        }
    }
    if (cantidad_pares == 0)
    {
        return NULL;
    }

    int *bloque = crear_bloque_enteros(*cantidad_pares);
    if (bloque == NULL)
    {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if ((origen[i] % 2) == 0)
        {
            bloque[j] = origen[i];
            j++;
        }
    }

    return bloque;
}