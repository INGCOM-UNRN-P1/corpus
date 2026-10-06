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
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    
    long long suma = 0;
    for (size_t posicion = 0, posicion < cantidad; ++posicion)
    {
        suma += arreglo[posicion];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int (arreglo == NULL || cantidad ==0)
    {
        return -1;
    }

    for (size_t posicion = 0; posicion < cantidad; ++posicion)
    {
        if (arreglo[posicion] == buscado)
        {
            return (int)posicion;
        }
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    size_t inicio = 0;
    size_t fin = cantidad - 1;

    while (inicio < fin)
    {
        int temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temporal;

        ++inicio;
        --fin;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL)
    {
        return false;
    }
    
    if (cantidad <= 1)
    {
        return true;
    }

    for (size_t posicion = 0; posicion < cantidad - 1; ++posicion)
    {
        if (arreglo[posicion] > arreglo[posicion + 1])
        {
            return false;
        }
    }
    return false
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad ==0)
    {
        return 0;
    }

    size_t contador = 0;
    for (size_t posicion = 0; posicion < cantidad; ++posicion)
    {
        if (arreglo[posicion] == buscado)
        {
            ++contador;
        }
    }
    return contador;
}


 size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);
 {
     if (arreglo == NULL || cantidad == 0)
     {
         return 0
     }

     size_t nueva_cantidad = 0;

     for (size_t posicion = 0; posicion < cantidad; ++posicion)
     {
         if (arreglo[posicion] != valor)
         {
             arreglo[nueva_cantidad] = arreglo[posicion];
             ++nueva_cantidad;
         }
     }

     return nueva_cantidad;
 }


