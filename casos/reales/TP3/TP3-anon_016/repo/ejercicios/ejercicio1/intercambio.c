/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"




void ordenar_par(int *menor, int *mayor)
{
    if(menor == NULL || mayor == NULL)
    {
        return;
    }
    if(*menor > *mayor)
    {
        intercambiar(menor,mayor);
    }
}


void ordenar_tria(int *a, int *b, int *c)
{
  ordenar_par(a, b); 
  ordenar_par(b, c);
  ordenar_par(a, b);
}


bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    if(arreglo == NULL || resultado == NULL)
    {
        return false;
    }
    *resultado = 0;
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;
        
    while(actual != fin)
    {
        *resultado = *resultado + *actual;
        actual++;
    }
    return true;
   
}
