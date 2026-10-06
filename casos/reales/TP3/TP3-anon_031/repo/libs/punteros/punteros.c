/**
 * @file punteros.c
 * @brief Implementación de la biblioteca libpunteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Observación:
 * No se utilizan ALV ni memoria dinámica.
 */

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    if (primer != NULL && segundo != NULL)
    {
        int auxiliar = *primer;
        *primer = *segundo;
        *segundo = auxiliar;
    }
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    bool resultado = false;

    if (arreglo != NULL && cantidad > 0 && minimo != NULL && maximo != NULL)
    {
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;

        *minimo = *actual;
        *maximo = *actual;

        actual++;

        while (actual < fin)
        {
            if (*actual < *minimo)
            {
                *minimo = *actual;
            }

            if (*actual > *maximo)
            {
                *maximo = *actual;
            }

            actual++;
        }

        resultado = true;
    }

    return resultado;
}
