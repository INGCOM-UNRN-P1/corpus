#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



/**
 * @brief Reserva memoria dinámica en el heap y copia los elementos del arreglo origen.
 * 
 * @param origen Puntero al arreglo constante de enteros.
 * @param cantidad Número de elementos a copiar.
 * @return int* Puntero al nuevo arreglo en heap, o NULL si origen es NULL, cantidad es 0 o falla la memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra los números pares de un arreglo y los guarda en un nuevo bloque dinámico.
 * 
 * @param origen Puntero al arreglo constante de enteros.
 * @param cantidad_origen Número de elementos del arreglo origen.
 * @param cantidad_pares Puntero de salida donde se guardará la cantidad de números pares encontrados.
 * @return int* Puntero al nuevo bloque dinámico con los pares, o NULL si no hay pares o ante un parámetro inválido.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
