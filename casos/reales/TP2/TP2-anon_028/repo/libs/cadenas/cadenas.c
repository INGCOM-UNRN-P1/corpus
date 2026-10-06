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
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0){
        return 0;
    }
    size_t i = 0;
    while (i < capacidad && cadena[i] != '\0'){
        i++;
    }
    return i;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || origen == NULL || capacidad == 0){
        return false;
    }
    size_t i = 0;
    while (i < capacidad - 1 && origen[i] != '\0'){
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
    return origen[i] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || origen == NULL || capacidad == 0){
        return false;
    }
    size_t len_dest = cadena_longitud(destino, capacidad);
    if (len_dest > capacidad -1){
        return false;
    }
    size_t i = 0;
    while (len_dest + i < capacidad - 1 && origen[i] != '\0'){
        destino[len_dest + i] = origen[i];
        i++;
    }

    destino[len_dest + i] = '\0';
    return origen[i] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0){
        return 0;
    }
    size_t conversiones = 0;
    for (size_t indice = 0; indice < capacidad && cadena[indice] != '\0'; indice++){
        if (islower((unsigned char)cadena[indice])){
            cadena[indice] = (char)toupper((unsigned char)cadena[indice]);
            conversiones++;
        }
    }
    
    return conversiones;
}


bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad){
    if (destino == NULL || capacidad == 0){
        return false;
    }

    if (origen == NULL){
        destino[0] = '\0';
        return false;
    }
    
    size_t len_origen = cadena_longitud(origen, capacidad);
    if (inicio >= len_origen){
        destino[0] = '\0';
        return false;
    }

    size_t i = 0;
    while (i < cantidad && (inicio + i) < len_origen && i < capacidad - 1){
        destino[i] = origen[inicio + i];
        i++;
    }
    destino[i] = '\0';
    return true;
}


bool cadena_entero(char destino[], size_t capacidad, int valor) {
    if (destino == NULL || capacidad == 0) {
        return false;
    }

    char buffer_tmp[64];
    int res = snprintf(buffer_tmp, sizeof(buffer_tmp), "%d", valor);

    if (res < 0) {
        destino[0] = '\0';
        return false;
    }

    size_t len = (size_t)res;

    if (len + 1 > capacidad) {
        destino[capacidad - 1] = '\0';
        return false;
    }

    for (size_t i = 0; i < len; i++) {
        destino[i] = buffer_tmp[i];
    }
    destino[len] = '\0';

    return true;
}