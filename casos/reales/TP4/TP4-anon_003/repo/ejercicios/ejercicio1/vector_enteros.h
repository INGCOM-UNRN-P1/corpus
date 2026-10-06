#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



/**
 * @brief clonar_arreglo_enteros 
 *        crea una copia de un puntero dado a otro con memoria dinamica
 *        reserva bloque de memoria con malloc.
 * 
 * @param origen, puntero de donde se copia
 * @param cantidad de enteros ena rreglo.
 * @return null si origen es null, cantidad =0, o falla malloc.
 * 
 * @return destino como nuevo puntero
 * 
 * 
 * -------------------------------------------
 * 
 * @brief filtrar_arreglo_pares
 *        chequea la cantidad de pares en un arreglo, cuenta , y los mete en un nuevo
 *          puntero.
 * @param origen puntero donde se analizara. no debe ser null
 * @param cantidad_origen cantidad de elementos de origen
 * @param cantidad_pares donde se guardan los pares enc aso de encontrarlos.
 * 
 * @return puntero al nuevo arrego con pares.
 * @return asi parametros son invalids, falla malloc o no ha pares retorna null/
 * 
 * 
 */

int *clonar_arreglo_enteros(const int *origen, size_t cantidad);
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
