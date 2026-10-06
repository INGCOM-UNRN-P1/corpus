/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"

bool copiar_arreglo(const int *origen, size_t cantidad, int *destino)
{
    if (origen == NULL || destino == NULL)
    {
        return false;
    }

    const int *fin_origen = origen + cantidad;
    const int *cursor_origen = origen;
    int *cursor_destino = destino;

    while (cursor_origen < fin_origen)
    {
        *cursor_destino = *cursor_origen;
        cursor_origen++;
        cursor_destino++;
    }

    return true;
}

void invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    int *inicio = arreglo;
    int *fin = arreglo + cantidad - 1;

    while (inicio < fin)
    {
        intercambiar(inicio, fin);
        inicio++;
        fin--;
    }

    return;
}