/**
 * @file puntero_cadena.c
 * @brief Implementacion de copia y concatenacion de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *dst = destino;
    const char *src = origen;
    size_t escritos = 0;

    while (*src != '\0' && escritos + 1 < capacidad)
    {
        *dst = *src;
        dst++;
        src++;
        escritos++;
    }

    *dst = '\0';

    return (*src == '\0');
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *dst = destino;
    size_t longitud_actual = 0;

    while (*dst != '\0' && longitud_actual < capacidad)
    {
        dst++;
        longitud_actual++;
    }

    if (longitud_actual >= capacidad)
    {
        return false;
    }

    const char *src = origen;
    size_t escritos = longitud_actual;

    while (*src != '\0' && escritos + 1 < capacidad)
    {
        *dst = *src;
        dst++;
        src++;
        escritos++;
    }

    *dst = '\0';

    return (*src == '\0');
}
