/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
    if (origen == NULL || destino == NULL)
    {
        return false;
    }

    const int *cursor_origen = origen;
    const int *fin = origen + cantidad;
    int *cursor_destino = destino;

    while (cursor_origen < fin)
    {
        *cursor_destino = *cursor_origen;
        cursor_origen++;
        cursor_destino++;
    }

    return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }

    int *inicio = arreglo;
    int *fin = arreglo + cantidad - 1;

    while (inicio < fin)
    {
        intercambiar(inicio, fin);
        inicio++;
        fin--;
    }

    return true;
}
