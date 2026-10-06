/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por
 * selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || inicio >= fin)
    {
        return NULL;
    }

    const int *puntero_actual = inicio + 1;
    const int *puntero_minimo = inicio;

    while (puntero_actual < fin)
    {
        if (*puntero_actual < *puntero_minimo)
        {
            puntero_minimo = puntero_actual;
        }
        puntero_actual++;
    }
    return puntero_minimo;
}

int *ordenar_seleccion_punteros(int *arreglo, size_t capacidad)
{
    if (arreglo == NULL || capacidad == 0)
    {
        return NULL;
    }

    int *puntero_actual = arreglo;
    int *fin = arreglo + capacidad;

    while (puntero_actual < fin)
    {
        const int *puntero_minimo_const = buscar_puntero_minimo(puntero_actual, fin);
        
        int *puntero_minimo = puntero_actual + (puntero_minimo_const - puntero_actual);

        if (puntero_minimo != puntero_actual)
        {
            int auxiliar = *puntero_actual;
            *puntero_actual = *puntero_minimo;
            *puntero_minimo = auxiliar;
        }
        puntero_actual++;
    }
    return arreglo;
}