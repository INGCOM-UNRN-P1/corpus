/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include "cadenas_tp2.h"
#include <stdlib.h>


char *clonar_cadena(const char *origen)
{
    char *nueva_cadena = NULL;
    if (origen != NULL)
    {
        size_t len = 0;
        for (; *(origen + len) != '\0'; len++)
        {
        }
        nueva_cadena = (char *)malloc((len + 1) * sizeof(char));
        if (nueva_cadena != NULL)
        {
            cadena_copiar(nueva_cadena, len + 1, origen);
        }
    }
    return nueva_cadena;
}


char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    char *concatenada = NULL;
    if (primera != NULL && segunda != NULL)
    {
        size_t len_1 = 0;
        size_t len_2 = 0;
        size_t len_total = 0;
        for (; *(primera + len_1) != '\0'; len_1++)
        {
        }
        for (; *(segunda + len_2) != '\0'; len_2++)
        {
        }
        len_total = len_1 + len_2 + 1;
        concatenada = (char *)calloc(len_total, sizeof(char));
        if (concatenada != NULL)
        {
            cadena_copiar(concatenada, len_total, primera);
            cadena_concatenar(concatenada, len_total, segunda);
        }
    }
    return concatenada;
}
