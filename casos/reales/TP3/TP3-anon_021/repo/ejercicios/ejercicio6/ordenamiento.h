#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * Recorre un rango acotado por punteros [inicio, fin) y retorna 
 * el puntero al elemento mínimo.
 * 
 * @param inicio Puntero al inicio del rango (inclusivo).
 * @param fin Puntero al final del rango (exclusivo, semi-abierto).
 * @return const int* Puntero al elemento mínimo encontrado, o NULL si el rango 
 *         es inválido, vacío o el puntero inicial es NULL.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 *  Ordena ascendentemente un arreglo de enteros in-place mediante el 
 *  algoritmo de Selection Sort utilizando aritmética de punteros.
 * 
 * @param arreglo Puntero al primer elemento del arreglo a ordenar.
 * @param cantidad Número de elementos que contiene el arreglo.
 */
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
