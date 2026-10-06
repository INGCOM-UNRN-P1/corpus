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
 
    int *clon = crear_bloque_enteros(cantidad);
    if (clon == NULL) 
    {
        return NULL;
    }
    for (size_t i = 0; i < cantidad; ++i) 
    {
        clon[i] = origen[i];
    }
    return clon;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    if (cantidad_pares == NULL) 
    {
        return NULL;
    }
    *cantidad_pares = 0;
    if (origen == NULL || cantidad_origen == 0) 
    {
        return NULL;
    }
 
    size_t pares = 0;
    for (size_t i = 0; i < cantidad_origen; ++i) 
    {
        if (origen[i] % 2 == 0) 
        {
            ++pares;
        }
    }
    if (pares == 0) 
    {
        return NULL;
    }
 
    int *filtrados = crear_bloque_enteros(pares);
    if (filtrados == NULL) 
    {
        return NULL;
    }
    size_t siguiente = 0;
    for (size_t i = 0; i < cantidad_origen; ++i) 
    {
        if (origen[i] % 2 == 0) 
        {
            filtrados[siguiente] = origen[i];
            ++siguiente;
        }
    }
    *cantidad_pares = pares;
    return filtrados;
}
