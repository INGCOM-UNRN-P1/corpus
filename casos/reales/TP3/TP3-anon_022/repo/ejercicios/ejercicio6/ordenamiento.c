/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando
 *        aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    const int *minimo = NULL;

    if (inicio == NULL || fin == NULL || fin <= inicio)
    {
        return NULL;
    }

    minimo = inicio;

    for (const int *actual = inicio + 1; actual < fin; actual++)
    {
        if (*actual < *minimo)
        {
            minimo = actual;
        }
    }

    return minimo;
}

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    for (int *actual = arreglo; actual < arreglo + cantidad - 1; actual++)
    {
        const int *minimo_const =
            buscar_puntero_minimo(actual, arreglo + cantidad);

        int *minimo = (int *)minimo_const;

        intercambiar(actual, minimo);
    }
}