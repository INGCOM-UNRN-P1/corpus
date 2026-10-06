/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    const int *minimo = NULL;

    if (inicio == NULL || fin == NULL)
    {
        minimo = NULL;
    }
    else if (fin <= inicio)
    {
        minimo = NULL;
    }
    else
    {
        minimo = inicio;

        for (const int *actual = inicio + 1; actual < fin; actual++)
        {
            if (*actual < *minimo)
            {
                minimo = actual;
            }
        }
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    bool resultado = false;

    if (arreglo == NULL && cantidad > 0)
    {
        resultado = false;
    }
    else if (cantidad == 0)
    {
        resultado = true;
    }
    else
    {
        int *fin = arreglo + cantidad;

        for (int *actual = arreglo; actual < fin; actual++)
        {
            const int *minimo = buscar_puntero_minimo(actual, fin);

            if (minimo != NULL)
            {
                intercambiar(actual, (int *)minimo);
            }
        }

        resultado = true;
    }

    return resultado;
}