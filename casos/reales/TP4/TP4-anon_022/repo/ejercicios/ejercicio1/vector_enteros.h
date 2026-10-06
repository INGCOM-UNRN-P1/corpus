#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"




/**
 * @brief Crea una copia dinámica de un arreglo de enteros.
 *
 * Reserva memoria en el heap para 'cantidad' enteros y copia en ella
 * los elementos de 'origen'.
 *
 * @param origen Arreglo cuyos elementos se desean copiar.
 * @param cantidad Cantidad de elementos de 'origen'.
 *
 * @return Puntero al nuevo bloque que contiene la copia,
 *         o NULL si 'origen' es NULL, 'cantidad' es cero, o falla la reserva
 *         de memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Crea un bloque dinámico con los enteros pares de un arreglo.
 *
 * Cuenta los elementos pares de 'origen', reserva en el heap la cantidad
 * exacta de enteros necesaria y copia en el nuevo bloque los valores pares,
 * conservando su orden original.
 *
 * @param origen Arreglo cuyos elementos se desean analizar.
 * @param cantidad_origen Cantidad de elementos de 'origen'.
 * @param cantidad_pares Puntero donde se almacena la cantidad de enteros pares encontrados.
 *
 * @pre 'origen' no debe ser NULL.
 * @pre 'cantidad_origen' debe ser mayor que cero.
 * @pre 'cantidad_pares' no debe ser NULL.
 *
 * @post Si se encuentran elementos pares, 'cantidad_pares' contiene
 *       la cantidad de elementos del nuevo bloque.
 *
 * @return Puntero al nuevo bloque con los elementos pares,
 *         o NULL si algún parámetro es inválido, no hay elementos pares
 *         o falla la reserva de memoria.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
