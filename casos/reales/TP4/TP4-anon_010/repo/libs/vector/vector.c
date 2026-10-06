/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include <string.h>
#include "vector.h"
 
int *crear_bloque_enteros(size_t cantidad)
{
    int *bloque = NULL;
 
    if (cantidad > 0) {
        bloque = calloc(cantidad, sizeof(int));
    }
    return bloque;
}
 
void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque != NULL && *puntero_bloque != NULL) {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}
 
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    int *resultado = NULL;
 
    if (nueva_cantidad == 0) {
        free(bloque);
    } else {
        resultado = realloc(bloque, nueva_cantidad * sizeof(int));
    }
    return resultado;
}
 
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)
{
    int *fusion = NULL;
 
    if ((primero != NULL || cant_primero == 0) && (segundo != NULL || cant_segundo == 0)) {
        size_t total = cant_primero + cant_segundo;
 
        if (total > 0) {
            fusion = malloc(total * sizeof(int));
            if (fusion != NULL) {
                if (cant_primero > 0) {
                    memcpy(fusion, primero, cant_primero * sizeof(int));
                }
                if (cant_segundo > 0) {
                    memcpy(fusion + cant_primero, segundo, cant_segundo * sizeof(int));
                }
            }
        }
    }
    return fusion;
}
 
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    bool agregado = false;
 
    if (puntero_bloque != NULL && cantidad != NULL) {

        int *nuevo = redimensionar_bloque_enteros(*puntero_bloque, *cantidad + 1);
 
        if (nuevo != NULL) {
            nuevo[*cantidad] = valor;
            (*cantidad)++;
            *puntero_bloque = nuevo;
            agregado = true;
        }
    }
    return agregado;
}