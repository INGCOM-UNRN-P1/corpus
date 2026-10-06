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

    bool cadena_completa = false;
    char *dest = destino;
    const char *orgn = origen;

    size_t largo = 0;
    while (largo < capacidad && *orgn != '\0')
    {
        largo++;
        orgn++;
    }
    if (largo < capacidad)
    {
        cadena_completa = true;
    }
    else
    {
        largo--;
    }
    orgn = origen;

    for (size_t i = 0; i < largo; i++)
    {
        *dest = *orgn;
        dest++;
        orgn++;
    }
    dest++;
    *dest = '\0';

    return cadena_completa;
}


bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if (origen == NULL || destino == NULL || capacidad == 0)
    {
        return false;
    }

    size_t largo_destino = 0;

    while (*destino != '\0' && largo_destino < (capacidad - 1))
    {
        destino++;
        largo_destino++;
    }

    while (*origen != '\0' && largo_destino < (capacidad - 1))
    {
        *destino = *origen;
        largo_destino++;
        destino++;
        origen++;
    }
    *destino = '\0';

    if (*origen == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

size_t longitud_con_punteros(const char *s, size_t capacidad)
{
    if (s == NULL || capacidad == 0)
    {
        return 0;
    }
    
    size_t contador = 0;
    while (contador < capacidad && *s != '\0' )
    {
        s++;
        contador++;
    }

    return contador;
}