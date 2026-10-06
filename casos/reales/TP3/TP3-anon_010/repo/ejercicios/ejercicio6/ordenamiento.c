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
        minimo = inicio;
        const int *actual = inicio + 1;

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

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo != NULL)
    {
        int *actual = arreglo;
        int *fin = arreglo + cantidad;

        while (actual < fin)
        {
            const int *minimo = buscar_puntero_minimo(actual, fin);
            intercambiar(actual, (int *)minimo);
            actual++;
        }
    }
}