/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor)
{
    const int *resultado = NULL; 
    if (arreglo != NULL)
    {
        const int *actual = NULL; //puntero auxiliar de lectura
        const int *limite = NULL;//puntero limite 
        actual = arreglo;
        limite = arreglo +cantidad;
        bool encontrado = false; //hago abndera para simular cortocircuito
        while (actual < limite && !encontrado)//frena si lelgo al limite o encuentra el elemento
        {
            if (*actual == valor)
            {
                resultado = actual;//aca oasaria el cortocircuito
                encontrado = true;
            }
            
            
            actual = actual +1;//avanzo puntero hacia siguiente celda
            
        }
        
    }
    return resultado;
}
