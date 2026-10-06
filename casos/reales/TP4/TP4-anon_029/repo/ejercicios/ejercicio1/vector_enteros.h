#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include "vector.h"
#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Copia los elementos de origen en un espacio en memoria
 *  generado por calloc.
 * @pre 'origen' no debe ser NULL.
 * @pre 'cantidad' no debe ser 0.
 * @post se devuelve la direccion de  memoria de la cadena clonada.
 * @param origen Es el arrelgo original.
 * @param cantidad Es la cantidad de elementos en el arreglo.
 * @return Devuelve el arreglo clonado.O NULL si origen es
 *  NULL, cantidad es 0 o falla la memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Cuenta cuántos números pares existen en el arreeglo.
 * @pre 'origen' no debe ser NULL.
 * @pre 'cantidad_pares' no debe ser NULL.
 * @pre 'cantidad_origen' no debe ser 0.
 * @post retorna la cantidad de elementos pares que hay en el arreglo.
 * @param origen es el arreglo original.
 * @param cantidad_origen son la cantidad de elementos en origen.
 * @param cantidad_pares son la cantidad de elementos pares que se
 *  calculan mediante un bucle.
 * @return Devuelve elementos pares que hay en el arreglo,
 *  o NULL si no hay pares o ante error.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);
#endif 
