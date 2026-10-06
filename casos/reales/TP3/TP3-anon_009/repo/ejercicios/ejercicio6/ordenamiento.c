/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"



const int* buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if(inicio == NULL || fin == NULL || inicio >= fin)
    {
        return NULL;
    }
    const int *p_min = inicio;
    const int *actual = inicio + 1;
    while(actual < fin)
    {
        if(*actual < *p_min)
        {
            p_min = actual;
        }
        actual++;
    }
    return p_min;
}

void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if(arreglo == NULL || cantidad <= 1)
    {
        return;
    }
    int *actual = arreglo;
    int *limite = arreglo + cantidad;
    while(actual < limite - 1)
    {
        const int *p_min = buscar_puntero_minimo(actual, limite);
        if(p_min != NULL && p_min != actual)
        {
            int aux = *actual;
            *actual = *(int *)p_min;
            *(int *)p_min = aux;
        }
        actual++;
    }
}