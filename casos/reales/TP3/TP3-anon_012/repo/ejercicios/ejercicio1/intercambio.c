/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"



void ordenar_par(int *menor, int *mayor)
{
    if (menor != NULL && mayor != NULL) 
    { 
        if (*menor > *mayor)
        { 
            intercambiar(menor, mayor);
        } 
    } 
}

void ordenar_tria(int *a, int *b, int *c)
{
    if (a != NULL && b != NULL && c != NULL)
    { 
        ordenar_par(a, b); 
        ordenar_par(b, c); 
        ordenar_par(a, b);
    }
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    bool exito = false;
    if (arreglo != NULL && resultado != NULL)
    { 
        long long suma = 0;
        
        for (size_t i = 0; i < cantidad; i++)
        { 
            suma += *(arreglo + i);
        }
        
        *resultado = suma;
        exito = true;
    }
    
    return exito;
}
