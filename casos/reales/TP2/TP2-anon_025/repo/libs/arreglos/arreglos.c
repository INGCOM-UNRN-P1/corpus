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
    for (size_t i = 0; i < cantidad; i ++)
    {
        suma = suma + arreglo[i];
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

    size_t inicio = 0;
    size_t fin = cantidad -1;
    while (inicio < fin)
    {
        int temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temporal;
        inicio++;
        fin--;
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
    size_t contador = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        {
            contador++;
        }
    }
    return contador;
}





 size_t arreglo_fusionar(const int primero[], size_t cantidad_primero, const int segundo[], size_t cantidad_segundo, int destino[], size_t capacidad_destino)
{
    if (destino == NULL || capacidad_destino == 0)
    {
        return 0;
    }
    if (primero == NULL) cantidad_primero = 0;
    {
        cantidad_primero = 0;
    }
    if (segundo == NULL) cantidad_segundo = 0;
    {
        cantidad_segundo = 0;
    }

    size_t indice_primero = 0;
    size_t indice_segundo = 0;
    size_t indice_destino = 0;

    while (indice_primero < cantidad_primero && indice_segundo < cantidad_segundo && indice_destino < capacidad_destino)
    {
        if (primero[indice_primero] <= segundo[indice_segundo])
        {
            destino[indice_destino] = primero[indice_primero];
            indice_primero++;
        }
        else
        {
            destino[indice_destino] = segundo[indice_segundo];
            indice_segundo++;
        }
        indice_destino++;
    }
    while (indice_primero < cantidad_primero && indice_destino < capacidad_destino)
    {
        destino[indice_destino] = primero[indice_primero];
        indice_primero++;
        indice_destino++;
    }
    while (indice_segundo < cantidad_segundo && indice_destino < capacidad_destino)
    {
        destino[indice_destino] = segundo[indice_segundo];
        indice_segundo++;
        indice_destino++;
    }
    return indice_destino;
}