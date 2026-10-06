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
    long long suma = 0LL;

    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            suma += arreglo [i];
        }
    }
    

    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int indice_encontrado = -1;
    bool encontrado = false;

    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad && !encontrado; i++)
        {
            if (arreglo[i] == buscado)
            {
                indice_encontrado = i;
                encontrado = true;
            }
        }
    }
    
    return indice_encontrado;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    
    if (arreglo != NULL && cantidad > 1)
    {
        size_t limite = cantidad / 2;

        for (size_t i = 0; i < limite; i++)
        {
            size_t j = cantidad - 1 - i;
            int temporal = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temporal;
        }
        
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    
    bool esta_ordenado = false;

    if (arreglo != NULL)
    {
        if (cantidad < 1)
        {
            esta_ordenado = true;
        } 
        else
        {
            esta_ordenado = true;

            for (size_t i = 0; i < cantidad - 1 && esta_ordenado; i++)
            {
                if (arreglo[i] > arreglo[i + 1])
                {
                    esta_ordenado = false;
                }
            }
        }
    }

    return esta_ordenado;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    
    size_t contador = 0;

    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
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
    size_t nueva_cantidad = 0;

    if (arreglo!= NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] != valor)
            {
                arreglo[nueva_cantidad] = arreglo[i];
                nueva_cantidad++;
            }
        }
    }
}




size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    if (destino != NULL && capacidad > 0)
    {
        while (i < cantidad_uno && j < cantidad_dos && k < capacidad)
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
        while (i < cantidad_uno && k < capacidad) 
        {   
            destino[k] = primero[i]; 
            i++; 
            k++; 
        }

        while (j < cantidad_dos && k < capacidad)
        { 
            destino[k] = segundo[j];
            j++;
            k++; 
        }
    }

    return k;
}