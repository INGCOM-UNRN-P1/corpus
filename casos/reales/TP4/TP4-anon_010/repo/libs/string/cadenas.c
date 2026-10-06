/**
 * @file cadenas.c
 * @brief Implementación de la biblioteca libstring.
 */
 
#include <stdlib.h>
#include <string.h>
#include "cadenas.h"
 
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    char *copia = NULL;
 
    if (origen != NULL && capacidad_max > 0) {
        size_t longitud = 0;
        while (longitud < capacidad_max && origen[longitud] != '\0') {
            longitud++;
        }
 
        copia = malloc(longitud + 1);
        if (copia != NULL) {
            memcpy(copia, origen, longitud);
            copia[longitud] = '\0';
        }
    }
    return copia;
}
 
char *cadena_unir_dinamica(const char *primera, size_t cap_primera, const char *segunda, size_t cap_segunda)
{
    char *unida = NULL;
 
    if (primera != NULL && segunda != NULL) {
        size_t longitud1 = 0;
        while (longitud1 < cap_primera && primera[longitud1] != '\0') {
            longitud1++;
        }
 
        size_t longitud2 = 0;
        while (longitud2 < cap_segunda && segunda[longitud2] != '\0') {
            longitud2++;
        }
 
        unida = malloc(longitud1 + longitud2 + 1);
        if (unida != NULL) {
            memcpy(unida, primera, longitud1);
            memcpy(unida + longitud1, segunda, longitud2);
            unida[longitud1 + longitud2] = '\0';
        }
    }
    return unida;
}
 
void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL && *puntero_cadena != NULL) {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}
 
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad)
{
    char *subcadena = NULL;
 
    if (origen != NULL) {
        size_t longitud = 0;
        while (longitud < capacidad_max && origen[longitud] != '\0') {
            longitud++;
        }
 
        size_t copiados = 0;
        if (inicio < longitud) {
            copiados = longitud - inicio;
            if (cantidad < copiados) {
                copiados = cantidad;
            }
        }
 
        subcadena = malloc(copiados + 1);
        if (subcadena != NULL) {
            if (copiados > 0) {
                memcpy(subcadena, origen + inicio, copiados);
            }
            subcadena[copiados] = '\0';
        }
    }
    return subcadena;
}
 
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    char *invertida = NULL;
 
    if (origen != NULL) {
        size_t longitud = 0;
        while (longitud < capacidad_max && origen[longitud] != '\0') {
            longitud++;
        }
 
        invertida = malloc(longitud + 1);
        if (invertida != NULL) {
            for (size_t i = 0; i < longitud; ++i) {
                invertida[i] = origen[longitud - 1 - i];
            }
            invertida[longitud] = '\0';
        }
    }
    return invertida;
}