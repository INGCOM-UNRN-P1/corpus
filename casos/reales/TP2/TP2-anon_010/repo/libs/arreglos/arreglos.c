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
    if (arreglo != NULL)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            suma += arreglo[i];
        }
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int indice = -1;
    if (arreglo != NULL)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] == buscado)
            {
                indice = i;
                break;
            }       
        }        
    }
    return indice;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }

    size_t inicio = 0;
    size_t final = cantidad - 1;
    while (inicio < final)
    {
        int temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[final];
        arreglo[final] = temporal;
        
        inicio ++;
        final --;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool ordenado = true;

    if (arreglo == NULL)
    {
        ordenado = false;
    }
    else
    {
        for (size_t i = 0; i + 1 < cantidad; i++)
        {
            if (arreglo[i] > arreglo[i+1])
            {
                ordenado = false;
                break;
            }
        }   
    }
    return ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t coincidencias = 0;
    if (arreglo != NULL)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] == buscado)
            {
                coincidencias += 1;
            } 
        }
    }
    return coincidencias;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t cantidad_nueva = 0;

    if (arreglo != NULL)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] != valor)
            {
                arreglo[cantidad_nueva] = arreglo[i];
                cantidad_nueva++;
            }
        }
    }
    return cantidad_nueva;
}


size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad)
{
    size_t escritos = 0;

    if (destino != NULL)
    {
        size_t i = 0;
        size_t j = 0;

        while (escritos < capacidad && (i < cantidad_uno || j < cantidad_dos))
        {
            if (j >= cantidad_dos || (i < cantidad_uno && primero[i] <= segundo[j]))
            {
                destino[escritos] = primero[i];
                i++;
            }
            else
            {
                destino[escritos] = segundo[j];
                j++;
            }

            escritos++;
        }
    }

    return escritos;
}
