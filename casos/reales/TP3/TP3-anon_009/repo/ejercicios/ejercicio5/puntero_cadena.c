

#include "puntero_cadena.h"



bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if(destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }
    char *dst = destino;
    const char *org = origen;
    size_t  copiados = 0;
    while(*org != '\0' && copiados < (capacidad - 1))
    {
        *dst = *org;
        dst++;
        org++;
        copiados++;
    }
    *dst = '\0';
    return(*org == '\0');
}

bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    if(destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }
    char *dst = destino;
    const char *org = origen;
    size_t ocupado = 0;
    while(*dst != '\0' && ocupado < capacidad)
    {
        dst++;
        ocupado++;
    }
    if(ocupado >= capacidad)
    {
        return false;
    }
    size_t restantes = capacidad - ocupado;
    size_t copiados = 0;
    while(*org != '\0' && copiados < (restantes - 1))
    {
        *dst = *org;
        dst++;
        org++;
        copiados++;
    }
    *dst = '\0';
    return(*org == '\0');
}