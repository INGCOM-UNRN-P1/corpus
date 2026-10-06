/**
 * @file ordenamiento.c
 * @brief Implementacion de ordenamiento por seleccion empleando aritmetica de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || inicio >= fin)
    {
        return NULL;
    }

    const int *ptr_min = inicio;
    const int *actual = inicio + 1;

    while (actual < fin)
    {
        if (*actual < *ptr_min)
        {
            ptr_min = actual;
        }
        actual++;
    }

    return ptr_min;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (cantidad <= 1)
    {
        return (cantidad == 0 || arreglo != NULL);
    }

    if (arreglo == NULL)
    {
        return false;
    }

    int *actual = arreglo;
    int *fin = arreglo + cantidad;

    while (actual < fin - 1)
    {
        const int *ptr_min_const = buscar_puntero_minimo(actual, fin);
        if (ptr_min_const != NULL && ptr_min_const != actual)
        {
            
            int *ptr_min = (int *)ptr_min_const;
            intercambiar(actual, ptr_min);
        }
        actual++;
    }

    return true;
}