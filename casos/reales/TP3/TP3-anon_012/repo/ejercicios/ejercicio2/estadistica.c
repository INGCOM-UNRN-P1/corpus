/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"



bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    bool exito = false;
    
    if (arreglo != NULL && cantidad > 0 && minimo != NULL && maximo != NULL && promedio != NULL)
    { 
        if (obtener_min_max(arreglo, cantidad, minimo, maximo))
        { 
            long long suma = 0;
            
            for (size_t i = 0; i < cantidad; i++)
            { 
                suma += *(arreglo + i);
            }
            
            *promedio = (double)suma / (double)cantidad;
            exito = true;
        }
    }
    
    return exito;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    bool exito = false;
    
    if (arreglo != NULL && coincidencias != NULL)
    { 
        size_t contador = 0;
        for (size_t i = 0; i < cantidad; i++)
        { 
            int val = *(arreglo + i);
            
            if (val >= limite_inf && val <= limite_sup)
            { 
                contador++;
            }
        }
    
        *coincidencias = contador;
        exito = true;
    }
    
    return exito;
}
