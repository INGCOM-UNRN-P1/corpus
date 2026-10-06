/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL){
        return NULL;
    }
    
    size_t inicio = 0;
    while (origen[inicio] != '\0' && isspace((unsigned char)origen[inicio])){
        inicio++;
    }
    
    if (origen[inicio] == '\0'){
        return NULL;
    }
    
    size_t fin = strlen(origen) - 1;
    while (fin > inicio && isspace((unsigned char)origen[fin])){
        fin--;
    }

    size_t longitud = fin - inicio + 1;
    char *resultado = (char *)malloc((longitud + 1) * sizeof(char));
    if (resultado == NULL){
        return NULL;
    }
    
    strncpy(resultado, origen + inicio, longitud);
    resultado[longitud] = '\0';

    return resultado;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL){
        return NULL;
    }
    
    if (veces == 0){
        char *vacia = (char *)malloc(1 * sizeof(char));
        if (vacia != NULL){
            vacia[0] = '\0';
        }
        return vacia;
    }
    
    size_t len_origen = strlen(origen);
    size_t len_total = len_origen * veces;
    
    char *resultado = (char *)malloc ((len_total + 1) * sizeof(char));
    if (resultado == NULL){
        return NULL;
    }
    
    resultado[0] = '\0';
    for (size_t i = 0; i < veces; i++){
        strcat(resultado, origen);
    }
    
    return resultado;
}
