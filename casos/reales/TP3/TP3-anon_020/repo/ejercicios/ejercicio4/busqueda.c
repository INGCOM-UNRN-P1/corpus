/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    if (arreglo == NULL)
    {
        return NULL;
    }

    const int *cursor = arreglo;
    const int *fin = arreglo + cantidad;

    while (cursor < fin)
    {
        if (*cursor == valor)
        {
            return cursor;
        }
        cursor++;
    }

    return NULL;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    if (inicio == NULL || elemento == NULL || elemento < inicio)
    {
        return -1;
    }

    return elemento - inicio;
}
