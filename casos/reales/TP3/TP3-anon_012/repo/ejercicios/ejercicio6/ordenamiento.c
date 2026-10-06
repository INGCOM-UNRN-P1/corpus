/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h" 
#include <stddef.h>

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    const int *min_ptr = NULL;
    
    if (inicio != NULL && fin != NULL && inicio < fin)
    { 
        min_ptr = inicio; const int *actual = inicio + 1;
        
        while (actual < fin)
        { 
            if (*actual < *min_ptr)
            { 
                min_ptr = actual;
            } 
            
            actual++;
        }
    }
    
    return min_ptr;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    bool exito = false;
    
    if (arreglo != NULL)
    {
        if (cantidad > 1)
        { 
            int *i = arreglo;
            int *fin = arreglo + cantidad;
            
            while (i < fin - 1)
            { 
                const int *min_const = buscar_puntero_minimo(i, fin);
                
                if (min_const != NULL)
                { 
                    int *min_ptr = (int *)min_const;
                    
                    if (min_ptr != i)
                    { 
                        intercambiar(i, min_ptr);
                    } 
                }

                i++;
            }
        } 
        
        exito = true;
    } 
    
    return exito;
}