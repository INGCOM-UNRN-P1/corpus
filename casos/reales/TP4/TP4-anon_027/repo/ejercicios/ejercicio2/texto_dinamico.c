/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include "texto_dinamico.h"
#include <string.h>
#include <ctype.h>

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL) 
    {
        return NULL;
    }

    const char *inicio = origen;
    
    while ((*inicio != '\0') && (isspace((unsigned char)*inicio))) 
    {
        inicio++;
    }

    if (*inicio == '\0')
    {
        return NULL;
    }

    const char *fin = origen + strlen(origen) - 1;

    while ((fin > inicio) && (isspace((unsigned char)*fin))) 
    {
        fin--;
    }

    size_t longitud = (size_t)(fin - inicio + 1);

    char *resultado = (char *)malloc(longitud + 1);
    if (resultado == NULL) 
    {
        return NULL;
    }

    memcpy(resultado, inicio, longitud);
    resultado[longitud] = '\0';
    return resultado;
}






char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL) 
    {
        return NULL;
    }

    if (veces == 0) 
    {
        char *vacia = (char *)malloc(1);
        
        if (vacia == NULL) 
        {
            return NULL;
        }
        
        vacia[0] = '\0';
        return vacia;
    }

    size_t len = strlen(origen);

    if ((len > 0) && (veces > (SIZE_MAX / len))) 
    {
        return NULL;
    }

    size_t longitud_total = len * veces;

    if (longitud_total == SIZE_MAX) 
    {
        return NULL;
    }

    char *resultado = (char *)malloc(longitud_total + 1);
    
    if (resultado == NULL) 
    {
        return NULL;
    }

    char *p = resultado;
    
    for (size_t i = 0; i < veces; i++) 
    {
        memcpy(p, origen, len);
        p += len;
    }

    *p = '\0';

    return resultado;
}
