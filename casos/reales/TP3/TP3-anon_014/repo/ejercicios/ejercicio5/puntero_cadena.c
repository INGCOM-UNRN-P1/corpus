/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante
 *        punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad,
                         const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    // Se reserva la última posición del buffer para el '\0'.
    const char *ultimo = destino + capacidad - 1;
    while (*origen != '\0' && destino < ultimo)
    {
        *destino++ = *origen++;
    }
    *destino = '\0';

    return *origen == '\0';
}

bool concatenar_con_punteros(char *destino, size_t capacidad,
                             const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t ocupado = longitud_con_punteros(destino, capacidad);
    if (ocupado == capacidad)
    {
        return false;
    }

    // Copiar sobre el '\0' actual reutiliza la lógica de truncamiento con
    // la capacidad que queda libre.
    return copiar_con_punteros(destino + ocupado, capacidad - ocupado,
                               origen);
}

size_t longitud_con_punteros(const char *cadena, size_t capacidad)
{
    if (cadena == NULL)
    {
        return 0;
    }

    const char *actual = cadena;
    const char *limite = cadena + capacidad;
    while (actual < limite && *actual != '\0')
    {
        actual++;
    }
    return (size_t)(actual - cadena);
}
