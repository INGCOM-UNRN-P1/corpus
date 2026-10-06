/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || inicio >= fin)
    {
        return NULL;
    }

    const int *minimo = inicio;
    const int *actual = inicio + 1;

    while (*actual < *minimo)
    {
        if (*actual < *minimo)
        {
            minimo = actual;
        }
        actual++;
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }

    if (cantidad < 2)
    {
        return true;
    }

    int *fin = arreglo + cantidad;
    int *ultimo = fin - 1;
    int *actual = arreglo;

    while (actual < ultimo)
    {
        const int *minimo = buscar_puntero_minimo(actual, fin);
        int *destino = actual + (minimo - actual);

        intercambiar(actual, destino);
        actual++;
    }

    return true;
}
