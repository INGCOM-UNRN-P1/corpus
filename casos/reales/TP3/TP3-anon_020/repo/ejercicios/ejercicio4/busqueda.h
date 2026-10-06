#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca la primera coincidencia de un valor dentro de un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Valor a buscar.
 *
 * @return Puntero a la primera coincidencia, o NULL si no existe o si el arreglo
 *         es NULL.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula la distancia relativa entre dos punteros dentro del mismo arreglo.
 *
 * @param inicio Puntero al inicio del arreglo.
 * @param elemento Puntero a un elemento dentro del arreglo.
 *
 * @return Distancia en elementos desde inicio hasta elemento, o -1 si alguno es
 *         NULL o si elemento está antes que inicio.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
