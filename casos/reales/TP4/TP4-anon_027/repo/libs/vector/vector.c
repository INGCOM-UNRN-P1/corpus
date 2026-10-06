/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include <string.h>
#include "vector.h"




int *crear_bloque_enteros(size_t cantidad)
{
    if(cantidad == 0)
    {
        return NULL;
    }

    return calloc(cantidad, sizeof(int));
}




void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL) 
    {
        return;
    }

    free(*puntero_bloque);
    *puntero_bloque = NULL;
}




int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if (nueva_cantidad == 0) 
    {
        free(bloque);
        return NULL;
    }

    int *nuevo_bloque = realloc(bloque, nueva_cantidad * sizeof(int));

    if (nuevo_bloque == NULL) 
    {
        return NULL;
    }

    return nuevo_bloque;
}





 int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                                const int *segundo, size_t cant_segundo)
{
    size_t total_cant = cant_primero + cant_segundo;

    if (total_cant == 0 || (primero == NULL && segundo == NULL)) 
    {
        return NULL;
    }

    int *resultado = malloc(total_cant * sizeof(int));
    
    if (resultado == NULL) 
    {
        return NULL;
    }

    if ((primero != NULL) && (cant_primero > 0)) 
    {
        memcpy(resultado, primero, cant_primero * sizeof(int));
    }

    if ((segundo != NULL) && (cant_segundo > 0)) 
    {
        memcpy(resultado + cant_primero, segundo, cant_segundo * sizeof(int));
    }

    return resultado;
}





bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, 
int valor)
{
    if (puntero_bloque == NULL || cantidad == 0) 
    {
        return false;
    }
    
    size_t nueva_cantidad = *cantidad + 1;
    int *aux = realloc(*puntero_bloque, nueva_cantidad * sizeof(int));

    if (aux == NULL) 
    {
        return false;
    }
    
    *puntero_bloque = aux;
    (*puntero_bloque)[*cantidad] = valor;
    (*cantidad)++;

    return true;
}           