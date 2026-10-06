/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de
 *        punteros.
 */

#include "recorrido.h"
#include "punteros.h" 

bool copiar_arreglo(int *destino, const int *origen, size_t cantidad)
{
    if (destino == NULL || origen == NULL)
    {
        return false;
    }

    const int *fin = origen + cantidad;
    while (origen < fin)
    {
        *destino = *origen;
        destino++;
        origen++;
    }
    return true;
}

void invertir_arreglo(int *arreglo, size_t cantidad)
{
    // Con menos de dos elementos no hay nada que invertir y además
    // 'arreglo + cantidad - 1' quedaría fuera del arreglo.
    if (arreglo == NULL || cantidad < 2)
    {
        return;
    }

    int *izquierda = arreglo;
    int *derecha = arreglo + cantidad - 1;
    while (izquierda < derecha)
    {
        intercambiar(izquierda, derecha);
        izquierda++;
        derecha--;
    }
}
