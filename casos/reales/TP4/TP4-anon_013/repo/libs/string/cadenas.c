/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include "cadenas.h"
#include <stdlib.h>

size_t longitud_util_cadena(const char *cadena, size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }
    for (size_t i = 0; i < capacidad; i++)
    {
        if (*cadena == '\0')
        {
            return i;
        }
        cadena++;
    }
    return capacidad;
}

void intercambiar_char(char *primer, char *segundo)
{
    if (primer == NULL || segundo == NULL || primer == segundo)
    {
        return;
    }
    else
    {
        char auxiliar = *primer;
        *primer = *segundo;
        *segundo = auxiliar;
    }
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }
    else
    {
        size_t capacidad_util = longitud_util_cadena(origen, capacidad_max);
        char *ptr_heap = malloc(sizeof(char) * (capacidad_util + 1));
        if (ptr_heap == NULL)
        {
            return NULL;
        }
        else
        {
            memcpy(ptr_heap, origen, sizeof(char) * capacidad_util);
            ptr_heap[capacidad_util] = '\0';
            return ptr_heap;
        }
    }
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 ||
        cap_segunda == 0)
    {
        return NULL;
    }
    else
    {
        size_t cap_util_primera = longitud_util_cadena(primera, cap_primera);
        size_t cap_util_segunda = longitud_util_cadena(segunda, cap_segunda);

        size_t cap_util_total = cap_util_primera + cap_util_segunda + 1;
        char *destino = malloc(cap_util_total * sizeof(char));
        if (destino == NULL)
        {
            return NULL;
        }
        else
        {
            memcpy(destino, primera, sizeof(char) * cap_util_primera);
            memcpy(destino + cap_util_primera, segunda,
                   sizeof(char) * cap_util_segunda);
            *(destino + cap_util_total - 1) = '\0';
            return destino;
        }
    }
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL || *puntero_cadena == NULL)
    {
        return;
    }
    else
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}



char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t longitud_extraida = longitud_util_cadena(origen, capacidad_max);
    if (inicio < longitud_extraida)
    {
        longitud_extraida = longitud_extraida - inicio;
        if (cantidad < longitud_extraida)
        {
            longitud_extraida = cantidad;
        }
    }
    else
    {
        longitud_extraida = 0;
    }

    char *destino = malloc(sizeof(char) * (longitud_extraida + 1));
    if (destino == NULL)
    {
        return NULL;
    }
    if (longitud_extraida > 0)
    {
        memcpy(destino, origen + inicio, longitud_extraida);
    }
    *(destino + longitud_extraida) = '\0';
    return destino;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud_util = longitud_util_cadena(origen, capacidad_max);
    char *destino = malloc(sizeof(char) * (longitud_util + 1));
    if (destino == NULL)
    {
        return NULL;
    }

    if (longitud_util > 0)
    {
        memcpy(destino, origen, longitud_util);
        if (longitud_util > 1)
        {
            char *inicio = destino;
            char *final = destino + longitud_util - 1;
            while (inicio < final)
            {
                intercambiar_char(inicio, final);
                inicio++;
                final--;
            }
        }
    }
    *(destino + longitud_util) = '\0';
    return destino;
}
