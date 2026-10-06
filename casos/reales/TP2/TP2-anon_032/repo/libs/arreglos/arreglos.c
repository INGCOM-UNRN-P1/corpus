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
    if (cantidad == 0 || arreglo == NULL)
    {
        return 0;
    }

    long long sumatoria = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        sumatoria += arreglo[i];
    }

    return sumatoria;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if ( arreglo == NULL || cantidad == 0)
    {
        return -1;
    }

    bool buscando_entero = true;
    int posicion = -1;
    size_t i = 0;
    while (buscando_entero == true && i < cantidad)
    {
        if (arreglo[i] == buscado)
        {
            posicion = i;
            buscando_entero = false;
        }
        i++;
    }
    return posicion;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1)
    {
        return;
    }
    
    size_t indice = cantidad - 1;
    for (size_t i = 0; i < cantidad / 2; i++)
    {
        int temporal = arreglo[i];
        arreglo[i] = arreglo[indice - i];
        arreglo[indice - i] = temporal;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if (cantidad <= 1)
    {
        return true;
    }
    else if (arreglo == NULL)
    {
        return false;
    }    

    bool esta_ordenado = true;
    for (size_t i = 0; i < cantidad - 1; i++)
    {
        if (arreglo[i] > arreglo[i + 1])
        {
            esta_ordenado = false;
        }
    }

    return esta_ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    int ocurrencias = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            ocurrencias++;
        }
    }
    return ocurrencias;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t eliminados = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == valor)
        {
            eliminados++;
            for (size_t j = i; j < cantidad - 1; j++)
            {
                arreglo[j] = arreglo[j+1];
            }
        }
    }
    for(size_t i = (cantidad - eliminados); i < cantidad; i++)
    {
        arreglo[i] = 0;
    }

    return eliminados;
}

size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, 
                        const int segundo[], size_t cantidad_dos, 
                        int destino[], size_t capacidad)
{
    if (arreglo_ordenado(primero, cantidad_uno) == false || 
        arreglo_ordenado(segundo, cantidad_dos) == false)
    {
        return 0;
    }
    if (cantidad_uno + cantidad_dos > capacidad)
    {
        return 0;
    }

    // https://www.geeksforgeeks.org/c/c-program-for-merge-sort/
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < cantidad_uno && j < cantidad_dos)
    {
        if (primero[i] <= segundo[j])
        {
            destino[k] = primero[i];
            i++;
        }
        else
        {
            destino[k] = segundo[j];
            j++;
        }
        k++;
            }
    while (i < cantidad_uno)
    {
        destino[k] = primero[i];
        i++;
        k++;
    }
    while (j < cantidad_dos)
    {
        destino[k] = segundo[j];
        j++;
        k++;
    }

    return k;
}