/**
 * @file arreglos.c
 * @brief Esqueleto de implementación para la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    long long suma = 0;
    if ( arreglo != NULL && cantidad != 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
        suma = suma + arreglo[i];
        }
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int posicion = -1;
    if ((arreglo != NULL) && (cantidad > 0))
    {
        for (size_t i = 0; (i < cantidad) && (posicion == -1); i++)
        {
            if (arreglo[i] == buscado)
            {
                posicion = i; 
            }
        }
    }
    return posicion;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if (arreglo != NULL && cantidad > 1)
    {
        for (size_t i = 0; i < cantidad / 2; i++)
         {
            int aux = arreglo[i];
            arreglo[i] = arreglo[cantidad-1-i];
            arreglo[cantidad-1-i] = aux;
         }
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool ordenado = true;
    if (arreglo == NULL)
    {
        ordenado = false;
    }
    else if (cantidad <= 1)
    {
        ordenado = true;
    }
    else
    {
        for (size_t i = 0; (i < cantidad - 1) && (ordenado); i++)
        {
            if (arreglo[i] > arreglo[i+1])
            {     
                ordenado = false;
            }
        }
    }
    return ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;
    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] == buscado)
            {
                contador ++;
            }
        }
    }
    return contador;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t escribir = 0;

    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] != valor)
            {
                arreglo[escribir] = arreglo[i];
                escribir++;
            }
        }
    }
    return escribir;
}



