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

    const int *fin = origen + cantidad;

    while (origen < fin)
    {
        *destino = *origen;
        destino++;
        origen++;
    }

    return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return false;
    }

    int *inicio = arreglo;
    int *fin = arreglo + (cantidad - 1);

    while (inicio < fin)
    {
        intercambiar(inicio, fin);
        inicio++;
        fin--;
    }

    return true;
}