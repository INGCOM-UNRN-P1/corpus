/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    const int *minimo = NULL;

    if (inicio != NULL && fin != NULL && inicio < fin)
    {
        const int *actual = inicio;

        minimo = inicio;
        actual++;

        while (actual < fin)
        {
            if (*actual < *minimo)
            {
                minimo = actual;
            }

            actual++;
        }
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    bool operacion_exitosa = false;

    if (arreglo != NULL)
    {
        int *actual = arreglo;
        int *fin = arreglo + cantidad;

        while (actual < fin)
        {
            const int *minimo = buscar_puntero_minimo(actual, fin);

            if (minimo != NULL)
            {
                ptrdiff_t distancia_minimo = minimo - actual;
                intercambiar(actual, actual + distancia_minimo);
            }

            actual++;
        }

        operacion_exitosa = true;
    }

    return operacion_exitosa;
}
