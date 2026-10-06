/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include <stdlib.h>
#include <string.h>
#include "cadena_dinamica.h"
 
char *clonar_cadena(const char *origen)
{
    char *copia = NULL;
 
    if (origen != NULL) {
        size_t longitud = strlen(origen);
 
        copia = malloc(longitud + 1);
        if (copia != NULL) {
            memcpy(copia, origen, longitud + 1);
        }
    }
    return copia;
}
 
char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    char *unida = NULL;
 
    if (primera != NULL && segunda != NULL) {
        size_t longitud1 = strlen(primera);
        size_t longitud2 = strlen(segunda);
 
        unida = malloc(longitud1 + longitud2 + 1);
        if (unida != NULL) {
            memcpy(unida, primera, longitud1);
            memcpy(unida + longitud1, segunda, longitud2 + 1);
        }
    }
    return unida;
}