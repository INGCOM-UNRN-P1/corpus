/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if (origen == NULL || cantidad == 0){
        return NULL;
    }
int *destino = malloc(cantidad * sizeof(int));
if (destino == NULL ){
    return NULL;

}
for (int i = 0; i < cantidad ; i++){

    destino [i] = origen [i];

}
return destino;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    if(origen == NULL || cantidad_origen == 0 || cantidad_pares == NULL){
        return NULL;
    }
 
    size_t par_encontrado = 0;
    for (size_t i = 0 ; i < cantidad_origen; i++){
        if (origen [i] %2 == 0){
            par_encontrado ++;
        }
    }
    if(par_encontrado == 0){
        return NULL;
    }

    int *destino = malloc(par_encontrado*sizeof(int));
    if (destino == NULL){
        return NULL;
    }
    size_t a = 0;
    for (size_t i = 0 ; i < cantidad_origen ; i++){
        if(origen [i] %2 ==0){
            destino [a] = origen [i];
            a++;
        }
    }
    *cantidad_pares = par_encontrado;
    return destino;

}
