/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdint.h>
#include <stdlib.h>
#include "cadenas.h"

/**
 * @brief Mide una cadena sin inspeccionar más de @p capacidad_max caracteres.
 *
 * @param cadena Cadena a medir (no debe ser NULL).
 * @param capacidad_max Cantidad máxima de caracteres a inspeccionar.
 * @return Cantidad de caracteres antes del '\0', o @p capacidad_max si no se
 *         halló el terminador dentro del rango.
 */

 static size_t longitud_segura(const char *cadena, size_t capacidad_max)
{
    size_t longitud = 0;
    while (longitud < capacidad_max && cadena[longitud] != '\0') {
        ++longitud;
    }
    return longitud;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0) {
        return NULL;
    }
 
    size_t longitud = longitud_segura(origen, capacidad_max);
    if (longitud == SIZE_MAX) {
        return NULL;
    }
 
    char *copia = malloc(longitud + 1);
    if (copia == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < longitud; ++i) {
        copia[i] = origen[i];
    }
    copia[longitud] = '\0';
    return copia;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 || cap_segunda == 0) 
    {
        return NULL;
    }
 
    size_t longitud1 = longitud_segura(primera, cap_primera);
    size_t longitud2 = longitud_segura(segunda, cap_segunda);
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

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL || *puntero_cadena == NULL) 
    {
        return;
    }
    free(*puntero_cadena);
    *puntero_cadena = NULL;
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad)
{
    if (origen == NULL) {
        return NULL;
    }
 
    size_t longitud = longitud_segura(origen, capacidad_max);
    size_t extraidos = 0;
    if (inicio < longitud) {
        extraidos = longitud - inicio;
        if (cantidad < extraidos) {
            extraidos = cantidad;
        }
    }
    if (extraidos == SIZE_MAX) {
        return NULL;
    }
 
    char *subcadena = malloc(extraidos + 1);
    if (subcadena == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < extraidos; ++i) {
        subcadena[i] = origen[inicio + i];
    }
    subcadena[extraidos] = '\0';
    return subcadena;
}
 
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL) {
        return NULL;
    }
 
    size_t longitud = longitud_segura(origen, capacidad_max);
    if (longitud == SIZE_MAX) {
        return NULL;
    }
 
    char *invertida = malloc(longitud + 1);
    if (invertida == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < longitud; ++i) {
        invertida[i] = origen[longitud - 1 - i];
    }
    invertida[longitud] = '\0';
    return invertida;
}