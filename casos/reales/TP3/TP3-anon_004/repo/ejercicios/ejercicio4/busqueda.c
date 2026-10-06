/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"



const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado)
{
    const int *actual = NULL;
    const int *limite = NULL;

    if (arreglo == NULL || cantidad == 0)
    {
        return NULL;
    }

    actual = arreglo;
    limite = arreglo + cantidad;

    while (actual < limite)
    {
        if (*actual == buscado)
        {
            return actual;
        }
        actual++;
    }

    return NULL;
}

bool distancia_punteros(const int *inicio, const int *elemento, size_t *distancia)
{
    if (inicio == NULL || elemento == NULL || distancia == NULL || elemento < inicio)
    {
        return false;
    }

    *distancia = (size_t)(elemento - inicio);

    return true;
}
