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

    if(arreglo != NULL)
    {
        for(size_t i = 0; i < cantidad; i++)
        {
            suma += arreglo[i];
        }
    }

    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int posicion = 0;
    int encontrado = 0;

    if(arreglo != NULL && cantidad > 0)
    {
        for(size_t i = 0; i < cantidad; i++)
        {
            if(arreglo[i] == buscado)
            {
                posicion += i;
                encontrado = 1;
                i = cantidad;
            }
        }
    }

    if (encontrado != 1)
    {
        posicion = -1;
    }

    return posicion;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    int izquierda = 0;
    int derecha = 0;

    for(size_t i = 0; i < cantidad / 2; i++)
    {
        izquierda = arreglo[i];
        derecha = arreglo[((cantidad - 1) - i)];

        arreglo[i] = derecha;
        arreglo[((cantidad - 1) - i)] = izquierda;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool ordenado = true;

    if(arreglo == NULL)
    {
        ordenado = false;
    }

    if(cantidad > 1 && arreglo != NULL)
    {
        for(size_t i = 0; i < (cantidad - 1); i++)
        {
            if(arreglo[i] > arreglo[i + 1])
            {
                ordenado = false;
                i = cantidad;
            }
        }
    }

    return ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t cont = 0;

    if(arreglo != NULL && cantidad > 0)
    {
        for(size_t i = 0; i < cantidad; i++)
        {
            if(arreglo[i] == buscado)
            {
                cont += 1;
            }
        }
    }

    return cont;
}



