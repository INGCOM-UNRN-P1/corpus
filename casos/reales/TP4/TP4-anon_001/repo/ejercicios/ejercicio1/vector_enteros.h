#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include "vector.h"
#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Clona un arreglo de enteros en un nuevo bloque de memoria dinámica.
 *
 * Reserva memoria en el heap (mediante malloc o calloc) y copia los elementos
 * del arreglo 'origen'.
 *
 * @param origen Puntero al arreglo de enteros fuente.
 * @param cantidad Cantidad de elementos 'int' a copiar.
 *
 * @return Puntero al nuevo arreglo de enteros en el heap, o NULL si 'origen' es
 * NULL, 'cantidad' es 0 o si falla la reserva de memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);



/**
 * @brief Filtra los números pares de un arreglo de enteros y los almacena en
 *        un nuevo bloque de memoria dinámica.
 *
 * Cuenta la cantidad de números pares en 'origen', reserva la memoria exacta
 * en el heap para alojarlos, copia únicamente dichos elementos y actualiza
 * el parámetro de salida 'cantidad_pares' con el total encontrado.
 *
 * @param origen Puntero al arreglo de enteros fuente.
 * @param cantidad_origen Cantidad total de elementos en el arreglo 'origen'.
 * @param cantidad_pares Puntero de salida donde se registrará la cantidad de
 * pares hallados.
 *
 * @return Puntero al nuevo arreglo de enteros pares en el heap,
 *         o NULL si 'origen' es NULL, 'cantidad_origen' es 0, 'cantidad_pares'
 * es NULL, no se encontraron números pares, o si falla la reserva de memoria.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);

#endif 
