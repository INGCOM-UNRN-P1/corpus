/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0){
        return NULL;
    }
    int *bloque_memoria = calloc(cantidad, sizeof(int));
    if(bloque_memoria == NULL){
        return NULL;
    }
    return bloque_memoria;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if(puntero_bloque == NULL || *puntero_bloque == NULL){
        return;
    }

    free(*puntero_bloque);
    *puntero_bloque = NULL;
    return;

}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if(nueva_cantidad == 0){
        free(bloque);
        return NULL;
    }
    int bloque_realloc = realloc(bloque, nueva_cantidad * sizeof(int));
    if(bloque_realloc == NULL){
        return NULL;
    }
    return bloque_realloc;

}
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                               const int *segundo, size_t cant_segundo){

if(primero == NULL || segundo == NULL){
    return NULL;

}

size_t largo_tot = cant_primero + cant_segundo;
if (largo_tot ==0){
    return NULL;
}


int *nuevo_bloque = malloc(largo_tot *sizeof(int));

if(nuevo_bloque ==NULL){
    return NULL;
}
int i;
int a;
for(i = 0; i < cant_primero ; i++){
    nuevo_bloque[i] = primero[i]; 
}

for (a = 0 ; a < cant_segundo; a++){
    nuevo_bloque [i] = segundo [a];
    i++;
}

return nuevo_bloque;


}


bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor){

    if (puntero_bloque == NULL || cantidad == 0){
        return false;
    }
   size_t nueva_cantidad = *cantidad +1 ;
   int *nuevo_ptr = realloc(*puntero_bloque , sizeof (int));
   if (*nuevo_ptr == NULL){
    return false;
   }
   *puntero_bloque = nuevo_ptr;
   (*puntero_bloque)[*cantidad] = valor;
   (*cantidad++);
   return true;

}

