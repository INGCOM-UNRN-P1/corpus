/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

size_t longitud_con_punteros(const char *cadena, size capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    const char *actual = cadena;
    const char *fin =cadena + capacidad;

    while (actual < fin && *actual != '\0')
    {
        actual++
    }

    return (size_t)(actual - cadena);
}

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false
    }

    char *escritura = destino;
    const char *limite = destino + capacidad - 1;

    while (escritura < limite && *origen != '\0')
    {
        *escritura++ = *origen++;
    }

    *escritura = '\0';
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    chat *escritura = desitno + longitud_con_punteros(destino, capacidad);
    char *limite = destino + capacidad - 1;

    if (escritura > limite)
    {
        escritura = limite;
    }

    while (escritura < limite && *origen != '\0')
    {
        *escritura++ = *origen++;
    }
    *escritura = '\0';

    return *origen =='\0';
}