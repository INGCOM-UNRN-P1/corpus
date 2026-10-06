#include <stdint.h>
#include <stdlib.h>
#include "texto_dinamico.h"

static size_t aux_longitud_texto(const char *cadena)
{
    size_t len = 0;
    while (cadena != NULL && *(cadena + len) != '\0')
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

    size_t inicio = 0;
    while (*(origen + inicio) == ' ' || *(origen + inicio) == '\t' || *(origen + inicio) == '\n' || *(origen + inicio) == '\r')
    {
        inicio++;
    }

    if (*(origen + inicio) == '\0')
    {
        return NULL;
    }

    size_t fin = aux_longitud_texto(origen) - 1;
    while (fin > inicio && (*(origen + fin) == ' ' || *(origen + fin) == '\t' || *(origen + fin) == '\n' || *(origen + fin) == '\r'))
    {
        fin--;
    }

    size_t nueva_longitud = fin - inicio + 1;
    
    if (nueva_longitud > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *nueva_cadena = malloc((nueva_longitud + 1) * sizeof(*nueva_cadena));
    
    if (nueva_cadena == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < nueva_longitud; i++)
    {
        *(nueva_cadena + i) = *(origen + inicio + i);
    }
    *(nueva_cadena + nueva_longitud) = '\0';

    return nueva_cadena;
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

    size_t len_origen = aux_longitud_texto(origen);
    
    if (len_origen > SIZE_MAX / veces)
    {
        return NULL;
    }

    size_t len_total = len_origen * veces;

    if (len_total > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *repetida = malloc((len_total + 1) * sizeof(*repetida));
    
    if (repetida == NULL)
    {
        return NULL;
    }

    size_t pos = 0;
    for (size_t i = 0; i < veces; i++)
    {
        for (size_t j = 0; j < len_origen; j++)
        {
            *(repetida + pos) = *(origen + j);
            pos++;
        }
    }
    *(repetida + len_total) = '\0';

    return repetida;
}