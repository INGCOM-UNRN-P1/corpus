/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if(origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }
    const char *ptr_origen = origen;
    size_t largo = 0;
    while(largo < capacidad_max && *ptr_origen != '\0')
    {
        largo++;
        ptr_origen++;
    }
    char *duplicado = (char *)malloc((largo + 1) * sizeof(char));
    if(duplicado == NULL)
    {
        return NULL;
    }
    char *ptr_destino = duplicado;
    ptr_origen = origen;
    for(size_t i = 0; i < largo; i++)
    {
        *ptr_destino = *ptr_origen;
        ptr_destino++;
        ptr_origen++;
    }
    *ptr_destino = '\0';
    return duplicado;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if(primera == NULL || cap_primera == 0 || segunda == NULL || cap_segunda == 0)
    {
        return NULL;
    }
    const char *ptr_origen = primera;
    size_t lar_primera = 0;
    while(lar_primera < cap_primera && *ptr_origen != '\0')
    {
        lar_primera++;
        ptr_origen++;
    }
    ptr_origen = segunda;
    size_t lar_segunda = 0;
    while (lar_segunda < cap_segunda && *ptr_origen != '\0')
    {
        lar_segunda++;
        ptr_origen++;
    }
    size_t total_bytes = lar_primera + lar_segunda + 1;
    char *resultado = (char *)malloc(total_bytes + sizeof(char));
    if(resultado == NULL)
    {
        return NULL;
    }
    char *ptr_destino = resultado;
    ptr_origen = primera;
    for(size_t i = 0; i < lar_primera; i++)
    {
        *ptr_destino = *ptr_origen;
        ptr_destino++;
        ptr_origen++;
    }
    ptr_origen = segunda;
    for(size_t i = 0; i < lar_segunda; i++)
    {
        *ptr_destino = *ptr_origen;
        ptr_origen++;
        ptr_destino++;
    }
    *ptr_destino = '\0';
    return resultado;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if( puntero_cadena ==  NULL || *puntero_cadena == NULL)
    {
        return;
    }
    free(*puntero_cadena);
    *puntero_cadena = NULL;
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    if(origen == NULL)
    {
        return  NULL;
    }
    const char *ptr_origen = origen;
    size_t largo_origen = 0;
    while(largo_origen < capacidad_max && *ptr_origen != '\0')
    {
        largo_origen++;
        ptr_origen++;
    }
    size_t inicio_real = inicio;
    if(inicio_real > largo_origen)
    {
        inicio_real = largo_origen;
    }
    size_t disponibles = largo_origen - inicio_real;
    size_t copiar = (cantidad < disponibles) ? cantidad : disponibles;
    char *subcadena = (char *)malloc((copiar + 1) * sizeof(char));
    if(subcadena == NULL)
    {
        return NULL;
    }
    ptr_origen = origen + inicio_real;
    char *ptr_destino = subcadena;
    for(size_t i = 0; i < copiar; i++)
    {
        *ptr_destino = *ptr_origen;
        ptr_destino++;
        ptr_origen++;
    }
    *ptr_destino = '\0';
    return subcadena;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if(origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }
    const char *ptr_origen = origen;
    size_t largo = 0;
    while(largo < capacidad_max && *ptr_origen != '\0')
    {
        largo++;
        ptr_origen++;
    }
    char *invertido = (char*)malloc((largo +1) * sizeof(char));
    if(invertido == NULL)
    {
        return NULL;
    }
    ptr_origen = origen + largo - 1;
    char *ptr_destino = invertido;
    for(size_t i = 0; i < largo; i++)
    {
        *ptr_destino = *ptr_origen;
        ptr_destino++;
        ptr_origen--;
    }
    *ptr_destino = '\0';
    return invertido;
}