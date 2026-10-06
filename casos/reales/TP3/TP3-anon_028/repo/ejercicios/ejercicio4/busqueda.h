#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca la primera aparición de un valor en un arreglo con aritmética de punteros.
 * 
 * @param arreglo Puntero al inicio del arreglo.
 * @param cantidad Número de elementos en el arreglo.
 * @param valor Valor entero a buscar.
 * @return const int* Puntero a la posición exacta del elemento, o NULL si no existe o es inválido.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula el índice o distancia relativa entre el inicio y un elemento.
 * 
 * @param inicio Puntero al inicio del arreglo.
 * @param elemento Puntero a un elemento interno del arreglo.
 * @return long Distancia en cantidad de elementos, o -1 si alguna dirección es NULL o inválida.
 */
long distancia_punteros(const int *inicio, const int *elemento);

#endif 
