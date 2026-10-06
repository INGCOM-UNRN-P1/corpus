/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    int *copia = NULL;
    size_t i = 0U;

    if (origen == NULL || cantidad == 0U)
    {
        return NULL;
    }

    copia = crear_bloque_enteros(cantidad);
    if (copia == NULL)
    {
        return NULL;
    }

    for (i = 0U; i < cantidad; ++i)
    {
        copia[i] = origen[i];
    }

    return copia;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                          size_t *cantidad_pares)
{
    int *pares = NULL;
    size_t cantidad_valida = 0U;
    size_t i = 0U;
    size_t j = 0U;

    if (origen == NULL || cantidad_origen == 0U || cantidad_pares == NULL)
    {
        return NULL;
    }

    for (i = 0U; i < cantidad_origen; ++i)
    {
        if (origen[i] % 2 == 0)
        {
            ++cantidad_valida;
        }
    }

    if (cantidad_valida == 0U)
    {
        *cantidad_pares = 0U;
        return NULL;
    }

    pares = crear_bloque_enteros(cantidad_valida);
    if (pares == NULL)
    {
        *cantidad_pares = 0U;
        return NULL;
    }

    for (i = 0U; i < cantidad_origen; ++i)
    {
        if (origen[i] % 2 == 0)
        {
            pares[j] = origen[i];
            ++j;
        }
    }

    *cantidad_pares = cantidad_valida;
    return pares;
}
