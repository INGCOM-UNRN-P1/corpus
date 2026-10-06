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
    if (arreglo == NULL || cantidad == 0)
    {
        return 0; 
    }
    
    for (size_t i = 0; i < cantidad; i++)
    {
        suma = suma + arreglo[i];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    int resultado = -1;
    if (arreglo != NULL && cantidad > 0)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if (arreglo[i] == buscado && resultado == -1)
            {
                resultado = i;
            }
        }
    }
    return resultado;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    int intercambio = 0;//Variable temporal  para guardar por un momento el valor de un elemento durante el intercambio.
    if (arreglo == NULL || cantidad <= 1)
    {
    }
    for (size_t i = 0; i < cantidad / 2 ; i++)//detenerme antes de la mitad al intercambiar
    {
        intercambio = arreglo[i];   
        arreglo[i]= (arreglo[cantidad -1 -i]);//copio valor del extremo opuesto
        arreglo[cantidad - 1 - i] = intercambio;//pongo el guardado en la derecha
    }
    
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    bool resultado = true;
    if (arreglo == NULL) 
    {
        resultado = false;
    }
    else if(cantidad > 1)
    {
        for (size_t i=0 ; i < cantidad -1; i++)//Recorro mi arreglo
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
    size_t ocurrencia = 0;
    if (arreglo == NULL || cantidad == 0)
    {
    }
    else if (cantidad > 0)
    {
        for (size_t i = 0; i < cantidad ; i++)
        {
            if (buscado == arreglo[i])
            {
                ocurrencia = ocurrencia + 1;
            }
        }
    }
    return ocurrencia;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    size_t nueva_cantidad = 0;
    if (arreglo == NULL || cantidad == 0)
    {
    }
    else
    {
        for (size_t i = 0; i < cantidad ; i++)
        {
            if (arreglo[i] != valor)
            {
                arreglo[nueva_cantidad]= arreglo[i];
                nueva_cantidad = nueva_cantidad +1;
            } 
        }
    }
    return nueva_cantidad;
}




size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad)
{
    size_t indice_destino = 0 ; //cuantos elementos escribo en total en el arreglo final
    if (primero == NULL || segundo == NULL || destino == NULL || capacidad < (cantidad_uno + cantidad_dos))
    {
        indice_destino = 0;
    }
    else
    {
        size_t indice_primero = 0;
        size_t indice_segundo = 0;

        while (indice_primero < cantidad_uno && indice_segundo< cantidad_dos)
        {
            if (primero[indice_primero] <= segundo[indice_segundo])
            {
                destino[indice_destino] = primero[indice_primero];
                indice_primero= indice_primero + 1;
            }
            else
            {
                destino[indice_destino] = segundo[indice_segundo];
                indice_segundo = indice_segundo + 1;
            }
            indice_destino = indice_destino+1;
        }
        while (indice_primero < cantidad_uno)
        {
            destino[indice_destino] = primero[indice_primero];
            indice_primero = indice_primero + 1;
            indice_destino = indice_destino + 1;
        }
        
        while (indice_segundo < cantidad_dos)
        {
            destino[indice_destino] = segundo[indice_segundo];
            indice_segundo = indice_segundo + 1 ;
            indice_destino = indice_destino + 1;
        }    
    }

   return indice_destino; 
}