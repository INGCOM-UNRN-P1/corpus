/**
 * @file arreglos.c
 * @brief Implementacion de la biblioteca libarreglos.
 *
 * Trabajo Practico 2 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#include "arreglos.h"


long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    long long suma = 0;

    for (size_t posicion = 0; posicion < cantidad; posicion++)
    {
        suma = suma + arreglo[posicion];
    }

    return suma;
}


int arreglo_buscar(
    const int arreglo[],
    size_t cantidad,
    int buscado
)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return -1;
    }

    for (size_t posicion = 0; posicion < cantidad; posicion++)
    {
        if (arreglo[posicion] == buscado)
        {
            return (int)posicion;
        }
    }

    return -1;
}


void arreglo_invertir(
    int arreglo[],
    size_t cantidad
)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    for (size_t posicion = 0; posicion < cantidad / 2; posicion++)
    {
        int auxiliar = arreglo[posicion];

        arreglo[posicion] = arreglo[cantidad - 1 - posicion];

        arreglo[cantidad - 1 - posicion] = auxiliar;
    }
}


bool arreglo_ordenado(
    const int arreglo[],
    size_t cantidad
)
{
    if (arreglo == NULL)
    {
        return false;
    }

    if (cantidad <= 1)
    {
        return true;
    }

    for (size_t posicion = 0; posicion < cantidad - 1; posicion++)
    {
        if (arreglo[posicion] > arreglo[posicion + 1])
        {
            return false;
        }
    }

    return true;
}


size_t arreglo_contar(
    const int arreglo[],
    size_t cantidad,
    int buscado
)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t contador = 0;

    for (size_t posicion = 0; posicion < cantidad; posicion++)
    {
        if (arreglo[posicion] == buscado)
        {
            contador++;
        }
    }

    return contador;
}


size_t arreglo_compactar(
    int arreglo[],
    size_t cantidad,
    int valor
)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t nueva_cantidad = 0;

    for (size_t posicion = 0; posicion < cantidad; posicion++)
    {
        if (arreglo[posicion] != valor)
        {
            arreglo[nueva_cantidad] = arreglo[posicion];
            nueva_cantidad++;
        }
    }

    return nueva_cantidad;
}