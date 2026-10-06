
/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    int *copia = NULL;
    size_t i = 0;

    if (origen == NULL || cantidad == 0)
    {
        return NULL;
    }

    copia = malloc(cantidad * sizeof(int));

    if (copia == NULL)
    {
        return NULL;
    }

    for (i = 0; i < cantidad; i++)
    {
        copia[i] = origen[i];
    }

    return copia;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    int *resultado = NULL;
    size_t cantidad_encontrada = 0;
    size_t i = 0;
    size_t posicion = 0;

    if (cantidad_pares == NULL)
    {
        return NULL;
    }

    *cantidad_pares = 0;

    if (origen == NULL || cantidad_origen == 0)
    {
        return NULL;
    }

    for (i = 0; i < cantidad_origen; i++)
    {
        if (origen[i] % 2 == 0)
        {
            cantidad_encontrada++;
        }
    }

    if (cantidad_encontrada == 0)
    {
        return NULL;
    }

    resultado = malloc(
        cantidad_encontrada * sizeof(int)
    );

    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0; i < cantidad_origen; i++)
    {
        if (origen[i] % 2 == 0)
        {
            resultado[posicion] = origen[i];
            posicion++;
        }
    }

    *cantidad_pares = cantidad_encontrada;

    return resultado;
}
