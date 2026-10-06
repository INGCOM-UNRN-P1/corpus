/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }
    const char *limite = destino + (capacidad - 1);
    while (destino < limite && *origen != '\0')
    {
        *destino = *origen; // Copia en la posición actual.
        destino++;          // Avanza el puntero destino a la siguiente casilla.
        origen++;           // Avanza el puntero origen a la siguiente casilla.
    }
    *destino = '\0';
    if (*origen != '\0')
    {
        return false;
    }
    return true;
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *puntero = destino;
    const char *limite = destino + (capacidad - 1);

    while (puntero < limite && *puntero != '\0')
    //se busca el final de la cadena actual en destino
    {
        puntero++;
    }

    while (puntero < limite && *origen != '\0')
    //se copia origen desde donde quedo puntero
    {
        *puntero = *origen;
        puntero++;
        origen++;
    }

    *puntero = '\0';

    if (*origen != '\0')
    {
        return false;
    }

    return true;
}