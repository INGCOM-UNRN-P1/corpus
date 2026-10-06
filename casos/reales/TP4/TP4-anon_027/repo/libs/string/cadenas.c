/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"
#include <string.h>

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0) 
    {
        return NULL;
    }

    size_t longitud = 0;
    
    while ((longitud < capacidad_max) && (origen[longitud] != '\0')) 
    {
        longitud++;
    }

    char *destino = malloc((longitud + 1) * sizeof(char));
    
    if (destino == NULL) 
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++) 
    {
        destino[i] = origen[i];
    }
    
    destino[longitud] = '\0';

    return destino;
}




char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    // Validación de argumentos de entrada
    if (primera == NULL || segunda == NULL) 
    {
        return NULL;
    }

    size_t len1 = 0;
    
    while ((len1 < cap_primera) && (primera[len1] != '\0')) 
    {
        len1++;
    }
    
    size_t len2 = 0;

    while ((len2 < cap_segunda) && (segunda[len2] != '\0')) 
    {
        len2++;
    }

    size_t total_len = len1 + len2;
    
    char *resultado = malloc((total_len + 1) * sizeof(char));
    
    if (resultado == NULL) 
    {
        return NULL;
    }

    for (size_t i = 0; i < len1; i++) 
    {
        resultado[i] = primera[i];
    }

    for (size_t j = 0; j < len2; j++) 
    {
        resultado[len1 + j] = segunda[j];
    }

    resultado[total_len] = '\0';

    return resultado;
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



 char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, 
 size_t inicio, size_t cantidad)
 {
    if ((origen == NULL) || (capacidad_max == 0)) 
    {
        return NULL;
    }

    size_t longitud_origen = 0;

    while ((longitud_origen < capacidad_max) && 
    (origen[longitud_origen] != '\0')) 
    {
        longitud_origen++;
    }

    if (inicio >= longitud_origen) 
    {
        char *vacia = malloc(1 * sizeof(char));

        if (vacia == NULL) 
        {
            return NULL;
        }
        vacia[0] = '\0';
        return vacia;
    }

    size_t disponibles = (longitud_origen - inicio);
    size_t longitud_extraida = (cantidad < disponibles) 
    ? cantidad : disponibles;

    char *subcadena = malloc((longitud_extraida + 1) * sizeof(char));
    if (subcadena == NULL) 
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud_extraida; i++) 
    {
        subcadena[i] = origen[inicio + i];
    }

    subcadena[longitud_extraida] = '\0';

    return subcadena;
 }




char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL) 
    {
        return NULL;
    }

    size_t longitud = 0;

    while ((longitud < capacidad_max) && (origen[longitud] != '\0')) 
    {
        longitud++;
    }

    char *invertida = malloc((longitud + 1) * sizeof(char));
    
    if (invertida == NULL) 
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++) 
    {
        invertida[i] = origen[longitud - 1 - i];
    }

    invertida[longitud] = '\0';

    return invertida;
}