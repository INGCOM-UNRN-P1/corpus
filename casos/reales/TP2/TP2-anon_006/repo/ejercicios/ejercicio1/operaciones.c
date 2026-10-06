/**
 * @file operaciones.c
 * @brief Implementación de operaciones sobre arreglos de enteros.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include "operaciones.h"
#include "arreglos.h"


double calcular_promedio(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0) {
        return 0.0;
    }
    
    double suma = (double)arreglo_sumar(arreglo, cantidad);
    return suma / (double)cantidad;
}


bool contiene_valor(const int arreglo[], size_t cantidad, int valor)
{
    if (arreglo == NULL || cantidad == 0) {
        return false;
    }
    
    return arreglo_buscar(arreglo, cantidad, valor) != -1;
}