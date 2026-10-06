

#include <stdlib.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    if(origen == NULL)
    {
        return NULL;
    }
    const char *inicio = origen;
    while(*inicio != '\0' && isspace((unsigned char)*inicio))
    {
        inicio++;
    }
    if(*inicio == '\0')
    {
        return NULL;
    }
    const char *fin = inicio;
    while(*fin != '\0')
    {
        fin++;
    }
    fin--;
    while(fin > inicio && isspace((unsigned char)*fin))
    {
        fin--;
    }
    size_t largo = (size_t)(fin - inicio + 1);
    char *resultado = (char *)malloc(largo + 1);
    if(resultado == NULL)
    {
        return NULL;
    }
    char *dst = resultado;
    const char *src = inicio;
    while (src <= fin)
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return resultado;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if(origen == NULL)
    {
        return NULL;
    }
    const char *ptr = origen;
    while(*ptr != '\0')
    {
        ptr++;
    }
    size_t largo_origen = (size_t)(ptr - origen);
    if(veces == 0)
    {
        char *vacia = (char *)malloc(1);
        if(vacia != NULL)
        {
            *vacia = '\0';
        }
        return vacia;
    }
    size_t tamaño_total = (largo_origen * veces) + 1;
    char *resultado = (char*)malloc(tamaño_total);
    if(resultado == NULL)
    {
        return NULL;
    }
    char *dst = resultado;
    for(size_t i = 0; i < veces; i++)
    {
        const char *src = origen;
        while(*src != '\0')
        {
            *dst = *src;
            dst++;
            src++;   
        }
    }
    *dst = '\0';
    return resultado;
}
