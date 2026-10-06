#include <stdint.h>
#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if (origen == NULL || cantidad == 0)
    {
        return NULL;
    }

    int *clon = NULL;
    if (cantidad > SIZE_MAX / sizeof(*clon))
    {
        return NULL;
    }

    clon = malloc(cantidad * sizeof(*clon));
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
    if (origen == NULL || cantidad_origen == 0 || cantidad_pares == NULL)
    {
        if (cantidad_pares != NULL)
        {
            *cantidad_pares = 0;
        }
        return NULL;
    }

    size_t pares = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (*(origen + i) % 2 == 0)
        {
            pares++;
        }
    }

    *cantidad_pares = pares;

    if (pares == 0)
    {
        return NULL;
    }

    int *bloque_pares = NULL;
    if (pares > SIZE_MAX / sizeof(*bloque_pares))
    {
        *cantidad_pares = 0;
        return NULL;
    }

    bloque_pares = malloc(pares * sizeof(*bloque_pares));
    if (bloque_pares == NULL)
    {
        *cantidad_pares = 0;
        return NULL;
    }

    size_t indice = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (*(origen + i) % 2 == 0)
        {
            *(bloque_pares + indice) = *(origen + i);
            indice++;
        }
    }

    return bloque_pares;
}