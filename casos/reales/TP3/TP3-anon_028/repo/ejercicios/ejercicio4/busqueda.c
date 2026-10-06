/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    if (arreglo == NULL || cantidad == 0) {
        return NULL;
    }

    const int *puntero_actual = arreglo;
    const int *puntero_fin = arreglo + cantidad;

    while (puntero_actual < puntero_fin) {
        if (*puntero_actual == valor) {
            return puntero_actual;
        }
        puntero_actual++;
    }

    return NULL;
}

long distancia_punteros(const int *inicio, const int *elemento)
{
    if (inicio == NULL || elemento == NULL || elemento < inicio) {
        return -1;
    }

    return (long)(elemento - inicio);
}