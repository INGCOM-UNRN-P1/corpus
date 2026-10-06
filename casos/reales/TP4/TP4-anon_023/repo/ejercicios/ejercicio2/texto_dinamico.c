/**
 * @file texto_dinamico.c
 * @brief Implementacion de funciones de texto dinamico en heap.
 */

#include "texto_dinamico.h"
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>

static size_t longitud_cadena(const char *cadena)
{
    if (cadena == NULL)
    {
        return 0;
    }

    size_t len = 0;
    while (*(cadena + len) != '\0')
    {
        len++;
    }
    return len;
}

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }

    
    const char *inicio = origen;
    while (*inicio != '\0' && isspace((unsigned char)*inicio))
    {
        inicio++;
    }

    
    if (*inicio == '\0')
    {
        return NULL;
    }

    
    const char *fin = inicio;
    const char *p = inicio;
    while (*p != '\0')
    {
        if (!isspace((unsigned char)*p))
        {
            fin = p;
        }
        p++;
    }

    size_t longitud_util = (size_t)(fin - inicio + 1);

    char *recortada = malloc((longitud_util + 1) * sizeof(*recortada));
    if (recortada == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud_util; i++)
    {
        *(recortada + i) = *(inicio + i);
    }
    *(recortada + longitud_util) = '\0';

    return recortada;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL)
    {
        return NULL;
    }

    if (veces == 0)
    {
        char *vacia = malloc(1 * sizeof(*vacia));
        if (vacia != NULL)
        {
            *vacia = '\0';
        }
        return vacia;
    }

    size_t len_origen = longitud_cadena(origen);

    
    if (len_origen > 0 && veces > (SIZE_MAX - 1) / len_origen)
    {
        return NULL;
    }

    size_t total_bytes = (len_origen * veces) + 1;

    char *resultado = malloc(total_bytes * sizeof(*resultado));
    if (resultado == NULL)
    {
        return NULL;
    }

    char *destino = resultado;
    for (size_t v = 0; v < veces; v++)
    {
        for (size_t i = 0; i < len_origen; i++)
        {
            *destino = *(origen + i);
            destino++;
        }
    }
    *destino = '\0';

    return resultado;
}
