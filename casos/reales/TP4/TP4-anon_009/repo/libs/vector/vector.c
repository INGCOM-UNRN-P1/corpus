/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    if(cantidad == 0)
    {
        return NULL;
    }
    char *bloque = (int *)calloc(cantidad, sizeof(int));
    if(bloque == NULL)
    {
        return NULL;
    }
    return bloque;

}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if(puntero_bloque == NULL || *puntero_bloque == NULL)
    {
        return;
    }
    free(*puntero_bloque);
    *puntero_bloque = NULL;
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if(nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }
    int *nuevo_bloque = (int *)realloc(bloque, nueva_cantidad * sizeof(int));
    if(nuevo_bloque == NULL)
    {
        return NULL;
    }
    return nuevo_bloque;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                                const int *segundo, size_t cant_segundo)
{
    if(primero == NULL && segundo == NULL )
    {
        return NULL;
    }
    size_t largo1 = (primero != NULL) ? cant_primero : 0;
    size_t largo2 = (segundo != NULL) ? cant_segundo : 0;
    size_t total_elementos = largo1 + largo2;
    int *resultado = (int *)malloc(total_elementos * sizeof(int));
    if(resultado == NULL)
    {
        return NULL;
    }
    int *ptr_destino = resultado;
    if(primero != NULL && largo1 > 0)
    {
        const int *ptr_origen = primero;
        for(size_t i = 0; i < largo1; i++)
        {
            *ptr_destino = *ptr_origen;
            ptr_destino++;
            ptr_origen++;
        }
    }
    if (segundo != NULL && largo2 > 0)
    {
        const int *ptr_origen = segundo; // <-- Apuntar a 'segundo'
        for (size_t i = 0; i < largo2; i++)
        {
            *ptr_destino = *ptr_origen;
            ptr_destino++;
            ptr_origen++;
        }
    }
    return resultado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if(puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }
    size_t nueva_cantidad = *cantidad + 1;
    int *nuevo_bloque = (int *)realloc(*puntero_bloque, nueva_cantidad + sizeof(int));
    if(nuevo_bloque == NULL)
    {
        return false;
    }
    *(nuevo_bloque + *cantidad) = valor;
    *puntero_bloque = nuevo_bloque;
    (*cantidad)++;
    return true;
}
