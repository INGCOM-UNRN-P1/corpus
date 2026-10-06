/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin
 * structs).
 */

#include "vector_enteros.h"
#include <stdlib.h>

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if (origen == NULL || cantidad == 0)
    {
        return NULL;
    }

    int *ptr_heap = calloc(cantidad, sizeof(int));
    if (ptr_heap == NULL)
    {
        return NULL;
    }
    memcpy(ptr_heap, origen, sizeof(int) * cantidad);
    return ptr_heap;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    if (origen == NULL || cantidad_origen == 0 || cantidad_pares == NULL)
    {
        return NULL;
    }
    *cantidad_pares = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (origen[i] % 2 == 0)
        {
            (*cantidad_pares)++;
        }
    }

    if (*cantidad_pares == 0)
    {
        return NULL;
    }
    else
    {
        int *ptr_pares = malloc(*cantidad_pares * sizeof(int));
        if (ptr_pares == NULL)
        {
            return NULL;
        }

        size_t j = 0;
        for (size_t i = 0; i < cantidad_origen; i++)
        {
            if (origen[i] % 2 == 0)
            {
                ptr_pares[j] = origen[i];
                j++;
            }
        }
        return ptr_pares;
    }
}
