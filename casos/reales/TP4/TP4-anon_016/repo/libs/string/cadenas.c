/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    char *resultado = NULL;
    if (origen != NULL && capacidad_max > 0)
    {
        const char *inicio = origen;
        size_t longitud = 0;
         while(longitud < capacidad_max && *inicio != '\0')
        {
            longitud++;
            inicio++;
        }
        resultado = malloc((longitud + 1)* sizeof(*resultado));

        if(resultado != NULL)
        {
            char *destino = resultado;
            const char *fuente = origen;
            size_t copiados = 0;

             while (copiados < longitud)
            {
                *destino = *fuente;
                destino++;
                fuente++;
                copiados++;
            }
           *destino = '\0';
        }
    }
    return resultado;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 || cap_segunda == 0)
    {
        return NULL;
    }

   
    size_t len1 = 0;
    while (len1 < cap_primera && primera[len1] != '\0')
    {
        len1++;
    }

   
    size_t len2 = 0;
    while (len2 < cap_segunda && segunda[len2] != '\0')
    {
        len2++;
    }

   
    char *resultado = (char *)malloc(len1 + len2 + 1);
    if (resultado == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len1; i++)
    {
        resultado[i] = primera[i];
    }


    for (size_t j = 0; j < len2; j++)
    {
        resultado[len1 + j] = segunda[j];
    }

   
    resultado[len1 + len2] = '\0';

    return resultado;
}

void cadena_liberar_segura(char **puntero_cadena)
{
   if (puntero_cadena != NULL && *puntero_cadena != NULL)
   {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
   }
}




 char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    char *resultado = NULL;

    if (origen != NULL)
    {
        const char *recorrido = origen;
        size_t longitud = 0;
        while (longitud < capacidad_max && *recorrido != '\0')
        {
            longitud++;
            recorrido++;
        }

        size_t disponibles = 0;
        if (inicio < longitud)
        {
            disponibles = longitud - inicio;
        }

        size_t extraidos = cantidad;
        if (extraidos > disponibles)
        {
            extraidos = disponibles;
        }

        resultado = malloc((extraidos + 1) * sizeof(*resultado));
        if (resultado != NULL)
        {
            char *destino = resultado;
            const char *fuente = origen + inicio;
            size_t copiados = 0;

            while (copiados < extraidos)
            {
                *destino = *fuente;
                destino++;
                fuente++;
                copiados++;
            }
            *destino = '\0';
        }
    }

    return resultado;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    char *resultado = NULL;

    if (origen != NULL)
    {
        const char *recorrido = origen;
        size_t longitud = 0;
        while (longitud < capacidad_max && *recorrido != '\0')
        {
            longitud++;
            recorrido++;
        }

        resultado = malloc((longitud + 1) * sizeof(*resultado));
        if (resultado != NULL)
        {
            char *destino = resultado;
            const char *fuente = origen + longitud;
            size_t copiados = 0;

            while (copiados < longitud)
            {
                fuente--;
                *destino = *fuente;
                destino++;
                copiados++;
            }
            *destino = '\0';
        }
    }

    return resultado;
}