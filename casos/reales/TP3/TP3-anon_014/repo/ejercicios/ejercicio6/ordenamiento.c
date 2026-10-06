/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética
 *        de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h" 

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || fin <= inicio)
    {
        return NULL;
    }

    const int *minimo = inicio;
    for (const int *actual = inicio + 1; actual < fin; actual++)
    {
        if (*actual < *minimo)
        {
            minimo = actual;
        }
    }
    return minimo;
}

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL)
    {
        return;
    }

    int *fin = arreglo + cantidad;
    for (int *actual = arreglo; actual < fin; actual++)
    {
        const int *minimo = buscar_puntero_minimo(actual, fin);
        // buscar_puntero_minimo devuelve un puntero de solo lectura; se
        // recupera uno modificable a partir de su distancia a 'actual',
        // sin descartar el const con un cast.
        int *posicion_minimo = actual + (minimo - actual);
        intercambiar(actual, posicion_minimo);
    }
}
