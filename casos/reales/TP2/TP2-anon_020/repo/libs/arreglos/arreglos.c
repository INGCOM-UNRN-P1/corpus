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
    for (size_t i = 0; i < cantidad; ++i)
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

    for (size_t i = 0; i < cantidad; ++i)
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
        int tmp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = tmp;
        ++i;
        --j;
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

    for (size_t i = 0; i + 1 < cantidad; ++i)
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

    size_t contador = 0;

    for (size_t i = 0; i < cantidad; ++i)
    {
        if (arreglo[i] == buscado)
        {
            ++contador;
        }
    }

    return contador;
}



size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t write = 0;

    for (size_t read = 0; read < cantidad; ++read)
    {
        if (arreglo[read] != valor)
        {
            arreglo[write++] = arreglo[read];
        }
    }

    return write;
}



size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad)
{
    if (destino == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (k < capacidad && i < cantidad_uno && j < cantidad_dos)
    {
        if (primero[i] <= segundo[j])
        {
            destino[k++] = primero[i++];
        }
        else
        {
            destino[k++] = segundo[j++];
        }
    }

    while (k < capacidad && i < cantidad_uno)
    {
        destino[k++] = primero[i++];
    }

    while (k < capacidad && j < cantidad_dos)
    {
        destino[k++] = segundo[j++];
    }

    return k;
}
