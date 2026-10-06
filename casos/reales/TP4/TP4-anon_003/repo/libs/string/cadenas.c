/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0){
        return NULL;
    }
    size_t longitud = 0; 
    while(longitud < capacidad_max && origen [longitud] != '\0'){
        longitud ++;
    }

    char *destino = malloc(longitud +1);
    if ( destino== NULL){
    return NULL;
    } else {
    
        for ( int i = 0; i < longitud + 1 ; i ++ ){
            destino [i] = origen [i];

        }
        return destino;
    }

}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda== NULL || cap_primera == 0 || cap_segunda == 0){
        return NULL;
    }

    size_t longitud_1 = 0;
    size_t longitud_2 = 0;

    while (longitud_1 < cap_primera && primera[longitud_1] != '\0') {
    longitud_1++;
    }

    while (longitud_2 < cap_segunda && segunda[longitud_2] != '\0') {
    longitud_2++;
    }

    char *destino = malloc(longitud_1 + longitud_2 +1);
    if (destino == NULL){
        return NULL;
    }
    size_t i = 0;
    while(i < longitud_1){
        destino [i] = primera[i];
        i++;
    }

    size_t a = 0;
    while (a < longitud_2){
        destino [i] = segunda[a];
        a++;
        i++;
    }
    destino[i] = '\0';

    return destino;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL || *puntero_cadena == NULL){
        return;
    }

    free(*puntero_cadena);
    *puntero_cadena = NULL;
    return;
}


char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad){
if (origen == NULL|| capacidad_max ==0){
    return NULL;
}

size_t longitud_origen = 0;

while (longitud_origen < capacidad_max && origen [longitud_origen] != '\0'){
longitud_origen ++;
}

if(inicio > longitud_origen){
    char *destino = malloc(1);
    if (destino== NULL){
        return NULL;
    }
    destino[0] = "";
    return destino;
}
size_t restante = longitud_origen - inicio; 
size_t longitud_extraida = cantidad;

char *destino = malloc(longitud_extraida + 1);
if (destino == NULL) {
    return NULL; 
}
size_t i = 0;
while (i < longitud_extraida) { 
    destino[i] = origen[inicio + i]; 
    i++; 
}

destino[i] = '\0';

return destino;

}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max){
if (origen == NULL || capacidad_max == 0) {
    return NULL;
}
size_t longitud = 0;

while (longitud < capacidad_max && origen[longitud] != '\0') {
    longitud++;
}

char *destino = malloc(longitud + 1);

if (destino == NULL) {
    return NULL;
}

size_t i = 0;

while(i < longitud){
    destino [i] = origen[longitud - 1 - i];
    i++;
}
destino[i] = '\0'; 
return destino; 
}




