/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include <string.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }
    int *bloque = (int *)calloc(cantidad, sizeof(*bloque));
    return bloque;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL)
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
    int *nuevo = (int *)realloc(bloque, nueva_cantidad * sizeof(*nuevo));
    return nuevo;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{
    if (primero == NULL && segundo == NULL)
    {
        return NULL;
    }
    if (primero == NULL)
    {
        cant_primero = 0;
    }
    if (segundo == NULL)
    {
        cant_segundo = 0;
    }
    size_t total = cant_primero + cant_segundo;
    if (total == 0)
    {
        return NULL;
    }
    int *fusion = (int *)malloc(total * sizeof(*fusion));
    if (fusion == NULL)
    {
        return NULL;
    }
    if (cant_primero > 0)
    {
        memcpy(fusion, primero, cant_primero * sizeof(*fusion));
    }
    if (cant_segundo > 0)
    {
        memcpy(fusion + cant_primero, segundo,
               cant_segundo * sizeof(*fusion));
    }
    return fusion;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }
    
    int *nuevo = (int *)realloc(*puntero_bloque,
                                (*cantidad + 1) * sizeof(*nuevo));
    if (nuevo == NULL)
    {
        return false;
    }
    nuevo[*cantidad] = valor;
    *cantidad = *cantidad + 1;
    *puntero_bloque = nuevo;
    return true;
}
