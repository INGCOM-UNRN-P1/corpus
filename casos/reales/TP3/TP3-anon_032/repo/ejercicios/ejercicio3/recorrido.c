/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"


bool copiar_arreglo(int *destino, size_t capacidad_destino,
                    int *origen, size_t cantidad_origen)
{
    if (destino == NULL || capacidad_destino == 0 ||
        origen == NULL || cantidad_origen == 0 ||
        capacidad_destino < cantidad_origen)
    {
        return false;
    }

    for (size_t i = 0; i < cantidad_origen; i++)
    {
        *(destino + i) = *(origen + i);
    }

    return true;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return false;
    }
    if (cantidad == 1)
    {
        return true;
    }

    size_t i = 0;
    while (i < cantidad)
    {
        intercambiar((arreglo + i), (arreglo + cantidad - 1));
        i++;
        cantidad--;
    }
    return true;
}
