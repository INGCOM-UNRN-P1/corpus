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

    char *cursor_destino = destino;
    const char *cursor_origen = origen;
    size_t ocupados = 0;

    while (*cursor_origen != '\0' && ocupados < capacidad - 1)
    {
        *cursor_destino = *cursor_origen;
        cursor_destino++;
        cursor_origen++;
        ocupados++;
    }

    *cursor_destino = '\0';
    return *cursor_origen == '\0';
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *cursor_destino = destino;

    while (*cursor_destino != '\0' && (cursor_destino - destino) < (ptrdiff_t)capacidad)
    {
        cursor_destino++;
    }

    if ((size_t)(cursor_destino - destino) >= capacidad)
    {
        destino[capacidad - 1] = '\0';
        return false;
    }

    const char *cursor_origen = origen;
    while (*cursor_origen != '\0' && (size_t)(cursor_destino - destino) < capacidad - 1)
    {
        *cursor_destino = *cursor_origen;
        cursor_destino++;
        cursor_origen++;
    }

    *cursor_destino = '\0';
    return *cursor_origen == '\0';
}
