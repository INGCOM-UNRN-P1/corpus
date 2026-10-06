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
    long long resultado = 0;

    if (arreglo == NULL || cantidad == 0)
    {
        resultado = 0;
    }
    else
    {
        long long suma = 0;

        for (size_t i = 0; i < cantidad; i++)
        {
            suma = suma + arreglo[i];
        }
        resultado = suma;
    }

    
    return resultado;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int indice = -1;

    if (arreglo == NULL || cantidad == 0)
    {
        indice = -1;
    }
    else
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] == buscado && indice == -1)
            {
                indice = (int)i;
            }
        }
    }
    return indice;
}
void arreglo_invertir(int arreglo[], size_t cantidad)
{

    if (arreglo != NULL && cantidad > 1)
    {
        for (size_t i = 0; i < cantidad / 2; i++)
        {
            size_t invertido = 0;

            invertido = cantidad - 1 - i;

            int valor_temporal = arreglo[i];

            arreglo[i] = arreglo[invertido];

            arreglo[invertido] = valor_temporal;
        }
    }
    
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool resultado = true;

    if (arreglo == NULL)
    {
        resultado = false;
    }
    else if (cantidad <= 1)
    {
        resultado = true;
    }
    else
    {
        for (size_t i = 0; i < cantidad - 1; i++)
        {
            if (arreglo[i] > arreglo[i + 1])
            {
                resultado = false;
            }
        }
    }
    return resultado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t apariciones = 0;

    if (arreglo == NULL || cantidad == 0)
    {
        apariciones = 0;
    }
    else
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if(arreglo[i] == buscado)
            {
                apariciones++;
            }
        }
    }
    
    return apariciones;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t elem_validos = 0;

    if (arreglo == NULL || cantidad == 0)
    {
        elem_validos = 0;
    }
    else
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] != valor)
            {
                arreglo[elem_validos] = arreglo[i];
                elem_validos++;
            }
        }
    }
    return elem_validos;
}

