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
    size_t posicion = 0;

    if (arreglo != NULL)
    {
        for (posicion = 0; posicion < cantidad; posicion++)
        {
            suma += arreglo[posicion];
        }
    }

    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int indice = -1;
    size_t posicion = 0;
    bool encontrado = false;

    if (arreglo != NULL)
    {
        while ((posicion < cantidad) && (!encontrado))
        {
            if (arreglo[posicion] == buscado)
            {
                indice = (int)posicion;
                encontrado = true;
            }
            else
            {
                posicion++;
            }
        }
    }

    return indice;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    size_t izquierda = 0;
    size_t derecha = 0;
    int auxiliar = 0;

    if ((arreglo != NULL) && (cantidad > 1))
    {
        derecha = cantidad - 1;

        while (izquierda < derecha)
        {
            auxiliar = arreglo[izquierda];
            arreglo[izquierda] = arreglo[derecha];
            arreglo[derecha] = auxiliar;

            izquierda++;
            derecha--;
        }
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool ordenado = true;
    size_t posicion = 1;

    if (arreglo == NULL)
    {
        ordenado = false;
    }
    else
    {
        while ((posicion < cantidad) && ordenado)
        {
            if (arreglo[posicion - 1] > arreglo[posicion])
            {
                ordenado = false;
            }
            else
            {
                posicion++;
            }
        }
    }

    return ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t coincidencias = 0;
    size_t posicion = 0;

    if (arreglo != NULL)
    {
        for (posicion = 0; posicion < cantidad; posicion++)
        {
            if (arreglo[posicion] == buscado)
            {
                coincidencias++;
            }
        }
    }

    return coincidencias;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t lectura = 0;
    size_t escritura = 0;

    if (arreglo != NULL)
    {
        for (lectura = 0; lectura < cantidad; lectura++)
        {
            if (arreglo[lectura] != valor)
            {
                arreglo[escritura] = arreglo[lectura];
                escritura++;
            }
        }
    }

    return escritura;
}

