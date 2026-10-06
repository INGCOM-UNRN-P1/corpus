#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



/**
 *      -Recibe const int *origen y size_t cantidad.
 * 
 *      -Reserva memoria dinámica en el heap mediante malloc/calloc y 
 * 
 *      -copia los elementos de origen. 
 * 
 *      -Retorna el nuevo puntero int*, o NULL si origen es NULL, cantidad es 0 o falla la memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 *      -Recibe const int *origen, size_t cantidad_origen, y un puntero de salida size_t *cantidad_pares.
 *      
*       -Cuenta cuántos números pares existen, 
 * 
 *      -reserva en el heap la cantidad exacta necesaria de enteros, 
 * 
 *      -copia los pares y actualiza *cantidad_pares.
 * 
 *      -Retorna el puntero al nuevo bloque en heap, o NULL si no hay pares o ante error.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);
#endif 
