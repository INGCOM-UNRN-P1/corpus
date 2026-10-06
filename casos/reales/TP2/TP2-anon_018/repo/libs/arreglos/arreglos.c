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
    for (size_t posicion = 0; posicion < cantidad; posicion++)
    {
        suma += arreglo[posicion];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
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
        int auxiliar = arreglo[inicio];
        arreglo[inicio] = arreglo[final];
        arreglo[final] = auxiliar;
        inicio++;
        final--;
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

    for (size_t posicion = 0; posicion < cantidad - 1; posicion++)
    {
        if (arreglo[posicion] > arreglo[posicion + 1])
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

    size_t ocurrencias = 0;
    for (size_t posicion = 0; posicion < cantidad; posicion++)
    {
        if (arreglo[posicion] == buscado)
        {
            ocurrencias++;
        }
    }
    return ocurrencias;
}


 size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
 {
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    size_t escritura = 0;
    for (size_t lectura = 0; lectura < cantidad; lectura++)
    {
        if (arreglo[lectura] != valor)
        {
            arreglo[escritura] = arreglo[lectura];
            escritura++;
        }
    }
    return escritura;
 }


size_t arreglo_fusionar(const int primero [], size_t cantidad_uno, 
                        const int segundo [], size_t cantidad_dos,
                        int destino [], size_t capacidad)
{
    if (destino == NULL || capacidad == 0 || (primero == NULL && cantidad_uno > 0) || (segundo == NULL && cantidad_dos > 0))
    {
        return 0;
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (k < capacidad && (i < cantidad_uno || j < cantidad_dos))
    {
        if (j >= cantidad_dos || (i < cantidad_uno && primero[i] <= segundo[j]))
        {
            destino[k++] = primero[i++];
        }
        else 
        {
            destino[k++] = segundo[j++];
        }
    }
    return k;
}                        
