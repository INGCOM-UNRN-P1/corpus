/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"




void ordenar_par(int *menor, int *mayor)
{
    if (menor == NULL || mayor == NULL)
    {
        return;
    }
    
    if(*menor > *mayor)
    {
        intercambiar(menor, mayor);
    }
}




void ordenar_tria(int *a, int *b, int *c)
{
    if(a == NULL || b == NULL || c == NULL)
    {
        return;
    }    

    if(((*a > *b) && (*a > *c)))
    {
        intercambiar(a,c);
        ordenar_par(a,b);
    }
}




bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    long long suma = 0;
    const int *fin = arreglo + cantidad;

    if(arreglo == NULL || resultado == NULL)
    {
        return false;
    }
    
    else
    {   
        for(const int *ptr = arreglo; ptr < fin; ptr++)
        {
            suma = suma + *ptr;
        }
        
        *resultado = suma;
        return true;
    }
}
