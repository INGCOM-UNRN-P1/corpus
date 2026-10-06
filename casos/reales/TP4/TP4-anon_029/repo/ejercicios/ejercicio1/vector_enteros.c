/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros
 *  (sin structs).
 */

#include "vector_enteros.h"
#include <stdlib.h>

/**
 * @brief Descripción de la función clonar_arreglo_enteros.
 *
 * @param origen Descripción del parámetro origen.
 * @param cantidad Descripción del parámetro cantidad.
 * @return Descripción del valor de retorno.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if (origen == NULL || cantidad == 0)
    {
        return NULL;
    }

    int *copia = (int *)calloc(cantidad, sizeof(int));

    if (copia == NULL)
    {
        return NULL;
    }
    int *aux = copia;
    for (size_t indice = 0; indice < cantidad; indice++)
    {
        *aux = *origen;
        aux++;
        origen++;
    }

    return copia;
}

/**
 * @brief Descripción de la función filtrar_arreglo_pares.
 *
 * @param origen Descripción del parámetro origen.
 * @param cantidad_origen Descripción del parámetro cantidad_origen.
 * @param cantidad_pares Descripción del parámetro cantidad_pares.
 * @return Descripción del valor de retorno.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    if (origen == NULL || cantidad_pares == NULL || cantidad_origen == 0)
    {
        return NULL;
    }

    *cantidad_pares = 0;

    for (size_t indice = 0; indice < cantidad_origen; indice++)
    {
        if (*(origen + indice) % 2 == 0)
        {
            (*cantidad_pares)++;
        }
    }

    if (*cantidad_pares == 0)
    {
        return NULL;
    }

    int *pares = (int *)calloc(*cantidad_pares, sizeof(int));

    if (pares == NULL)
    {
        return NULL;
    }

    int indice_par = 0;
    for (size_t indice = 0; indice < cantidad_origen; indice++)
    {
        if (*(origen + indice) % 2 == 0)
        {
            *(pares + indice_par) = *(origen + indice);
            indice_par++;
        }
    }
    return pares;
}
