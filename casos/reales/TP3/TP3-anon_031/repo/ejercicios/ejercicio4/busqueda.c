/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    const int *resultado = NULL;

    if (arreglo != NULL)
    {
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;

        while (actual < fin && resultado == NULL)
        {
            if (*actual == valor)
            {
                resultado = actual;
            }
            else
            {
                actual++;
            }
        }
    }

    return resultado;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    ptrdiff_t distancia = -1;

    if (inicio != NULL && elemento != NULL && elemento >= inicio)
    {
        distancia = elemento - inicio;
    }

    return distancia;
}
