/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"

 // == TP2 ==

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    if(cadena == NULL || capacidad == 0){
        return 0;
    }

    for(size_t i = 0; i < capacidad; i++){
        if(cadena[i] == '\0'){
            return i;
        }
    }

    return capacidad;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if(destino == NULL || origen == NULL || capacidad == 0){
        return false;
    }

    for(size_t i = 0; i < capacidad; i++){
        if (origen[i] == '\0') {
            destino[i] = '\0';
            return true;
        }

        if (i == capacidad - 1) {
            destino[i] = '\0';
            return false;
        }

        destino[i] = origen[i];
    }

    return false;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if(destino == NULL || origen == NULL || capacidad == 0){
        return false;
    }

    size_t longitud = cadena_longitud(destino, capacidad);

    if(longitud == capacidad){
        return false;
    }

    for(size_t i = 0; i < capacidad; i++){

        if (origen[i] == '\0') {
            destino[longitud] = '\0';
            return true;
        }

        if (longitud == capacidad - 1) {
            destino[longitud] = '\0';
            return false;
        }

        destino[longitud] = origen[i];
        longitud++;
    }
    
    return false;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if(cadena == NULL || capacidad == 0){
        return 0;
    }

    size_t cantidad = 0;

    for(size_t i = 0; i < capacidad; i++){
        if(cadena[i] == '\0'){
            return cantidad;
        }

        if('a' <= cadena[i] && cadena[i] <= 'z'){
            cadena[i] -= ('a' - 'A');
            cantidad++;
        }
    }

    return cantidad;
}

bool cadena_subcadena(char destino[],
                      size_t capacidad,
                      const char origen[],
                      size_t inicio,
                      size_t cantidad)
{
    if (destino == NULL || origen == NULL || capacidad == 0) {
        return false;
    }

    size_t posicion = 0;

    while (posicion < inicio && origen[posicion] != '\0') {
        posicion++;
    }

    if (origen[posicion] == '\0') {
        destino[0] = '\0';
        return true;
    }

    size_t copiados = 0;

    while (copiados < cantidad && origen[posicion] != '\0') {
        if (copiados == capacidad - 1) {
            destino[copiados] = '\0';
            return false;
        }

        destino[copiados] = origen[posicion];
        copiados++;
        posicion++;
    }

    destino[copiados] = '\0';

    return true;
}

 // ^^^ TP2 ^^^

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud = cadena_longitud(origen, capacidad_max);

    char *copia = malloc(longitud + 1);

    if (copia == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++)
    {
        copia[i] = origen[i];
    }

    copia[longitud] = '\0';

    return copia;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 || cap_segunda == 0)
    {
        return NULL;
    }

    size_t longitud_primera = cadena_longitud(primera, cap_primera);
    size_t longitud_segunda = cadena_longitud(segunda, cap_segunda);
    size_t longitud_total = longitud_primera + longitud_segunda;

    char *nuevo_bloque = malloc(longitud_total + 1);

    if(nuevo_bloque == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud_primera; i++)
    {
        nuevo_bloque[i] = primera[i];
    }

    for (size_t i = 0; i < longitud_segunda; i++)
    {
        nuevo_bloque[longitud_primera + i] = segunda[i];
    }

    nuevo_bloque[longitud_total] = '\0';

    return nuevo_bloque;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if(puntero_cadena == NULL || *puntero_cadena == NULL)
    {
        return;
    }

    free(*puntero_cadena);
    *puntero_cadena = NULL;
}



char *cadena_subcadena_dinamica(const char *origen, 
                                 size_t capacidad_max, 
                                 size_t inicio, 
                                 size_t cantidad)
{
    if(origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t extraidos = 0;
    size_t disponibles = 0;
    size_t longitud = cadena_longitud(origen, capacidad_max);

    if(inicio < longitud)
    {
        disponibles = longitud - inicio;
        extraidos = (cantidad < disponibles) ? cantidad : disponibles;
    }

    char *extraccion = malloc(extraidos + 1);

    if(extraccion == NULL)
    {
        return NULL;
    } 

    for(size_t i = 0; i < extraidos; i++)
    {
        extraccion[i] = origen[inicio + i];
    }

    extraccion[extraidos] = '\0';

    return extraccion;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if(origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud = cadena_longitud(origen, capacidad_max);

    char *cadena_invertida = malloc(longitud + 1);
    if(cadena_invertida == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < longitud; i++)
    {
        cadena_invertida[i] = origen[longitud - 1 - i];
    }

    cadena_invertida[longitud] = '\0';

    return cadena_invertida;
}