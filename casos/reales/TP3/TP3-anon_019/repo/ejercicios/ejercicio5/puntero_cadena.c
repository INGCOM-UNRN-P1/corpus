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

    char *fin = destino + capacidad - 1;
    char *p_dest = destino;
    const char *p_orig = origen;

    while (p_dest < fin && *p_orig != '\0')
    {
        *p_dest = *p_orig;
        p_dest++;
        p_orig++;
    }

    *p_dest = '\0';

    return (*p_orig == '\0');
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *fin = destino + capacidad - 1;
    char *p_dest = destino;

    while (p_dest < fin && *p_dest != '\0')
    {
        p_dest++;
    }

    if (p_dest == fin && *p_dest != '\0')
    {
        *p_dest = '\0';
        return false;
    }

    const char *p_orig = origen;

    while (p_dest < fin && *p_orig != '\0')
    {
        *p_dest = *p_orig;
        p_dest++;
        p_orig++;
    }

    *p_dest = '\0';

    return (*p_orig == '\0');
}