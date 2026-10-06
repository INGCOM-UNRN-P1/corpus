/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"

bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
    if (origen == NULL || destino == NULL)
    {
        return false;
    }

    const int *actual_origen = origen;
    int *actual_destino = destino;
    const int *fin = origen + cantidad;

    while (actual_origen < fin)
    {
        *actual_destino = *actual_origen;

        actual_origen++;
        actual_destino++;
    }

    return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }

    if (cantidad < 2)
    {
        return true;
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