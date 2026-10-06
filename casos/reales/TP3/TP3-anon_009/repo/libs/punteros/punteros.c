

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    if(primer == NULL || segundo == NULL || primer == segundo)
    {
        return;
    }
    int temp = *primer;
    *primer = *segundo;
    *segundo = temp; 
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    if(arreglo == NULL || minimo == NULL || maximo == NULL || cantidad == 0)
    {
        return false;
    }
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;
    int valor_min = *actual;
    int valor_max = *actual;
    for(actual = arreglo + 1; actual < fin; actual++)
    {
        if(*actual < valor_min)
        {
            valor_min = *actual;
        }
        if(*actual > valor_max)
        {
            valor_max = *actual;
        }
    }
    *maximo = valor_max;
    *minimo = valor_min;
    return true;
}
