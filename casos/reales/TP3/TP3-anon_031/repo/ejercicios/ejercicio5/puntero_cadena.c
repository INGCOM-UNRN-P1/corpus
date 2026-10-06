/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    bool copia_completa = false;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        char *actual_destino = destino;
        const char *actual_origen = origen;
        char *ultimo = destino + capacidad - 1;

        while (*actual_origen != '\0' && actual_destino < ultimo)
        {
            *actual_destino = *actual_origen;
            actual_destino++;
            actual_origen++;
        }

        *actual_destino = '\0';

        if (*actual_origen == '\0')
        {
            copia_completa = true;
        }
    }

    return copia_completa;
}

size_t longitud_con_punteros(const char *cadena, size_t capacidad)
{
    size_t longitud = 0;

    if (cadena != NULL)
    {
        const char *actual = cadena;
        const char *fin = cadena + capacidad;

        while (actual < fin && *actual != '\0')
        {
            longitud++;
            actual++;
        }
    }

    return longitud;
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    bool concatenacion_completa = false;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t longitud_destino = longitud_con_punteros(destino, capacidad);

        if (longitud_destino < capacidad)
        {
            char *inicio_copia = destino + longitud_destino;
            size_t capacidad_restante = capacidad - longitud_destino;

            concatenacion_completa = copiar_con_punteros(
                inicio_copia,
                capacidad_restante,
                origen
            );
        }
    }

    return concatenacion_completa;
}
