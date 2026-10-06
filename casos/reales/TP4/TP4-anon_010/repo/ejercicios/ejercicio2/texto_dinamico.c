/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include <string.h>
#include "texto_dinamico.h"
 
char *cadena_recortar_espacios(const char *origen)
{
    char *limpia = NULL;
 
    if (origen != NULL) {
        size_t longitud = strlen(origen);
        size_t inicio = 0;
        while (inicio < longitud && origen[inicio] == ' ') {
            inicio++;
        }
 
        if (inicio < longitud) {
            size_t fin = longitud;
            while (origen[fin - 1] == ' ') {
                fin--;
            }
            limpia = cadena_subcadena_dinamica(origen, longitud, inicio, fin - inicio);
        }
    }
    return limpia;
}
 
char *cadena_repetir(const char *origen, size_t veces)
{
    char *repetida = NULL;
 
    if (origen != NULL) {
        size_t longitud = strlen(origen);
 
        repetida = malloc(longitud * veces + 1);
        if (repetida != NULL) {
            for (size_t i = 0; i < veces; ++i) {
                memcpy(repetida + i * longitud, origen, longitud);
            }
            repetida[longitud * veces] = '\0';
        }
    }
    return repetida;
}
