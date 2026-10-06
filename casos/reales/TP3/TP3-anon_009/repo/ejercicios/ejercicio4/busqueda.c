

#include "busqueda.h"



const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado)
{
    if(arreglo == NULL || cantidad == 0)
    {
        return NULL;
    }
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;
    while(actual < fin)
    {
        if(*actual == buscado)
        {
            return actual;
        }
        actual++;
    }
    return NULL;
}

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento)
{
    if(inicio == NULL || elemento == NULL || elemento < inicio)
    {
        return -1;
    }
    return elemento - inicio;
}