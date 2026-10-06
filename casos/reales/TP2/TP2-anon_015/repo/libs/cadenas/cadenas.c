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

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    size_t longitud = 0;

    if (cadena == NULL || capacidad == 0){
        return 0;
    }

    for(size_t i = 0; i < capacidad; i++){
        if (cadena[i] != '\0'){
            longitud++;

        }
        else{
            return longitud;
        }
    }

    return capacidad;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (origen == NULL || capacidad == 0 || destino == NULL){
        return 0;
    }
    for(size_t i = 0; i < capacidad; i++){
        if (origen[i] == '\0'){
            destino[i] = origen[i];
            return true;
        }
        else{
            destino[i] = origen[i];
        }
    }
    destino[capacidad - 1] = '\0';
    return false;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    size_t fin_destino = 0; 


    if (origen == NULL || destino == NULL || capacidad == 0){
        return false;
    }
    for(size_t i = 0; i < capacidad; i++){
        if (destino[i] == '\0'){
            fin_destino = i;
                for (size_t i = fin_destino; i < capacidad; i++){
                    if(origen[i - fin_destino] == '\0'){
                        destino[i] = '\0';
                        return true;
                        
                    }
                    else{
                        destino[i] = origen[i - fin_destino];
                    }

                }
            destino[capacidad - 1] = '\0';
            return false;
        }
    }
    return false;
}


size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t contador = 0;
    if (cadena == NULL || capacidad == 0){
        return 0;
    }
    for(size_t i = 0; i < capacidad; i++){
        if(isalpha(cadena[i]) && cadena[i] != toupper(cadena[i])){
            cadena[i] = toupper(cadena[i]);
            contador++;
        }
        else if(cadena[i] == '\0'){
            return contador;
        }
    }
    return 0;
}



bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad){
    if (capacidad == 0 || inicio > cantidad){
        return false;
    } 
    for(size_t i = inicio; i < cantidad; i++){
        destino[i] = origen[i];

    }
    return false;
}

