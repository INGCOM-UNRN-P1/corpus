#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Encuentra el puntero al elemento mínimo en un rango de memoria.
 * 
 * @pre Los punteros 'inicio' y 'fin' no deben ser nulos, y 'inicio' debe ser menor a 'fin'.
 * @post Se devuelve un puntero al menor valor encontrado.
 * 
 * @param inicio Puntero constante al inicio del rango (inclusivo).
 * @param fin Puntero constante al final del rango (exclusivo).
 * @return const int* Puntero al valor mínimo, o NULL si el rango es inválido.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena un arreglo de enteros usando el algoritmo de Selección con punteros.
 * 
 * @pre El puntero 'arreglo' no debe ser nulo y 'cantidad' debe ser mayor a 0.
 * @post Los elementos del arreglo quedan ordenados de forma ascendente in-place.
 * 
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Número total de elementos en el arreglo.
 * @return true si el ordenamiento fue exitoso, false si el arreglo es nulo o vacío.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 