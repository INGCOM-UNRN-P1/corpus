#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include "vector.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una copia dinámica de un arreglo de enteros.
 *
 * @param origen Arreglo de enteros a clonar.
 * @param cantidad Cantidad de elementos a copiar.
 *
 * @pre Si cantidad > 0, origen debe apuntar a un arreglo válido
 *      de al menos cantidad elementos.
 *
 * @post Si la reserva tiene éxito, retorna un nuevo bloque dinámico
 *       que contiene una copia de los primeros cantidad elementos
 *       de origen.Si origen es NULL, cantidad es 0 o falla la
 *       reserva, retorna NULL.
 *
 * @return Puntero al nuevo bloque dinámico, o NULL si falla.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra los elementos pares de un arreglo de enteros.
 *
 * @param origen Arreglo de enteros que se desea filtrar.
 * @param cantidad_origen Cantidad de elementos de origen.
 * @param cantidad_pares Puntero donde se almacena la cantidad de
 *                       elementos pares encontrados.
 *
 * @pre cantidad_pares debe ser un puntero válido y, si cantidad_origen
 *      > 0, origen debe apuntar a un arreglo válido de al menos
 *      cantidad_origen elementos.
 *
 * @post Si existen elementos pares y la reserva tiene éxito, retorna
 *       un nuevo bloque dinámico con los elementos pares y
 *       *cantidad_pares contiene su cantidad.Si no hay pares,
 *       origen es NULL, cantidad_origen es 0 o falla la reserva,
 *       retorna NULL y *cantidad_pares queda en 0.
 *
 * @return Puntero al nuevo bloque dinámico, o NULL ante error.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);
#endif 
