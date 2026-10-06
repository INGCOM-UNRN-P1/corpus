/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include <string.h>
#include "cadenas.h"

static size_t strnlen_segura(const char *s, size_t maxlen)
{
    if (s == NULL) return 0;
    size_t len = 0;
    while (len < maxlen && s[len] != '\0') {
        len++;
    }
    return len;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0) {
        return NULL;
    }

    size_t len = strnlen_segura(origen, capacidad_max);
    char *copia = (char *)malloc((len + 1) * sizeof(char));
    if (copia == NULL) {
        return NULL;
    }

    memcpy(copia, origen, len);
    copia[len] = '\0';

    return copia;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera, const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 || cap_segunda == 0) {
        return NULL;
    }

    size_t len1 = strnlen_segura(primera, cap_primera);
    size_t len2 = strnlen_segura(segunda, cap_segunda);

    char *resultado = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (resultado == NULL) {
        return NULL;
    }

    memcpy(resultado, primera, len1);
    memcpy(resultado + len1, segunda, len2);
    resultado[len1 + len2] = '\0';

    return resultado;
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
    if (origen == NULL || capacidad_max == 0) {
        return NULL;
    }

    size_t len = strnlen_segura(origen, capacidad_max);

    if (inicio >= len) {
        char *vacia = (char *)malloc(1 * sizeof(char));
        if (vacia != NULL) {
            vacia[0] = '\0';
        }
        return vacia;
    }

    size_t disponibles = len - inicio;
    size_t extraer = (cantidad < disponibles) ? cantidad : disponibles;

    char *sub = (char *)malloc((extraer + 1) * sizeof(char));
    if (sub == NULL) {
        return NULL;
    }

    memcpy(sub, origen + inicio, extraer);
    sub[extraer] = '\0';

    return sub;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0) {
        return NULL;
    }

    size_t len = strnlen_segura(origen, capacidad_max);

    char *invertida = (char *)malloc((len + 1) * sizeof(char));
    if (invertida == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        invertida[i] = origen[len - 1 - i];
    }
    invertida[len] = '\0';

    return invertida;
}