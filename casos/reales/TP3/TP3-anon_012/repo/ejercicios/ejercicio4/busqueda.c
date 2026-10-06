/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    const int *hallado = NULL;

    if (arreglo != NULL && cantidad > 0)
    {
        const int *ptr = arreglo;
        const int *fin = arreglo + cantidad;

        while (ptr < fin && hallado == NULL)
        {
            if (*ptr == valor)
            {
                hallado = ptr;
            }
            ptr++;
        }
    }

    return hallado;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    ptrdiff_t distancia = -1;

    if (inicio != NULL && elemento != NULL && elemento > inicio)
    {
        distancia = elemento - inicio;
    }

    return distancia;
}


