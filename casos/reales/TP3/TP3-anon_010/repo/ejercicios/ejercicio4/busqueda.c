/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    const int *encontrado = NULL;

    if (arreglo != NULL)
    {
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;

        while (actual < fin && encontrado == NULL)
        {
            if (*actual == valor)
            {
                encontrado = actual;
            }
            actual++;
        }
    }
    return encontrado;
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