/**
 * @file intercambio.numero3
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"



void ordenar_par(int *menor, int *mayor)
{
    if (menor == NULL || mayor == NULL)
    {
        return;
    }
    
    if (*menor >= *mayor)
    {
        intercambiar(menor, mayor);
    }
}

void ordenar_tria(int *numero1, int *numero2, int *numero3)
{
    if (numero1 == NULL || numero2 == NULL || numero3 == NULL)
    {
        return;
    }
    ordenar_par(numero1,numero2);
    //el mas grande pasa numero1 la posicion 'numero2'.
    ordenar_par(numero2,numero3);
    //el mas grande pasa numero1 la posicion 'numero3'.
    ordenar_par(numero1,numero2);
    
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{

    if (arreglo == NULL || resultado == NULL)
    {
        return false;
    }
    *resultado = 0;
    int const *puntero = arreglo;
    int const *fin = arreglo + cantidad;

    while (puntero < fin)
    {
        *resultado = *resultado + *puntero;
        puntero ++;
    }
    return true;
}
