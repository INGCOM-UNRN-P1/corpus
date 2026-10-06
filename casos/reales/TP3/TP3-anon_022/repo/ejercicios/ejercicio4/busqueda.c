/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta
 *        de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return NULL;
    }

    const int *fin = arreglo + cantidad;
    const int *actual = arreglo;

    while (actual < fin)
    {
        if (*actual == buscado)
        {
            return actual;
        }

        actual++;
    }

    return NULL;
}

long distancia_punteros(const int *inicio, const int *elemento)
{
    if(inicio == NULL || elemento == NULL || elemento < inicio){
        return -1;
    }

    return (long)(elemento - inicio);
}