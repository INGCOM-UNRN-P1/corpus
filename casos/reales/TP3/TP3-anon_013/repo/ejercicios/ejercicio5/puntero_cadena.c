/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros (char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }
    char *comienzo = destino;
    while (destino < (comienzo + capacidad -1) && *origen != '\0')
    {
        *destino = *origen;
        origen++;
        destino++;
    }
    if (*origen == '\0')
    {
        *destino = *origen;
        return true;
    }
    else
    {
        *destino = '\0';
        return false;
    }
}

bool concatenar_con_punteros (char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }

    char *ptr_auxiliar = destino;
    while (ptr_auxiliar < (destino + capacidad) && *ptr_auxiliar != '\0')
    {
        ptr_auxiliar++;
    }
    size_t capacidad_restante = destino + capacidad - ptr_auxiliar;
    return copiar_con_punteros(ptr_auxiliar, capacidad_restante, origen);
}