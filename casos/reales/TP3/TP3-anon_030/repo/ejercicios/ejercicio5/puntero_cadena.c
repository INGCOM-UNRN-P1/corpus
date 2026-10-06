/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

size_t longitud_con_punteros(const char *cadena, size_t capacidad)
{
    if (cadena == NULL)
    {
        return 0;
    }

    const char *actual = cadena;
    const char *fin = cadena + capacidad;

    while (actual < fin && *actual != '\0')
    {
        actual++;
    }

    return actual - cadena;
}

bool copiar_con_punteros(char *destino, size_t capacidad,
                         const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *actual_destino = destino;
    const char *actual_origen = origen;
    char *fin = destino + capacidad - 1;

    while (*actual_origen != '\0' && actual_destino < fin)
    {
        *actual_destino = *actual_origen;

        actual_destino++;
        actual_origen++;
    }

    *actual_destino = '\0';

    if (*actual_origen != '\0')
    {
        return false;
    }

    return true;
}

bool concatenar_con_punteros(char *destino, size_t capacidad,
                             const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *actual_destino = destino;
    char *fin = destino + capacidad;

    while (actual_destino < fin && *actual_destino != '\0')
    {
        actual_destino++;
    }

    if (actual_destino == fin)
    {
        *(fin - 1) = '\0';
        return false;
    }

    const char *actual_origen = origen;
    char *ultimo = fin - 1;

    while (*actual_origen != '\0' && actual_destino < ultimo)
    {
        *actual_destino = *actual_origen;

        actual_destino++;
        actual_origen++;
    }

    *actual_destino = '\0';

    if (*actual_origen != '\0')
    {
        return false;
    }

    return true;
}