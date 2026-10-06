/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"



bool calcular_estadisticas(const int *arreglo, size_t cantidad, 
int *minimo, int *maximo, double *promedio)
{
    if(arreglo == NULL || minimo == NULL || maximo == NULL 
        || promedio == NULL || cantidad == 0)
    {
        return false;
    }
    
    else
    {
        const int *ptr = arreglo;
        const int *fin = arreglo + cantidad;
        long long suma = 0;
        *minimo = *ptr;
        *maximo = *ptr;

        while (ptr < fin)
        {
            if (*ptr < *minimo)
            {
                *minimo = *ptr;
            }

            if (*ptr > *maximo)
            {
                *maximo = *ptr;
            }

            suma += *ptr;
            ptr++;
        }

        *promedio = (double)suma / cantidad;
        return true;
    }  
}







bool contar_en_rango(const int *arreglo, size_t cantidad, 
    int limite_inf, int limite_sup, size_t *coincidencias)
{
  
    if(arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }
    
    const int *puntero = arreglo;
    const int *fin = arreglo + cantidad;
    *coincidencias = 0;
    
    while(puntero < fin)
    {
        if((*puntero >= limite_inf) && (*puntero <= limite_sup))
        {
            (*coincidencias)++;
        }
            puntero++;
    }
    
    return true;
}

