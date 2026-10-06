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
    size_t contador_caracteres = 0;
    for (size_t i = 0 ; i < capacidad ; i++){
        if (cadena [i] == '\0'){
            return contador_caracteres;
        }
        contador_caracteres ++;
    }
return contador_caracteres;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0 || origen == NULL) {
        return false;
    }

    if (strlen(origen) + 1 <= capacidad) {

        size_t i;

        for (i = 0; origen[i] != '\0'; i++) {
            destino[i] = origen[i];
        }

        destino[i] = '\0';

        return true;

    } else {

        size_t i;

        for (i = 0; i < capacidad - 1; i++) {
            destino[i] = origen[i];
        }

        destino[i] = '\0';

        return false;
    }
}
        

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0 || origen == NULL) {
        return false;
    }
    size_t i = 0;
    while (destino[i]!= '\0'){
        i++;
    }

    if (strlen (origen) + 1 <= capacidad - i ){
        size_t a;
        for (a = 0 ; origen [a] != '\0' ; a++){
            destino [i] = origen [a];
            i++;
        }   
        destino [i] = '\0';
        return true;

    } else{
        size_t a;
        for (a = 0 ; i< capacidad -1  && origen[a] != '\0' ; a++){
        destino [i] = origen [a];
        i++;
        }
        destino [i]= '\0';
        return false;
    }


    
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
   if (cadena == NULL || capacidad ==0){
    return 0;
   }
   int i = 0;
   while (cadena [i]!= '\0'){
        if (cadena [i] >='a' && cadena[i]<='z'){
            cadena [i] = cadena [i] -32;
        }
        i++;
   }
   return i;
    
}

bool cadena_subcadena(char destino[], size_t capacidad, 
                    const char origen[], size_t inicio, size_t cantidad){

    if (destino == NULL || origen == NULL || capacidad == 0){
        return false;
    }
    
    size_t longitud_cadena_original = strlen(origen);

    if (inicio >= longitud_cadena_original){
        destino [0] = '\0';
        return true;
    }
    
    if (cantidad > longitud_cadena_original){
        cantidad = longitud_cadena_original - inicio;
    }
    if (cantidad>capacidad-1){
        cantidad = capacidad -1;
    }   
    size_t i;
    for (i=0 ; i < cantidad ;i++){
        destino [i] = origen[inicio + i];
    }
    destino [i] = '\0';
    return true;
}




