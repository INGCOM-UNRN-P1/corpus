/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"



const int *buscar_puntero_minimo(const int *inicio, const int *fin) {
    const int *minimo = NULL;
    if (inicio != NULL && fin != NULL && inicio < fin) {
        minimo = inicio;
        for (const int *ptr_aux = inicio + 1; ptr_aux < fin; ptr_aux++) {
            if (*ptr_aux < *minimo) {
                minimo = ptr_aux;
            }
        }
    }
    return minimo;
}

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo != NULL && cantidad > 1)
    {
        int *fin = arreglo + cantidad;

        for (int *actual = arreglo; actual < fin - 1; actual++)
        {
            const int *p_min = buscar_puntero_minimo(actual, fin);
            if (p_min != NULL && p_min != actual)
            {
                int *p_min_modificable = (int *)p_min;

                int aux = *actual;
                *actual = *p_min_modificable;
                *p_min_modificable = aux;
            }
        }
    }
}
    
