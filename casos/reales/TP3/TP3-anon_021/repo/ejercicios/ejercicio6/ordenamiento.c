/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    const int *resultado = NULL;//supongo que elemenot mas chico es el primero del rango

    if (inicio != NULL && fin != NULL && inicio < fin)
    {
        const int *ptr_min = NULL;
        ptr_min = inicio;
        const int *avanzar = NULL; 
        avanzar = inicio + 1;
        while (avanzar < fin)
        {
            if (*avanzar < *ptr_min)
            {
                ptr_min = avanzar;//actualizo puntero a minimo
            }
            avanzar = avanzar + 1;   
        }
        resultado = ptr_min;//asigno minimo encontrado
        
    }
    return resultado;
}
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo != NULL && cantidad> 1)
    {
        int *actual = NULL;
        actual = arreglo;
        int *fin_arreglo = NULL;
        fin_arreglo = arreglo + cantidad;
        while (actual < fin_arreglo - 1)
        {
            int *minimo = NULL;
            minimo = (int*)buscar_puntero_minimo(actual, fin_arreglo);//puse ese int* porque buscar_puntero retorna const int
            
            if (minimo != NULL && minimo != actual)
            {
                intercambio (actual,minimo);
            }
            actual = actual + 1;
            
        }
        
    }
    
}

