/**
 * @file punteros.c
 * @brief Implementacion de la biblioteca libpunteros.
 *
 * Trabajo Practico 3 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#include "punteros.h"
#include <stddef.h>

void intercambiar(int *primer, int *segundo)
{
    if (primer == NULL || segundo == NULL || primer == segundo)
    {
        return;
    }

    int temporal = *primer;
    *primer = *segundo;
    *segundo = temporal;
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    if (arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL)
    {
        return false;
    }

    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    int min_val = *actual;
    int max_val = *actual;
    actual++;

    while (actual < fin)
    {
        if (*actual < min_val)
        {
            min_val = *actual;
        }
        if (*actual > max_val)
        {
            max_val = *actual;
        }
        actual++;
    }

    *minimo = min_val;
    *maximo = max_val;

    return true;
}
