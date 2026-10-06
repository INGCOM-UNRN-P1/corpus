/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"


const int *buscar_primero(const int *inicio, size_t cantidad, int valor)
{
    if (inicio == NULL || cantidad == 0)
    {
        return NULL;
    }

    const int *puntero = NULL;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (*(inicio + i) == valor)
        {
            puntero = (inicio + i);
            return puntero;
        }
    }

    return puntero;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    if (inicio == NULL ||
        elemento == NULL ||
        elemento < inicio)
    {
        return -1;
    }

    return (elemento - inicio);
}
