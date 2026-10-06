/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include "vector_enteros.h"

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if(origen == NULL || cantidad == 0)
    {
        return NULL;
    }
    int *copia = (int *)malloc(cantidad * sizeof(int));
    if(copia == NULL)
    {
        return NULL;
    }
    const int *ptr_origen = origen;
    int *ptr_destino = copia;
    for(size_t i = 0; i < cantidad; i++)
    {
        *ptr_destino = *ptr_origen;
        ptr_destino++;
        ptr_origen++;
    } 
    return copia;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    if(cantidad_pares == NULL)
    {
        return NULL;
    }
    *cantidad_pares = 0;
    if(cantidad_origen == 0 || origen == NULL)
    {
        return NULL;
    }
    const int *ptr_lectura = origen;
    size_t contador_par = 0;
    for(size_t i = 0; i < cantidad_origen; i++)
    {
        if(*ptr_lectura % 2 == 0)
        {
            contador_par++;
        }
        ptr_lectura++;
    }
    if(contador_par == 0)
    {
        return NULL;
    }
    int *bloque_pares = (int *)malloc(contador_par * sizeof(int));
    if(bloque_pares == NULL)
    {
        return NULL;
    }
    ptr_lectura = origen;
    int  *ptr_escritura = bloque_pares;
    for(size_t i = 0; i < cantidad_origen;i++)
    {
        if(*ptr_lectura % 2 == 0)
        {
            *ptr_escritura = *ptr_lectura;
            ptr_escritura++;
        }
        ptr_lectura++;
    }
    *cantidad_pares = contador_par;

    return bloque_pares;
}
