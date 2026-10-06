/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo,size_t capacidad, int valor)
{

    if(arreglo == NULL || capacidad == 0)
    {
        return NULL;
    }

    const int *fin = arreglo + capacidad ;
    const int *ptr = arreglo;

    while(ptr < fin)
    {
        if(*ptr == valor)
        {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}





int distancia_punteros(const int *p,const int *inicio)
{
    if(p == NULL || inicio == NULL || p < inicio)
    {
        return -1;
    }

    return (p - inicio);
}
