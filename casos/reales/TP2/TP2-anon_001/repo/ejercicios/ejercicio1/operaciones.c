/**
 * @file operaciones.c
 * @brief Implementación de operaciones sobre arreglos de enteros.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Esqueleto a ser completado por los estudiantes.
 */

#include "operaciones.h"
#include "arreglos.h"


double calcular_promedio(const int arreglo[], size_t cantidad)
{
    double promedio = 0.0;
    if((arreglo != NULL) && (cantidad != 0))
    {
        promedio = (double)arreglo_sumar(arreglo, cantidad) / cantidad;
    }
    return promedio;
}


bool contiene_valor(const int arreglo[], size_t cantidad, int valor)
{
    bool encontrado = false;
    if ((arreglo != NULL) && (cantidad != 0))
    {
        if (arreglo_buscar(arreglo, cantidad, valor) != -1)
        {
            encontrado = true;
        }

    }
    return encontrado;
}
