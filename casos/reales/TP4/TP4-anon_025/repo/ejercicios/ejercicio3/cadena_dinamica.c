/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include <stdlib.h>
#include <string.h>


char *clonar_cadena(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t longitud = strlen(origen);
    char *clon = (char *)malloc((longitud + 1) * sizeof(char));
    if (clon != NULL)
    {
        strcpy(clon, origen);
    }
    return clon;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }
    size_t len1 = strlen(primera);
    size_t len2 = strlen(segunda);
    char *unida = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (unida != NULL)
    {
        strcpy(unida, primera);
        strcat(unida, segunda);
    }
    return unida;
}