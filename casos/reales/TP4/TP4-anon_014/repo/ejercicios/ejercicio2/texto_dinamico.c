/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    char *recortada = recortar_espacios_dinamico(origen);
    if (recortada != NULL && recortada[0] == '\0')
    {
        cadena_liberar_segura(&recortada);
    }
    return recortada;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t longitud = strlen(origen);
    char *repetida = (char *)malloc(longitud * veces + 1);
    if (repetida == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < veces; i++)
    {
        memcpy(repetida + i * longitud, origen, longitud);
    }
    repetida[longitud * veces] = '\0';
    return repetida;
}

char *recortar_espacios_dinamico(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t inicio = 0;
    while (origen[inicio] == ' ')
    {
        inicio++;
    }
    size_t fin = strlen(origen);
    while (fin > inicio && origen[fin - 1] == ' ')
    {
        fin--;
    }
    return cadena_subcadena_dinamica(origen, fin + 1, inicio, fin - inicio);
}

char *normalizar_mayusculas_dinamico(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t longitud = strlen(origen);
    char *mayusculas = cadena_duplicar_segura(origen, longitud + 1);
    if (mayusculas == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < longitud; i++)
    {
        mayusculas[i] = (char)toupper((unsigned char)mayusculas[i]);
    }
    return mayusculas;
}
