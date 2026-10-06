/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"



void ordenar_par(int *menor, int *mayor)
{
    (void)menor;
    (void)mayor;
    if((menor != NULL) && (mayor != NULL))
    {
        if(*menor > *mayor)
        {
            intercambiar(menor, mayor);
        }
    }
}

void ordenar_tria(int *valor_menor, int *valor_medio, int *valor_mayor)
{
    (void)valor_menor;
    (void)valor_medio;
    (void)valor_menor;
    if((valor_menor != NULL) && (valor_medio != NULL) && (valor_mayor != NULL))
    {
        ordenar_par(valor_menor, valor_mayor);
        ordenar_par(valor_medio, valor_mayor);
        ordenar_par(valor_menor, valor_medio);
    }
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    (void)arreglo;
    (void)cantidad;
    (void)resultado;

    bool estado_suma = true;

    if((arreglo == NULL) || (resultado == NULL))
    {
        estado_suma = false;
    }
    else
    {
        *resultado = 0;
        for(size_t i = 0; i < cantidad; i++)
        {
            *resultado = *resultado + *arreglo;
            arreglo = arreglo + 1;
        }
    }

    return estado_suma;
}
