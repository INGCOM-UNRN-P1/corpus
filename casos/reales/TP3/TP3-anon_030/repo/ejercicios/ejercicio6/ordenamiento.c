/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || inicio >= fin)
    {
        return NULL;
    }

    const int *minimo = inicio;
    const int *actual = inicio + 1;

    while (actual < fin)
    {
        if (*actual < *minimo)
        {
            minimo = actual;
        }

        actual++;
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }

    if (cantidad < 2)
    {
        return true;
    }

    int *actual = arreglo;
    int *fin = arreglo + cantidad;

    while (actual < fin - 1)
    {
        const int *minimo_encontrado =
            buscar_puntero_minimo(actual, fin);

        ptrdiff_t distancia = minimo_encontrado - actual;
        int *minimo = actual + distancia;

        if (minimo != actual)
        {
            intercambiar(actual, minimo);
        }

        actual++;
    }

    return true;
}