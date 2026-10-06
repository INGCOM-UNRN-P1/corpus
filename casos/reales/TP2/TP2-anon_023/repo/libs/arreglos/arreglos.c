/**
 * @file arreglos.c
 * @brief Implementación de la biblioteca libarreglos.
 */

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    long long suma = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        suma += arreglo[i];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < cantidad; i++)
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
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    size_t i = 0;
    size_t j = cantidad - 1;
    while (i < j)
    {
        int temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
        i++;
        j--;
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

    for (size_t i = 0; i < cantidad - 1; i++)
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
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t total = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            total++;
        }
    }
    return total;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t pos_escritura = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] != valor)
        {
            arreglo[pos_escritura] = arreglo[i];
            pos_escritura++;
        }
    }
    return pos_escritura;
}


