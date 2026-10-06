/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || fin <= inicio)
    {
        return NULL;
    }

    const int *minimo = inicio;
    const int *cursor = inicio + 1;

    while (cursor < fin)
    {
        if (*cursor < *minimo)
        {
            minimo = cursor;
        }
        cursor++;
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

    int *inicio = arreglo;
    int *fin = arreglo + cantidad;

    while (inicio < fin)
    {
        const int *minimo = buscar_puntero_minimo(inicio, fin);

        if (minimo == NULL)
        {
            return false;
        }

        if (minimo != inicio)
        {
            intercambiar(inicio, (int *)minimo);
        }

        inicio++;
    }

    return true;
}
