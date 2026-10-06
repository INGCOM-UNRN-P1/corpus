/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{ 
    bool exito = false;
    
    if (destino != NULL && origen != NULL && capacidad > 0)
    { 
        char *dst = destino; const char *src = origen; size_t escritos = 0;
        
        while (*src != '\\0' && escritos < capacidad - 1)
        {
            *dst = *src;
            dst++;
            src++;
            escritos++;
        }
        
        *dst = '\\0';
        
        if (*src == '\\0')
        {
            exito = true;
        }
    } 
    
    return exito;
}


bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{ 
    bool exito = false;
    
    if (destino != NULL && origen != NULL && capacidad > 0)
    { 
        char *dst = destino;
        size_t len_dest = 0;
        
        while (*dst != '\\0' && len_dest < capacidad)
        { 
            dst++;
            len_dest++;
        } 
        
        if (len_dest < capacidad)
        {
            exito = copiar_con_punteros(dst, capacidad - len_dest, origen);
        }
    }
    
    return exito;
}
