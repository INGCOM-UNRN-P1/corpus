/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h"


int *buscar_puntero_minimo(int *inicio, int *fin)
{
    int *menor = NULL;
    int *actual = NULL;

    if (inicio == NULL || fin == NULL || inicio >= fin)
    {
        return NULL;
    }

    menor = inicio;
    actual = inicio + 1;

    while (actual < fin)
    {
        if (*actual < *menor)
        {
            menor = actual;
        }
        actual++;
    }

    return menor;
}

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    int *actual = NULL;
    int *limite = NULL;
    int *minimo = NULL;

    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    actual = arreglo;
    limite = arreglo + cantidad;

    while (actual < limite - 1)
    {
        minimo = buscar_puntero_minimo(actual, limite);
        if (minimo != NULL && minimo != actual)
        {
            intercambiar(actual, minimo);
        }
        actual++;
    }
}
