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

bool arreglo_ok(const int arreglo[], size_t cantidad)
{
    bool resultado = false;
    if (arreglo != NULL && cantidad >= 0)
    {
        resultado = true;
    }
    return resultado;
}

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    long long suma = 0;
    if (arreglo_ok(arreglo,cantidad))
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
    int resultado = -1;
    if (arreglo_ok(arreglo,cantidad))
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] == buscado)
            {
                resultado = i;
                i = cantidad;
            }
        }
    }
    return resultado;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    size_t contador = cantidad - 1;
    int temp;
    if (arreglo_ok(arreglo,cantidad))
    {
        if ((cantidad % 2) == 0)
        {           
            for (size_t i = 0; i < cantidad / 2; i++)
            {
                temp = arreglo[i];
                arreglo[i] = arreglo[contador];
                arreglo[contador] = temp;
                contador--;
            }
        }
        else
        {
            for (size_t i = 0; i < (cantidad - 1) / 2; i++)
            {
                temp = arreglo[i];
                arreglo[i] = arreglo[contador];
                arreglo[contador] = temp;
                contador--;
            }
        }
        
    }
    
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool resultado = true;
    if (arreglo_ok(arreglo,cantidad))
    {
        if (cantidad > 1)
        {
            for (size_t i = 0; i < cantidad - 1; i++)
            {
                if (arreglo[i] > arreglo[i + 1])
                {
                    resultado = false;
                }
            }
        }
    }
    else
    {
        resultado = false;
    }
    return resultado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;
    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i <= cantidad; i++)
        {
            if (arreglo[i] == buscado)
            {
                contador++;
            }
        }
    }
    
    return contador;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t largo_nuevo = 0;
    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] != valor)
            {
                arreglo[largo_nuevo] = arreglo[i];
                largo_nuevo++;
            }
        }
    }
    return largo_nuevo;
}

size_t arreglo_concatenar(const int primer_arreglo[], size_t capacidad_primero,
                         const int segundo_arreglo[], size_t capacidad_segundo,
                         int destino[], size_t capacidad_destino)
{
    size_t tamanio = 0;
    if (arreglo_ok(primer_arreglo, capacidad_primero) && 
        arreglo_ok(segundo_arreglo, capacidad_segundo) &&
        (capacidad_destino >= (capacidad_primero + capacidad_segundo)) &&
        arreglo_ok(destino, capacidad_destino) &&
        arreglo_ordenado(primer_arreglo, capacidad_primero) &&
        arreglo_ordenado(segundo_arreglo, capacidad_segundo))
    {
        for (size_t i = 0; i < capacidad_primero; i++)
        {
            destino[tamanio] = primer_arreglo[i];
            tamanio++;
        }
        for (size_t i = 0; i < capacidad_segundo; i++)
        {
            destino[tamanio] = segundo_arreglo[i];
            tamanio++;
        }
        while (!arreglo_ordenado(destino, tamanio) && tamanio > 1)
        {
            for (size_t i = 0; i < tamanio - 1; i++)
            {
                if (destino[i] > destino[i + 1])
                {
                    int temp = destino[i];
                    destino[i] = destino[i + 1];
                    destino[i + 1] = temp;  
                }
            }        
        }
    }
    return tamanio;
}