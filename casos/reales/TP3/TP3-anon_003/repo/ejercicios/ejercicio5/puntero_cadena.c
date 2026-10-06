/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 *@brief copiar_con_punteros copia de un puntero origen .
 *      Si no entra completa, se copia hasta capacidad -1 y devuelve false
 *      si entra completa, devuelve true
 * @pre destino dene ser valido
 * @post si destino origen es null, devuelve false, 
 *       si el copiado es trunco, devuelve false
 *       si el; copiado se realizac ompleto devuevle true
 * 
 * 
 * 
 * @brief concatenar_con_punteros 
 *        avanza un puntero hasta final de destino y copia ahi una cadena origen
 * @pre origen y destino no deben ser null y deben contener temrminador seguro \0
 * @post si el origen o dest es null, devuelve false
 *       si la cadena nmo se pudo concatenar, devuelve false
 *          si se pudo concatenar ok, devuelve true.         
 * 
 * 
 * 
 * 
 * */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen){
if (destino == NULL || capacidad == 0 || origen == NULL){
    return false;
}
char *dst = destino;
const char *src = origen;
bool copiado_correcto = false;
if (strlen(origen) + 1 <= capacidad){
    while (*src != '\0'){
        *dst = *src;
        dst++;
        src ++;
    }
    *dst = '\0';
    copiado_correcto = true;
    return copiado_correcto;
}else{
    int i = 0;
    while(i < capacidad - 1){
        *dst = *src;
        dst++;
        src++;
        i++;
    }
    *dst = '\0';
    return copiado_correcto;
}
}


bool concatenar_con_punteros( char *destino, size_t capacidad, const char *origen){
if (destino == NULL || capacidad == 0 || origen == NULL) {
    return false;
}
char *dst = destino;
while (*dst != '\0'){
    dst++;
}
char *src = origen;
size_t largo_destino = strlen(destino);
size_t largo_origen = strlen(origen);
if (capacidad >= strlen(origen) + strlen(destino) + 1){
    while (*src != '\0'){
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return true;
}else {
    size_t i = 0;

    while (i < capacidad - largo_destino - 1 && *src != '\0'){
        *dst = *src;
        dst++;
        src++;
        i++;
    }

    *dst = '\0';
    return false;
}

}
