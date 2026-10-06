/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include <string.h>
#include <stdlib.h>


char *clonar_cadena(const char *origen)
{
    if (origen == NULL) {
        return NULL;
    }

    size_t longitud = strlen(origen);
    char *copia = (char *)malloc((longitud + 1) * sizeof(char));
    if (copia == NULL) {
        return NULL;
    }

    strcpy(copia, origen);
    return copia;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL) {
        return NULL;
    }

    size_t len1 = strlen(primera);
    size_t len2 = strlen(segunda);

    char *resultado = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (resultado == NULL) {
        return NULL;
    }

    strcpy(resultado, primera);
    strcat(resultado, segunda);

    return resultado;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL && *puntero_cadena != NULL) {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}