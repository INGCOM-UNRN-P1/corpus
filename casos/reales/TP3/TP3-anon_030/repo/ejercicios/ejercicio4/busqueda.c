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

    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        if (*actual == valor)
        {
            return actual;
        }

        actual++;
    }

    return NULL;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    if (inicio == NULL || elemento == NULL)
    {
        return -1;
    }

    if (elemento < inicio)
    {
        return -1;
    }

    return elemento - inicio;
}