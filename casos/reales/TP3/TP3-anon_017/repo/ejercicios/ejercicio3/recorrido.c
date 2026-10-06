/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(const int *origen, size_t capacidad_origen, int *destino, size_t capacidad_destino)
{
    bool estado_copiar_arreglo = true;
    if((origen == NULL) || (capacidad_origen == 0) || (destino == NULL) || (capacidad_destino == 0))
    {
        estado_copiar_arreglo = false;
    }
    else
    {
        size_t contador = 0;
        while((contador < capacidad_origen) && (contador < capacidad_destino))
        {
            *destino = *origen;
            destino = destino + 1;
            origen = origen + 1;
            contador = contador + 1;
        }
    }
    return estado_copiar_arreglo;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    bool manejo_errores = true;
    if((arreglo == NULL) || (cantidad == 0))
    {
        manejo_errores = false;
    }
    else
    {
        int *arr_inicio = arreglo;
        int *arr_fin = arreglo + (cantidad - 1);
        int auxiliar = 0;
        while(arr_inicio <= arr_fin)
        {
            auxiliar = *arr_inicio;
            *arr_inicio = *arr_fin;
            *arr_fin = auxiliar;

            arr_inicio = arr_inicio + 1;
            arr_fin = arr_fin - 1;
        }
    }
    return manejo_errores;
}
