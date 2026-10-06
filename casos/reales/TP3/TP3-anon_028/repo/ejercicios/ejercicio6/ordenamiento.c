/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || inicio >= fin) {
        return NULL;
    }

    const int *puntero_minimo = inicio;
    const int *puntero_actual = inicio + 1;

    while (puntero_actual < fin) {
        if (*puntero_actual < *puntero_minimo) {
            puntero_minimo = puntero_actual;
        }
        puntero_actual++;
    }

    return puntero_minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0) {
        return false;
    }

    int *puntero_posicion_actual = arreglo;
    int *puntero_limite_fin = arreglo + cantidad;

    while (puntero_posicion_actual < puntero_limite_fin - 1) {
        int *puntero_minimo = (int *)buscar_puntero_minimo(puntero_posicion_actual, puntero_limite_fin);

        if (puntero_minimo != NULL && puntero_minimo != puntero_posicion_actual) {
            int valor_temporal = *puntero_posicion_actual;
            *puntero_posicion_actual = *puntero_minimo;
            *puntero_minimo = valor_temporal;
        }

        puntero_posicion_actual++;
    }

    return true;
}

