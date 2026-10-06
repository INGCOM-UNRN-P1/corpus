/**
 * @file puntero_cadena.c
 * @brief Implementación de cadenas seguras con aritmética de punteros.
 */

#include "puntero_cadena.h"

size_t longitud_con_punteros(const char *cadena, size_t capacidad)
{
    size_t longitud = capacidad;

    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    const char *actual = cadena;
    const char *limite = cadena + capacidad;

    while (actual < limite && *actual != '\0')
    {
        actual++;
    }

    if (actual < limite)
    {
        longitud = (size_t) (actual - cadena);
    }

    return longitud;
}

bool copiar_con_punteros(char *destino, size_t capacidad,
                          const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    char *salida = destino;
    const char *entrada = origen;
    const char *limite = destino + (capacidad - 1);

    while (salida < limite && *entrada != '\0')
    {
        *salida = *entrada;
        salida++;
        entrada++;
    }

    *salida = '\0';

    return (*entrada == '\0');
}

bool concatenar_con_punteros(char *destino, size_t capacidad,
                              const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t longitud = longitud_con_punteros(destino, capacidad);

    if (longitud == capacidad)
    {
        return false;
    }

    char *salida = destino + longitud;
    const char *entrada = origen;
    const char *limite = destino + (capacidad - 1);

    while (salida < limite && *entrada != '\0')
    {
        *salida = *entrada;
        salida++;
        entrada++;
    }

    *salida = '\0';

    return (*entrada == '\0');
}