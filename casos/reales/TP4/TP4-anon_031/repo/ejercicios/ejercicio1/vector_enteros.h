#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stddef.h>
#include "vector.h"

/**
 * @brief Clona un arreglo de enteros en memoria dinámica.
 * @param origen Arreglo original.
 * @param cantidad Cantidad de elementos a copiar.
 * @return Copia en heap o NULL si los parámetros son inválidos o falla la reserva.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Crea un arreglo nuevo que contiene solamente los valores pares.
 * @param origen Arreglo original.
 * @param cantidad_origen Cantidad de elementos del arreglo original.
 * @param cantidad_pares Parámetro de salida con la cantidad de pares encontrados.
 * @return Bloque exacto con los pares o NULL si no hay pares o ante error.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);

/**
 * @brief Alias compatible con la consigna general: clona un bloque de enteros.
 * @param origen Bloque original.
 * @param cantidad Cantidad de elementos.
 * @return Copia dinámica o NULL ante error.
 */
int *clonar_bloque(const int *origen, size_t cantidad);

/**
 * @brief Filtra los valores estrictamente positivos de un bloque.
 * @param origen Bloque original.
 * @param cantidad_origen Cantidad de elementos originales.
 * @param cantidad_positivos Parámetro de salida con la cantidad de positivos.
 * @return Nuevo bloque exacto con los positivos o NULL si no hay positivos o ante error.
 */
int *filtrar_bloque_positivos(const int *origen, size_t cantidad_origen,
                              size_t *cantidad_positivos);

#endif 
