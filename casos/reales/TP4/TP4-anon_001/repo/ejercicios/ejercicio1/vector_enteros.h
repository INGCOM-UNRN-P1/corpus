#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include "vector.h"
#include <stdbool.h>
#include <stddef.h>

/**  =========================================================================
 * Ejercicio 1: Gestión de Arreglos Dinámicos de Enteros sin Structs
 * =========================================================================
 * Consigna:
 * El estudiante debe definir los prototipos y documentación Doxygen completa
 * para:
 *
 * 1. clonar_arreglo_enteros: recibe const int *origen y size_t cantidad.
 *    Reserva memoria dinámica en el heap mediante malloc/calloc y copia los
 *    elementos de origen.Retorna el nuevo puntero int*, o NULL si origen es
 *    NULL, cantidad es 0 o falla la memoria.
 */

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
 * 2. filtrar_arreglo_pares: recibe const int *origen, size_t cantidad_origen,
 *    y un puntero de salida size_t *cantidad_pares.
 *    Cuenta cuántos números pares existen, reserva en el heap la cantidad
 * exacta necesaria de enteros, copia los pares y actualiza *cantidad_pares.
 *    Retorna el puntero al nuevo bloque en heap, o NULL si no hay pares o ante
 * error.
 * =========================================================================
 */

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
