/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdint>
#include <stdlib.h>
#include "texto_dinamico.h"

/**
 * @brief Cuenta los caracteres de una cadena terminada en '\0'.
 *
 * @param cadena Cadena a medir (no debe ser NULL).
 * @return Cantidad de caracteres antes del '\0'.
 */
 static size_t longitud_cadena(const char *cadena)
{
    size_t longitud = 0;
    while (cadena[longitud] != '\0') 
    {
        ++longitud;
    }
    return longitud;
}

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL) 
    {
        return NULL;
    }
 
    size_t longitud = longitud_cadena(origen);
    size_t inicio = 0;
    while (inicio < longitud && origen[inicio] == ' ') 
    {
        ++inicio;
    }
    if (inicio == longitud) 
    {
        return NULL; 
    }
 
    size_t fin = longitud; 
    while (origen[fin - 1] == ' ') 
    {
        --fin;
    }
 
    return cadena_subcadena_dinamica(origen, SIZE_MAX, inicio, fin - inicio);
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL) 
    {
        return NULL;
    }
 
    size_t longitud = longitud_cadena(origen);
    if (longitud != 0 && veces > (SIZE_MAX - 1) / longitud) 
    {
        return NULL;
    }
 
    size_t total = longitud * veces;
    char *repetida = malloc(total + 1);
    if (repetida == NULL) 
    {
        return NULL;
    }
    for (size_t vuelta = 0; vuelta < veces; ++vuelta) 
    {
        for (size_t i = 0; i < longitud; ++i) 
        {
            repetida[vuelta * longitud + i] = origen[i];
        }
    }
    repetida[total] = '\0';
    return repetida;
}
