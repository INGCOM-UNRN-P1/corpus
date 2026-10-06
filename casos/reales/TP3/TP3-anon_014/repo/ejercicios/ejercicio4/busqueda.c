/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de
 *        punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado)
{
    if (arreglo == NULL)
    {
        return NULL;
    }

    const int *encontrado = NULL;
    const int *fin = arreglo + cantidad;
    // El lazo termina apenas encuentra el valor: interesa la primera
    // aparición, no la última.
    for (const int *actual = arreglo; actual < fin && encontrado == NULL;
         actual++)
    {
        if (*actual == buscado)
        {
            encontrado = actual;
        }
    }
    return encontrado;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    if (inicio == NULL || elemento == NULL)
    {
        return DISTANCIA_INVALIDA;
    }
    if (elemento < inicio)
    {
        return DISTANCIA_INVALIDA;
    }
    return elemento - inicio;
}
