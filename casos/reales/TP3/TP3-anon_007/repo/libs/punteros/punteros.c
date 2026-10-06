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

//Nota: *puntero(lvalue) = contenido apuntado. 
//      puntero(lvalue) = direccion de memoria.
 
#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    if (primer != NULL && segundo != NULL)
    {
        int temp = *segundo;
        *segundo = *primer;
        *primer = temp;
    }
    
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    bool obtenido = false;
    if (arreglo != NULL && cantidad > 0 && minimo != NULL && maximo != NULL)
    {
        *maximo = *arreglo;
        *minimo = *arreglo;
        const int *inicio = arreglo;
        const int *fin = arreglo + cantidad;
        while (inicio < fin)
        {
            if (*inicio > *maximo)
            {
                *maximo = *inicio;
            }
            else if (*inicio < *minimo)
            {
                *minimo = *inicio;
            }
            inicio++;
        }
        if (minimo != NULL && maximo != NULL)
        {
            obtenido = true;
        }
    }
    return obtenido;
}

void imprimir_arreglo(const int *arreglo, size_t cantidad)
{
    if (arreglo != NULL && cantidad > 0)
    {
        const int *inicio = arreglo;
        const int *fin = arreglo + cantidad;
        while (inicio < fin)
        {
            printf("[%d]",*inicio);
            inicio++;
        }
        printf("\n");
    }
}