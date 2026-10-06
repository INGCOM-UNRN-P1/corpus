/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"
#include <stdio.h>
#include <string.h>

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0){
        return NULL;
    }
    
    return (int *)calloc(cantidad, sizeof(int));
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque != NULL && *puntero_bloque != NULL){
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if (nueva_cantidad == 0){
        if (bloque != NULL){
            free(bloque);
        }
        return NULL;
    }
    int *nuevo = (int *)realloc(bloque, nueva_cantidad * sizeof(int));
    return nuevo;
}



int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)
{
    size_t total = 0;
    if (primero != NULL) total += cant_primero;
    if (segundo != NULL) total += cant_segundo;

    if (total == 0) {
        return NULL;
    }

    int *resultado = (int *)malloc(total * sizeof(int));
    if (resultado == NULL) {
        return NULL;
    }

    size_t pos = 0;
    if (primero != NULL && cant_primero > 0) {
        memcpy(resultado + pos, primero, cant_primero * sizeof(int));
        pos += cant_primero;
    }

    if (segundo != NULL && cant_segundo > 0) {
        memcpy(resultado + pos, segundo, cant_segundo * sizeof(int));
    }

    return resultado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL) {
        return false;
    }

    size_t nueva_cant = *cantidad + 1;
    int *nuevo = (int *)realloc(*puntero_bloque, nueva_cant * sizeof(int));

    if (nuevo == NULL) {
        return false;
    }

    nuevo[*cantidad] = valor;
    *puntero_bloque = nuevo;
    *cantidad = nueva_cant;

    return true;
}