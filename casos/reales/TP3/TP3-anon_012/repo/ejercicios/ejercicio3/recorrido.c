/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"


bool copiar_arreglo(int *destino, const int *origen, size_t cantidad)
{
    bool exito = false;

    if (destino != NULL && origen != NULL)
    { 
        int *ptr_dest = destino;
        const int *ptr_orig = origen;
        
        for (size_t i = 0; i < cantidad; i++)
        { 
            *ptr_dest = *ptr_orig; 
            ptr_dest++;
            ptr_orig++;
        } 
        
        exito = true;
    }
    
    return exito;
}

bool invertir_arreglo(int *arreglo, size_t cantidad)
{ 
    bool exito = false;
    
    if (arreglo != NULL)
    { 
        if (cantidad > 1)
        { 
            int *inicio = arreglo;
            int *fin = arreglo + cantidad - 1;
            
            while (inicio < fin)
            { 
                intercambiar(inicio, fin);
                inicio++;
                fin--; 
            }
        } 
        
        exito = true;
    }
    
    return exito;
}