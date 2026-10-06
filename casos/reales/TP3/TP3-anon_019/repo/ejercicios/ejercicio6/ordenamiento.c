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
    const int *p = inicio + 1; 

    while (p < fin)
    {
        if (*p < *minimo)
        {
            minimo = p; 
        }
        p++;
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return false;
    }

    int *fin = arreglo + cantidad;
    int *actual = arreglo;

    while (actual < fin - 1)
    {
        int *minimo = (int *)buscar_puntero_minimo(actual, fin);

        if (minimo != actual)
        {
            intercambiar(actual, minimo);
        }
        
        actual++;
    }

    return true;
}