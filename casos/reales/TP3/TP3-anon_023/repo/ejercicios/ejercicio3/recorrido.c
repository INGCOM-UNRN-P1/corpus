/**
 * @file recorrido.c
 * @brief Implementacion de recorrido, copia e inversion con aritmetica de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(int *destino, const int *origen, size_t cantidad)
{
    if (cantidad == 0)
    {
        return true;
    }

    if (destino == NULL || origen == NULL)
    {
        return false;
    }

    int *ptr_dest = destino;
    const int *ptr_orig = origen;
    const int *fin_orig = origen + cantidad;

    while (ptr_orig < fin_orig)
    {
        *ptr_dest = *ptr_orig;
        ptr_dest++;
        ptr_orig++;
    }

    return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (cantidad == 0)
    {
        return true;
    }

    if (arreglo == NULL)
    {
        return false;
    }

    if (cantidad == 1)
    {
        return true;
    }

    int *izq = arreglo;
    int *der = arreglo + cantidad - 1;

    while (izq < der)
    {
        intercambiar(izq, der);
        izq++;
        der--;
    }

    return true;
}