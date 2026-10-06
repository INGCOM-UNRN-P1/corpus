/**
 * @file cadenas.c
 * @brief Esqueleto de implementación para la biblioteca libcadenas.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "cadenas.h"

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

