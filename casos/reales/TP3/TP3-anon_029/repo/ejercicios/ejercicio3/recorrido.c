/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool arreglo_invertir(int *arreglo  , size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return false;
    }
int *inicio = arreglo;
int *fin = arreglo + (cantidad - 1);
int auxiliar = 0;   
    while(inicio < fin)
    {
    auxiliar = *inicio;
    *inicio = *fin;
    *fin = auxiliar;
    inicio ++;
    fin --;
    }
    return true;
}

bool copiar_arreglo(const int *origen, int *destino, size_t capacidad)
{
    if (origen == NULL || destino == NULL || capacidad == 0)
    {
        return false;
    }
    const int *puntero_origen = origen;
    int *puntero_destino = destino;
    const int *fin = origen + capacidad;

    while (puntero_origen < fin)
    {
        *puntero_destino = *puntero_origen;
        puntero_origen ++;
        puntero_destino ++;
    }
    return true;
    
}
