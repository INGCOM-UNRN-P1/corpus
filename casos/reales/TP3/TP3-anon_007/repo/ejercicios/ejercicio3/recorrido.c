/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

//Tuve que copiar la funcion intercambiar porque por alguna razon no me la toma el makefile directo desde la libreria punteros

void intercambiar(int *primer, int *segundo)
{
    if (primer != NULL && segundo != NULL)
    {
        int temp = *segundo;
        *segundo = *primer;
        *primer = temp;
    }
}

bool copiar_arreglo(const int *arreglo_origen, int *arreglo_destino,
                    size_t capacidad_origen, size_t capacidad_destino)
{
    bool es_valido = false;
    if (arreglo_origen != NULL && arreglo_destino != NULL && capacidad_origen > 0 && capacidad_destino > 0)
    {
        const int *inicio_origen = arreglo_origen;
        int *inicio_destino = arreglo_destino;
        const int *fin_origen = arreglo_origen + capacidad_origen;
        int *fin_destino = arreglo_destino + capacidad_destino;
        if (capacidad_origen > capacidad_destino)
        {
            while (inicio_destino < fin_destino)
            {
                *inicio_destino = *inicio_origen;
                inicio_destino++;
                inicio_origen++;
            }
            es_valido = true;
        }
        else
        {
            while (inicio_origen < fin_origen)
            {
                *inicio_destino = *inicio_origen;
                inicio_destino++;
                inicio_origen++;
            }
            es_valido = true;
        }
    }
    return es_valido;
}

void invertir_arreglo(int *arreglo, size_t capacidad)
{
    if (arreglo != NULL && capacidad > 0)
    {
        int *inicio = arreglo;
        int *fin = arreglo + capacidad;
        while (inicio < fin - 1)
        {
            intercambiar(inicio, fin - 1);
            inicio++; 
            fin--; 
        }
    }
}