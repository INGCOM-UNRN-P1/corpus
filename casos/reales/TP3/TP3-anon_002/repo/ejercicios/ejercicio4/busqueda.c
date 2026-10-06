/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    const int *resultado = NULL;

    if (arreglo == NULL)
    {
        resultado = NULL;
    }
    else if (cantidad == 0)
    {
        resultado = NULL;
    }
    else
    {
        const int *ptr = arreglo;

        const int *limite = arreglo + cantidad;

        while (ptr < limite && resultado == NULL)
        {
            if (*ptr == valor)
            {
                resultado = ptr;
            }
            else
            {
                ptr++;
            }
        }
    }
    return resultado;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    ptrdiff_t resultado = -1;

    if (inicio == NULL || elemento == NULL)
    {
        resultado = -1;
    }
    else if (elemento < inicio)
    {
        resultado = -1;
    }
    else
    {
        resultado = elemento - inicio;
    }
    return resultado;
}