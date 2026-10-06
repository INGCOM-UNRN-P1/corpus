/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, const size_t cantidad, int valor)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return NULL;
    }
    else
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (*arreglo == valor)
            {
                const int *encontrado = arreglo;
                return encontrado;
            }
            arreglo++;
        }
        return NULL;
    }
}

long long int distancia_punteros (const int *const arreglo, size_t cantidad, const int *const elemento)
{
    if (arreglo == NULL || cantidad == 0 || elemento == NULL || elemento < arreglo)
    {
        return -1;
    }
    else
    {
        size_t distancia = elemento - arreglo;
        if (distancia >= cantidad)
        {
            return -1;
        }
        else
        {
            return (long long int)distancia;
        }
    }
}