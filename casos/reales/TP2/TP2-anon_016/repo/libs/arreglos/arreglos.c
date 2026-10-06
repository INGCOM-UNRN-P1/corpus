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
    if(arreglo == NULL || cantidad == 0 )
    return 0;

    long long suma = 0;

    for(size_t i = 0; i < cantidad; i++)
    {   
        suma+= arreglo[i]; 
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
     if(arreglo == NULL || cantidad == 0 )
    return -1;

    for(size_t i = 0; i < cantidad; i++)
    {
        if(arreglo[i] == buscado)
        return (int)i;
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    
     if(arreglo == NULL || cantidad == 0 )
    return;

    size_t izquierda = 0;
    size_t derecha = cantidad -1;

    while (izquierda < derecha)
    {
        int temporal = arreglo[izquierda];
        arreglo[izquierda] = arreglo [derecha];
        arreglo [derecha] = temporal;

        izquierda++;
        derecha--;
    }
}
   

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if(arreglo == NULL)
    {   
        return false;
    }

    if (cantidad <= 1)
    {
        return true;
    }

    for (size_t i = 0; i < cantidad -1; i++)
    {
        if (arreglo[i]>arreglo[i+1])
        return false;
    }
    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
     if(arreglo == NULL || cantidad == 0 )
    return 0;

    size_t contador = 0;

    for(size_t i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == buscado)
        contador ++;
    }
    return contador;
   
}

size_t arreglo_compactar(int arreglo [], size_t cantidad, int valor)
{
    if(arreglo == NULL || cantidad == 0)
    return 0;

    size_t escritura = 0;

    for(size_t lectura = 0; lectura < cantidad; lectura++)
    {
        if(arreglo[lectura] != valor)
        {
            arreglo[escritura] = arreglo[lectura];
            escritura++;
        }
    }
    return escritura;

}




 size_t arreglo_fusionar(const int primero[], size_t cantidad_uno,
                        const int segundo[], size_t cantidad_dos,
                        int destino[], size_t capacidad)
{
    if (destino == NULL || capacidad == 0)
    return 0;

    if(primero == NULL)
    {
        cantidad_uno = 0;
    }
    if(segundo == 0)
    {
        cantidad_dos = 0;
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    
    while(i < cantidad_uno && j < cantidad_dos && k < capacidad)
    {
        if(primero[i] <= segundo[j])
        {
            destino[k++] = primero[i++];
        }
        else
        {
            destino[k++] = segundo[j++];
        }
    }

    while (i < cantidad_uno && k < capacidad)
    {
        destino[k++] = primero[i++];
    }

    while(j < cantidad_dos && k < capacidad)
    {
        destino[k++] = segundo[j++];
    }

    return k;
}

