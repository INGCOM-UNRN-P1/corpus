/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"
bool copiar_con_punteros(const char *origen, size_t capacidad
                        ,char *destino)
{    
    if(destino == NULL || origen == NULL || capacidad == 0 )
    {
        return false;
    }
    
    const char *src = origen;
    char *dst = destino;
    const char *limite = destino + (capacidad - 1);

    while(( dst < limite) && (*src != '\0')) 
    {
        *dst ++ = *src++;
    }
        
    if (*src == '\0')
    {
        *dst = '\0';
        return true;    
    }
    
    else
    {
        *dst = '\0';
        return false;
    }
}





bool concatenar_con_punteros(const char *origen, size_t capacidad
                            , char *destino)
{   
    if(destino == NULL || origen == NULL || capacidad == 0 )
    {
        return false;
    }

    const char *src = origen;
    char *dst = destino;
    const char *limite = destino + (capacidad - 1);
    
    while((dst < limite) && (*dst != '\0'))
    {
        dst++;
    }
    
    if(*dst != '\0')
    {
        return false;
    }

    
    
    while((dst < limite) && (*src != '\0'))
    {   
        *dst++ = *src++;
    }
    
    *dst = '\0';
    
    return (*src == '\0');
}