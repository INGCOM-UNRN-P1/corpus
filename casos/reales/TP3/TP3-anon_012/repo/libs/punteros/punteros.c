/**
 * @file punteros.c
 * @brief Esqueleto de implementación para la biblioteca libpunteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    
    if (primer != NULL && segundo != NULL && primer != segundo) 
    { 
        int aux = *primer;
        *primer = *segundo;
        *segundo = aux; 
    }
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    
    bool exito = false;
    
    if (arreglo != NULL && cantidad > 0 && minimo != NULL && maximo != NULL)
    { 
        int minimo_valor = *arreglo;
        int maximo_valor = *arreglo;
        
        for (size_t i = 1; i < cantidad; i++)
        { 
            int val = *(arreglo + i);
            
            if (val < minimo_valor) 
            { 
                minimo_valor = val; 
            } 
            
            if (val > maximo_valor)
            { 
                maximo_valor = val; 
            } 
        } 
        
        *minimo = minimo_valor;
        *maximo = maximo_valor;
        exito = true; 
    } 
    
    return exito;
}
