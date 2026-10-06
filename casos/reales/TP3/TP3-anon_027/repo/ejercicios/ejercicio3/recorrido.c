/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(const int *origen, size_t cantidad, int *destino)
{
    if(origen == NULL || cantidad == 0 || destino == NULL)
    {
        return false;
    }

    while(cantidad > 0)
    {
        *destino = *origen;
        ++ origen;
        ++ destino;
        cantidad --;
    }

    return true;
}


bool invertir_arreglo(int *arreglo, size_t cantidad, 
    int *inicio, int *fin)
{
    if(arreglo == NULL || cantidad == 0)
    {
        return false;
    }

    if (cantidad == 1)
    {
        return true;
    }

    inicio = arreglo;
    fin = arreglo + (cantidad - 1);


    while(inicio < fin)
    {
        int invertido = *inicio;
        *inicio = *fin;
        *fin = invertido;
        inicio ++;
        fin --;
    }

    return true;
}


