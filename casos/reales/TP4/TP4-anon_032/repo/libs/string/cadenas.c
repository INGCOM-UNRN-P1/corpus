/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"
//No pude incluir la liberia de cadenas del tp2 de ninguna manera

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t largo = 0;
    while(origen[largo] != '\0' && largo < capacidad_max)
    {
        largo++;
    }

    char *bloque = malloc((largo + 1));
    if (bloque == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < largo; i++)
    {
        bloque[i] = origen[i];
    }
    bloque[largo] = '\0';

    return bloque;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    size_t largo_primera = 0;
    size_t largo_segunda = 0;

    while(primera[largo_primera] != '\0' && largo_primera < cap_primera)
    {
        largo_primera++;
    }
    while(primera[largo_segunda] != '\0' && largo_segunda < cap_segunda)
    {
        largo_segunda++;
    }

    
    char *bloque = calloc((largo_primera + largo_segunda + 1), 1);
    if (bloque == NULL)
    {
        return NULL;
    }

    size_t largo_total = 0;
    for (size_t i = 0; i < largo_primera; i++)
    {
        bloque[largo_total] = primera[i];
        largo_total++;
    }
    for (size_t i = 0; i < largo_segunda; i++)
    {
        bloque[largo_total] = segunda[i];
        largo_total++;
    }
    bloque[largo_total] = '\0';

    return bloque;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL || *puntero_cadena == NULL)
    {
        return;
    }

    free(*puntero_cadena);
    *puntero_cadena = NULL;
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_origen, size_t inicio, size_t cantidad)
{
    if (origen == NULL || capacidad_origen == 0)
    {
        return NULL;
    }

    size_t largo = 0;
    while (largo < capacidad_origen && origen[largo] != '\0')
    {
        largo++;
    }
        
    if (inicio >= largo || cantidad == 0)
    {
        char *cadena_vacia = malloc(1);
        if (cadena_vacia == NULL)
        {
            return NULL;
        }
        cadena_vacia[0] = '\0';
        return cadena_vacia;
    }

    size_t largo_extraccion = (largo - inicio);
    if (largo_extraccion > cantidad)
    {
        largo_extraccion = cantidad;
    }
    

    char *bloque = calloc((largo_extraccion + 1), 1);
    if (bloque == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < largo_extraccion; i++)
    {
        bloque[i] = origen[i + inicio];
    }

    bloque[largo_extraccion] = '\0';
    return bloque;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }
    
    size_t largo = 0;
    while( largo < (capacidad_max - 1) && origen[largo] != '\0')
    {
        largo++;
    }
    
    char *bloque = malloc(largo + 1);
    if (bloque == NULL)
    {
        return NULL;
    }

    size_t i = 0;
    for (; i < largo; i++)
    {
        bloque[i] = origen[(largo - i) - 1];
    }
    bloque[i] = '\0';

    return bloque;
}
