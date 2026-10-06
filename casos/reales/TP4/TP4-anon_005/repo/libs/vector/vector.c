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
    
    int *direccion = calloc(cantidad, sizeof(int));
    return direccion;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL)
    {
        return;
    }
    
    if (*puntero_bloque == NULL)
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

    int *dir_nueva = realloc(bloque,nueva_cantidad * sizeof(int));
    
    return dir_nueva;

}


