/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include <stdint.h>
#include <stdlib.h>
#include "cadena_dinamica.h"
 
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
 
char *clonar_cadena(const char *origen)
{
    if (origen == NULL) 
    {
        return NULL;
    }
 
    size_t longitud = longitud_cadena(origen);
    if (longitud == SIZE_MAX) 
    {
        return NULL;
    }
 
    char *clon = malloc(longitud + 1);
    if (clon == NULL) 
    {
        return NULL;
    }
    for (size_t i = 0; i < longitud; ++i) 
    {
        clon[i] = origen[i];
    }
    clon[longitud] = '\0';
    return clon;
}
 
char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL) 
    {
        return NULL;
    }
 
    size_t longitud1 = longitud_cadena(primera);
    size_t longitud2 = longitud_cadena(segunda);
    if (longitud1 > SIZE_MAX - 1 - longitud2) 
    {
        return NULL;
    }
 
    char *unida = malloc(longitud1 + longitud2 + 1);
    if (unida == NULL) 
    {
        return NULL;
    }
    for (size_t i = 0; i < longitud1; ++i) 
    {
        unida[i] = primera[i];
    }
    for (size_t i = 0; i < longitud2; ++i) 
    {
        unida[longitud1 + i] = segunda[i];
    }
    unida[longitud1 + longitud2] = '\0';
    return unida;
}