/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"



bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    char *cursor_dst = NULL;
    char *limite_dst = NULL;
    const char *cursor_src = NULL;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    cursor_dst = destino;
    limite_dst = destino + (capacidad - 1);
    cursor_src = origen;

    while (cursor_dst < limite_dst && *cursor_src != '\0')
    {
        *cursor_dst++ = *cursor_src++;
    }

    *cursor_dst = '\0';

    if (*cursor_src != '\0')
    {
        return false;
    }

    return true;
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    char *cursor_dst = NULL;
    char *limite_dst = NULL;
    const char *cursor_src = NULL;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    cursor_dst = destino;
    limite_dst = destino + (capacidad - 1);

    while (cursor_dst < limite_dst && *cursor_dst != '\0')
    {
        cursor_dst++;
    }

    if (*cursor_dst != '\0')
    {
        return false;
    }

    cursor_src = origen;

    while (cursor_dst < limite_dst && *cursor_src != '\0')
    {
        *cursor_dst++ = *cursor_src++;
    }

    *cursor_dst = '\0';

    if (*cursor_src != '\0')
    {
        return false;
    }

    return true;
}
