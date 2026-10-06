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
    size_t indice = 0;
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    
    for (indice = 0; indice < cantidad; indice++)
    {
        suma = suma + arreglo[indice];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t indice = 0;
    if (arreglo_buscar == NULL || arreglo == 0)
    {
        return -1;
    }
    
    for (indice = 0; indice < cantidad; indice++)
    {
        if (arreglo[indice] == buscado)
        {
            return indice;
        }
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    size_t indice = 0;
    size_t final = 0;
    size_t inicio = 0;
    int auxiliar = 0;
    if (arreglo == NULL || cantidad < 2)
    {
        return;
    }
    for (indice = 0; indice < cantidad / 2; indice++)
    {
        final = (cantidad - 1) - indice;
        inicio = indice;
        auxiliar = arreglo[inicio];       
        arreglo[inicio] = arreglo[final]; 
        arreglo[final] = auxiliar;        
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    size_t indice = 0;
    if (arreglo == NULL)
    {
        return false;
    }
    if (cantidad <= 1)
    {
        return true;
    }
    for (indice = 0; indice < cantidad - 1; indice++)
    {
        if (arreglo[indice] > arreglo[indice + 1])
        {
            return false;
        }
    }
    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    int contador = 0;
    size_t indice = 0;
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    for (indice = 0; indice < cantidad; indice++)
    {
        if (arreglo[indice] == buscado)
            contador++;
    }
    return contador;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t indice = 0;
    size_t escribo = 0;
    if (arreglo == NULL || cantidad == 0)
    {
        return 0;
    }

    for (indice = 0; indice < cantidad; indice++)
    {
        if (arreglo[indice] != valor)
        {
            arreglo[escribo] = arreglo[indice];
            escribo++;
        }
    }
    return escribo;
}
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno,
                        const int segundo[], size_t cantidad_dos,
                        int destino[], size_t capacidad)
{
    size_t indice1 = 0;
    size_t indice2 = 0;
    size_t indice3 = 0;
    if (primero == 0 || segundo == 0 || destino == 0 ||
        capacidad == 0)
    {
        return 0;
    }
    while (indice1 < cantidad_uno && indice2 < cantidad_dos && indice3 
        < capacidad)
    {
        if (primero[indice1] <= segundo[indice2])
        {
            
            destino[indice3] = primero[indice1];
            indice1++;
        }
        else
        {
            destino[indice3] = segundo[indice2];
            indice2++;
        }
        indice3++;
    }
    while (indice1 < cantidad_uno && indice3 < capacidad)
        {
            destino[indice3] = primero[indice1];
            indice1++;
            indice3++;
        }
    while (indice2 < cantidad_dos && indice3 < capacidad)
        {
            destino[indice3] = segundo[indice2];
            indice2++;
            indice3++;
        }
    return indice3;
}