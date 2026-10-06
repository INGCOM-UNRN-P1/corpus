/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"


size_t longitud_con_punteros(const char *cadena, size_t capacidad)
{
    size_t longitud = capacidad;

    if (cadena != NULL)
    {   
        const char *actual = cadena;
        longitud = 0;

        while (longitud < capacidad && *actual != '\0')
        {
            longitud++;
            actual++;
        } 
    }
    return longitud;
}


bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    bool completa = false;

    if (destino != NULL && capacidad > 0 && origen != NULL)
    {
        char *actual_destino = destino;
        const char *actual_origen = origen;
        const char *limite = destino + capacidad - 1;

        while (actual_destino < limite && *actual_origen != '\0')
        {
            *actual_destino = *actual_origen;
            actual_destino++;
            actual_origen++;
        }

        *actual_destino = '\0';
        completa = (*actual_origen == '\0');
    }
    return completa;
}


bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    bool completa = false;

    if (destino != NULL && capacidad > 0 && origen != NULL)
    {
        char *actual_destino = destino;
        const char *limite = destino + capacidad;

        while (actual_destino < limite && *actual_destino != '\0')
        {
            actual_destino++;
        }

        const char *actual_origen = origen;
        const char *limite_escritura = destino + capacidad - 1;

        while (actual_destino < limite_escritura && *actual_origen != '\0')
        {
            *actual_destino = *actual_origen;
            actual_destino++;
            actual_origen++;
        }

        *actual_destino = '\0';
        completa = (*actual_origen == '\0');
    }
    return completa;
}