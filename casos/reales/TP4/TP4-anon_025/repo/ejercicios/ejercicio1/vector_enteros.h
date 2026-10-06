#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



/**
 * @brief Clona un arreglo de enteros reservando memoria dinamica exacta.
 * 
 * @param origen Puntero al arreglo de solo lectura a clonar.
 * @param cantidad Cantidad de elementos en el arreglo original.
 * 
 * @return int* Puntero al nuevo arreglo en el heap, o NULL falla.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra los numeros pares de un arreglo y los guarda en un nuevo bloque dinamico
 * 
 * @param origen Puntero al arreglo original
 * @param cantidad_origen Cantidad de elementos a evaluar.
 * @param cantidad_pares Puntero de salida donde se guardara la cantidad de pares encontrados
 * 
 * @return int* Puntero al nuevo arreglo con los pares en el heap, o NULL si no hay pares o hay un error.
 */

#endif 
