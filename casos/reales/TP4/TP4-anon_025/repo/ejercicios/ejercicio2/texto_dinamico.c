/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include <string.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    
    if (origen == NULL)
    {
        return NULL;
    }
    size_t inicio = 0;
    while (origen[inicio] == ' ' || origen[inicio] == '\t' || origen[inicio] == '\n' || origen[inicio] == '\r')
    {
        inicio ++;
    }
    if (origen[inicio] == '\0')
    {
        return NULL;
    }
    size_t fin = strlen(origen) - 1;
    while (fin > inicio && (origen[fin] == ' ' || origen[fin] == '\t' || origen[fin] == '\n' || origen[fin] == '\r'))
    {
        fin--;
    }
    size_t longitud_nueva = fin - inicio + 1;
    char *limpio = (char *)malloc((longitud_nueva + 1) * sizeof(char));

    if (limpio == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < longitud_nueva; i++)
    {
        limpio[i] = origen[inicio + i];
    }
    limpio[longitud_nueva] = '\0';
    return limpio;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    
    if (origen == NULL)
    {
        return NULL;
    }

    size_t longitud_origen = strlen(origen);
    size_t longitud_total = longitud_origen * veces;
    char * repetida = (char *)malloc((longitud_total + 1) * sizeof(char));
    if (repetida == NULL)
    {
        return NULL;
    }
    size_t indice_actual = 0;
    for (size_t i = 0; i < veces; i++)
    {
        for (size_t j = 0; j < longitud_origen; j++)
        {
            repetida[indice_actual] = origen[j];
            indice_actual++;
        }
    }
    repetida[longitud_total] = '\0';
    return repetida;
}
