/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"



const int *buscar_primero(const int *arreglo, size_t cantidad, const int *valor)
{
    if(arreglo == NULL || valor == NULL || cantidad == 0)
    {
        return NULL;
    }

   const int *actual = arreglo;
   const int *fin = arreglo + cantidad;      
   while(actual != fin)
   {
     if(*actual == *valor)
     {
         return actual;
     }
     actual++;
   }
    return NULL;
}

int distancia_punteros(const int *arreglo, const int *elemento)
{
     if(arreglo == NULL || elemento == NULL)
    {
        return -1;
    }
    const int *inicio = arreglo;
    int distancia = 0;

     if(elemento < inicio)
    {
        return -1;
    }

    distancia = elemento - inicio;
     
    return distancia;
    
}