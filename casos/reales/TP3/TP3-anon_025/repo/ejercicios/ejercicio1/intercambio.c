/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"



void ordenar_par(int *puntero_menor, int *puntero_mayor)
{
    if (puntero_menor == NULL || puntero_mayor == NULL)
    {
        return;
    }
    if (*puntero_menor > *puntero_mayor)
    {
        intercambiar(puntero_menor, puntero_mayor);
    }
}

void ordenar_tria(int *puntero_primero, int *puntero_segundo, int *puntero_tercero)
{
    if (puntero_primero == NULL || puntero_segundo == NULL || puntero_tercero == NULL)
    {
        return;
    }

    ordenar_par(puntero_primero, puntero_segundo);
    ordenar_par(puntero_segundo, puntero_tercero);
    ordenar_par(puntero_primero, puntero_segundo);
}

bool sumar_acumulado(const int *arreglo_fuente, size_t cantidad_elementos, long long *resultado)
{
    if (arreglo_fuente == NULL || resultado == NULL)
    {
        return false;
    }

    *resultado = 0;

    const int *cursor_actual = arreglo_fuente;

    for (size_t elementos_procesados = 0; elementos_procesados < cantidad_elementos; elementos_procesados++)
    {
        *resultado += *cursor_actual;
        cursor_actual++;
    }
    return true;
}
