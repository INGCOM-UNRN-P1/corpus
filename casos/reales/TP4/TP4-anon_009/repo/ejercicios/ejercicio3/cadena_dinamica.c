

#include "cadena_dinamica.h"

char *clonar_cadena(const char *origen)
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
    size_t largo = (size_t)(ptr - origen);
    char *copia = (char *)malloc(largo + 1);
    if(copia == NULL)
    {
        return NULL;
    }
    char *dst = copia;
    const char *src = origen;
    while (*src != '\0')
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return copia;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if(primera == NULL || segunda == NULL)
    {
        return NULL;
    }
    const char *ptr_1 = primera;
    while(*ptr_1 != '\0')
    {
        ptr_1++;
    }
    size_t largo_1 = (size_t)(ptr_1 - primera);
    const char *ptr_2 = segunda;
    while(*ptr_2 != '\0')
    {
        ptr_2++;
    }
    size_t largo_2 = (size_t)(ptr_2 - segunda);
    char *resultado = (char *)malloc(largo_1 + largo_2 + 1);
    if(resultado == NULL)
    {
        return NULL;
    }
    char *destino = resultado;
    const char *origen_1 = primera;
    while(*origen_1 != '\0')
    {
        *destino = *origen_1;
        destino++;
        origen_1++;
    }
    const char *origen_2 = segunda;
    while(origen_2 != '\0')
    {
        *destino = *origen_2;
        destino++;
        origen_2++;
    }
    *destino = '\0';
    return resultado;
}


