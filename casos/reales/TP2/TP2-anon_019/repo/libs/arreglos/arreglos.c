/**
 * @file arreglos.c
 * @brief Implementación de la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    long long suma = 0;
    size_t i;

    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    for (i = 0; i < cantidad; i++)
    {
        suma += arreglo[i];
    }

    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t i;

    if (arreglo == NULL || cantidad == 0)
    {
        return -1;
    }

    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            return (int)i;
        }
    }

    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    size_t inicio = 0;
    size_t fin;
    int temporal;

    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    fin = cantidad - 1;

    while (inicio < fin)
    {
        temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temporal;
        
        inicio++;
        fin--;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    size_t i;

    if (arreglo == NULL)
    {
        return false;
    }
    
    if (cantidad <= 1)
    {
        return true;
    }

    for (i = 0; i < cantidad - 1; i++)
    {
        if (arreglo[i] > arreglo[i + 1])
        {
            return false;
        }
    }

    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;
    size_t i;

    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            contador++;
        }
    }

    return contador;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t posicion_valida = 0;
    size_t i;

    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] != valor)
        {
            arreglo[posicion_valida] = arreglo[i];
            posicion_valida++;
        }
    }

    return posicion_valida;
}