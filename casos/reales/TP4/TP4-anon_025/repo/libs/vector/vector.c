/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    

    if (cantidad == 0)
    {
        return NULL;
    }
    return (int *)calloc(cantidad, sizeof(int));
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
    
    if (nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }
    int *nuevo_bloque = (int *)realloc(bloque, nueva_cantidad * sizeof(int));
    return nuevo_bloque;
}



int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)
{
    if ((primero == NULL && segundo == NULL) || (cant_primero == 0 && cant_segundo == 0))
    {
        return NULL;
    }
    int *nuevo = (int *)malloc((cant_primero + cant_segundo) * sizeof(int));
    if (nuevo == NULL)
    {
        return NULL;
    }
    size_t indice = 0;
    for (size_t i = 0; i < cant_primero; i++)
    {
        nuevo[indice++] = segundo[i];
    }
    return nuevo;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }
    size_t nueva_cant = (*cantidad) + 1;
    int *nuevo_bloque = redimensionar_bloque_enteros(*puntero_bloque, nueva_cant);

    if (nuevo_bloque == NULL)
    {
        return false;
    }

    *puntero_bloque = nuevo_bloque;
    (*puntero_bloque)[*cantidad] = valor;
    (*cantidad)++;

    return true;
}