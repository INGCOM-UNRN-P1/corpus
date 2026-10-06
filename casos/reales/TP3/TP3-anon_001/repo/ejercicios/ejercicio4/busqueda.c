/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado)
{
    const int *ptr = NULL;
    if (arreglo != NULL)
    {
        bool encontrado = false;
        for (size_t i = 0; (i < cantidad) && (encontrado == false); i++)
        {
            if (*(arreglo + i) == buscado)
            {
                encontrado = true;
                ptr = arreglo + i;
            }
        }
    }
    return ptr;
}

long distancia_punteros(const int *inicio, const int *p)
{
    long distancia = -1;

    if ((inicio != NULL) && (p != NULL) && (p >= inicio))
    {
        distancia = (long)(p - inicio);
    }

    return distancia;
}