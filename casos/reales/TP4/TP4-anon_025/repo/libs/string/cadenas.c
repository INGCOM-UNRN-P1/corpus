/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"

static size_t medir_seguro(const char *cadena, size_t max)
{
    size_t i = 0;
    while (i < max && cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    
    if (origen == NULL || capacidad_max == 0) return NULL;
    size_t len = medir_seguro(origen, capacidad_max);
    char *nueva = (char *)malloc(len + 1);
    if (nueva != NULL)
    {
        for (size_t i = 0; i < len; i++)
        {
            nueva[i] = origen[i];
        }
        nueva[len] = '\0';
    }
    return nueva;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    
    if (primera == NULL || segunda == NULL) return NULL;

    size_t len1 = medir_seguro(primera, cap_primera);
    size_t len2 = medir_seguro(segunda, cap_segunda);

    char *nueva = (char *)malloc(len1 + len2 + 1);
    if (nueva != NULL)
    {
        for (size_t i = 0; i < len1; i++) nueva[i] = primera[i];
        for (size_t i = 0; i < len2; i++) nueva[len1 + i] = segunda[i];
        nueva[len1 + len2] = '\0';
    }
    return nueva;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    
    if (puntero_cadena != NULL && *puntero_cadena != NULL)
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}



 char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad)
 {
    if (origen == NULL) return NULL;
    size_t len = medir_seguro(origen, capacidad_max);
    if (inicio >= len)
    {
        char *vacia = (char *)malloc(1);
        if (vacia) vacia[0] = '\0';
        return vacia;
    }

    size_t extraible = len - inicio;
    size_t final_cant = (cantidad < extraible) ? cantidad : extraible;

    char *nueva = (char *)malloc(final_cant + 1);
    if (nueva != NULL)
    {
        for (size_t i = 0; i < final_cant; i++)
        {
            nueva[i] = origen[inicio + i];
        }
        nueva[final_cant] = '\0';
    }
    return nueva;
 }

 char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
 {
    if (origen == NULL) return NULL;
    size_t len = medir_seguro(origen, capacidad_max);
    char *nueva = (char *)malloc(len + 1);
    if (nueva != NULL)
    {
        for (size_t i = 0; i < len; i++)
        {
            nueva[i] = origen[len - 1 - i];
        }
        nueva[len] = '\0';
    }
    return nueva;
 }