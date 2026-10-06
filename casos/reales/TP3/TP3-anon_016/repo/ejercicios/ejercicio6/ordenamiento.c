/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if( inicio == NULL || inicio > fin 
        || fin < inicio)
    {
        return NULL;
    }
  
   const int *minimo = inicio;
     
   while(inicio <= fin)
   {
        if(*inicio < *minimo)
        {
           minimo = inicio; 
        }
     inicio++;
   } 
   return minimo;
}
void ordenar_seleccion_punteros (int *arreglo, size_t cantidad)
{
    int *actual = arreglo;
    int *fin = arreglo + cantidad - 1;      
    
    while(actual < fin)
    {
       const int *minimo = buscar_puntero_minimo(actual, fin);

       ptrdiff_t distancia = minimo - arreglo;
       int *pos_minimo = arreglo + distancia;

      int temp = *actual;
      *actual = *pos_minimo;
      *pos_minimo = temp;

      actual++;
    }
}

