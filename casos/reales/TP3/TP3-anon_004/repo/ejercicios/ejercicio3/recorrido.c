/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"


bool copiar_arreglo(int *destino, const int *origen, size_t cantidad)
{
    int *cursor_dst = NULL;
    const int *cursor_src = NULL;
    const int *limite_src = NULL;

    if (destino == NULL || origen == NULL)
    {
        return false;
    }

    cursor_dst = destino;
    cursor_src = origen;
    limite_src = origen + cantidad;

    while (cursor_src < limite_src)
    {
        *cursor_dst++ = *cursor_src++;
    }

    return true;
}

void invertir_arreglo(int *arreglo, size_t cantidad)
{
    int *izquierda = NULL;
    int *derecha = NULL;

    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    izquierda = arreglo;
    derecha = arreglo + (cantidad - 1);

    while (izquierda < derecha)
    {
        intercambiar(izquierda, derecha);
        izquierda++;
        derecha--;
    }
}
