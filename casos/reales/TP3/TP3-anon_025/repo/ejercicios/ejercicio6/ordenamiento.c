/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"



const int* buscar_puntero_minimo(const int *puntero_inicio, const int * puntero_fin)
{
    if (puntero_inicio == NULL || puntero_fin == NULL || puntero_inicio >= puntero_fin)
    {
        return NULL;
    }

    const int *puntero_minimo = puntero_inicio;
    const int *cursor_actual = puntero_inicio + 1;

    while (cursor_actual < puntero_fin)
    {
        if (*cursor_actual < *puntero_minimo)
        {
            puntero_minimo = cursor_actual;
        }
        cursor_actual++;
    }
    return puntero_minimo;
}
void ordenar_seleccion_punteros(int *puntero_arreglo, size_t cantidad_elementos)
{
    if (puntero_arreglo == NULL || cantidad_elementos <= 1)
    {
        return;
    }

    int *cursor_actual = puntero_arreglo;
    int *puntero_fin = puntero_arreglo + cantidad_elementos;
    while (cursor_actual < puntero_fin -1)
    {
        int *minimo_encontrado = (int*)buscar_puntero_minimo(cursor_actual, puntero_fin);
        if (minimo_encontrado != NULL && minimo_encontrado != cursor_actual)
        {
            int temporal = *cursor_actual;
            *cursor_actual = *minimo_encontrado;
            *minimo_encontrado = temporal;
        }
        cursor_actual++;
    }
}