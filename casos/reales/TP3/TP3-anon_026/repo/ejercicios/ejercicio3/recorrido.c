/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(int *destino, size_t capacidad, const int *origen, size_t cantidad)
{
    if (destino == NULL || origen == NULL || capacidad < cantidad)
    {
        return false;
    }
    const int *fin = origen + cantidad;

    while (origen < fin)
    {
        *destino = *origen;
        origen++;
        destino++;
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