/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include "vector.h"
#include <stdlib.h>


int *crear_bloque_enteros(size_t cantidad)
{
    int *bloque_int = NULL;
    if (cantidad != 0)
    {
        bloque_int = (int *)calloc(cantidad, sizeof(int));
    }
    return bloque_int;
}


void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque != NULL && *puntero_bloque != NULL)
    {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}


int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    int *nuevo_bloque = NULL;
    if (nueva_cantidad == 0)
    {
        free(bloque);
    }
    else
    {
        nuevo_bloque = (int *)realloc(bloque, nueva_cantidad * sizeof(int));
        if (nuevo_bloque != NULL)
        {
            bloque = nuevo_bloque;
        }
    }
    return nuevo_bloque;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)                          
{
    size_t cantidad_total = cant_primero + cant_segundo;
    int *nuevo_bloque = NULL;
    if (cantidad_total != 0)
    {
        nuevo_bloque = crear_bloque_enteros(cantidad_total);
        if (nuevo_bloque != NULL)
        {
            for (size_t i = 0; i < cant_primero; i++)
            {
                nuevo_bloque[i] = primero[i];
            }
            for (size_t i = 0; i < cant_segundo; i++)
            {
                nuevo_bloque[cant_primero + i] = segundo[i];
            }
        }
    }
    return nuevo_bloque;
}


bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor)
{
    bool exito = false;
    if ((puntero_bloque != NULL) && (cantidad != NULL))
    {
        int *nuevo_bloque =
            (int *)realloc(*puntero_bloque, (*cantidad + 1) * sizeof(int));
        if (nuevo_bloque != NULL)
        {
            nuevo_bloque[*cantidad] = valor;
            *puntero_bloque = nuevo_bloque;
            (*cantidad)++;
            exito = true;
        }
    }
    return exito;
}
