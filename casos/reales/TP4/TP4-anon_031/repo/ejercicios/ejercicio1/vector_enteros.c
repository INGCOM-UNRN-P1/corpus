/**
 * @file vector_enteros.c
 * @brief Clonación y filtrado dinámico de enteros.
 */

#include <stdint.h>
#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    int *clon = NULL;
    size_t indice = 0U;

    if ((origen != NULL) && (cantidad > 0U) &&
        (cantidad <= SIZE_MAX / sizeof(int)))
    {
        clon = malloc(cantidad * sizeof(int));
    }

    if (clon != NULL)
    {
        for (indice = 0U; indice < cantidad; indice++)
        {
            clon[indice] = origen[indice];
        }
    }

    return clon;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    int *pares = NULL;
    size_t cantidad_encontrada = 0U;
    size_t indice = 0U;
    size_t indice_pares = 0U;

    if (cantidad_pares != NULL)
    {
        *cantidad_pares = 0U;
    }

    if ((origen != NULL) && (cantidad_origen > 0U) && (cantidad_pares != NULL))
    {
        for (indice = 0U; indice < cantidad_origen; indice++)
        {
            if ((origen[indice] % 2) == 0)
            {
                cantidad_encontrada++;
            }
        }

        if ((cantidad_encontrada > 0U) &&
            (cantidad_encontrada <= SIZE_MAX / sizeof(int)))
        {
            pares = malloc(cantidad_encontrada * sizeof(int));
        }
    }

    if (pares != NULL)
    {
        for (indice = 0U; indice < cantidad_origen; indice++)
        {
            if ((origen[indice] % 2) == 0)
            {
                pares[indice_pares] = origen[indice];
                indice_pares++;
            }
        }
        *cantidad_pares = cantidad_encontrada;
    }

    return pares;
}

int *clonar_bloque(const int *origen, size_t cantidad)
{
    return clonar_arreglo_enteros(origen, cantidad);
}

int *filtrar_bloque_positivos(const int *origen, size_t cantidad_origen,
                              size_t *cantidad_positivos)
{
    int *positivos = NULL;
    size_t cantidad_encontrada = 0U;
    size_t indice = 0U;
    size_t indice_positivos = 0U;

    if (cantidad_positivos != NULL)
    {
        *cantidad_positivos = 0U;
    }

    if ((origen != NULL) && (cantidad_origen > 0U) && (cantidad_positivos != NULL))
    {
        for (indice = 0U; indice < cantidad_origen; indice++)
        {
            if (origen[indice] > 0)
            {
                cantidad_encontrada++;
            }
        }

        if ((cantidad_encontrada > 0U) &&
            (cantidad_encontrada <= SIZE_MAX / sizeof(int)))
        {
            positivos = malloc(cantidad_encontrada * sizeof(int));
        }
    }

    if (positivos != NULL)
    {
        for (indice = 0U; indice < cantidad_origen; indice++)
        {
            if (origen[indice] > 0)
            {
                positivos[indice_positivos] = origen[indice];
                indice_positivos++;
            }
        }
        *cantidad_positivos = cantidad_encontrada;
    }

    return positivos;
}
