/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include <stdlib.h>
#include <string.h>

char* clonar_cadena(const char *origen)
{
    if (origen == NULL) 
    {
        return NULL;
    }
    
    size_t longitud = strlen(origen);

    char *copia = (char *)malloc(longitud + 1);
    
    if (copia == NULL) 
    {
        return NULL;
    }

    memcpy(copia, origen, longitud + 1);

    return copia;
}


char* unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL) 
    {
        return NULL;
    }
    
    size_t len1 = strlen(primera);
    size_t len2 = strlen(segunda);
    
    char *resultado = (char *)malloc(len1 + len2 + 1);
    
    if (resultado == NULL) 
    {
        return NULL;
    }

    memcpy(resultado, primera, len1);
    memcpy(resultado + len1, segunda, len2 + 1);

    return resultado;
}