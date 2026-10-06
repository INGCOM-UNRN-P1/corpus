/**
 * @file vector_enteros.c
 * @brief Implementacion de clonacion y filtrado dinamico de enteros (sin structs).
 */

#include "vector_enteros.h"
#include <stdint.h>
#include <stdlib.h>

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if (origen == NULL || cantidad == 0)
    {
        return NULL;
    }

    if (cantidad > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    int *clon = malloc(cantidad * sizeof(*clon));
    if (clon == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        *(clon + i) = *(origen + i);
    }

    return clon;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    if (cantidad_pares != NULL)
    {
        *cantidad_pares = 0;
    }

    if (origen == NULL || cantidad_origen == 0 || cantidad_pares == NULL)
    {
        return NULL;
    }

    size_t contador_pares = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (*(origen + i) % 2 == 0)
        {
            contador_pares++;
        }
    }

    if (contador_pares == 0)
    {
        return NULL;
    }

    if (contador_pares > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    int *pares = malloc(contador_pares * sizeof(*pares));
    if (pares == NULL)
    {
        return NULL;
    }

    size_t pos = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (*(origen + i) % 2 == 0)
        {
            *(pares + pos) = *(origen + i);
            pos++;
        }
    }

    *cantidad_pares = contador_pares;
    return pares;
}
