/**
 * @file ordenamiento.h
 * @brief Funciones de ordenamiento por seleccion empleando aritmetica de punteros.
 *
 * Ejercicio 6 - Trabajo Practico 3
 * Programacion 1 - Universidad Nacional de Rio Negro
 */

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Localiza el elemento minimo dentro de un rango de memoria contigua.
 *
 * Trabaja sobre un rango semiabierto [inicio, fin) desplazando punteros.
 *
 * @pre `inicio` y `fin` deben delimitar un rango contiguo valido si inicio != NULL y fin != NULL.
 * @post No altera los elementos del arreglo.
 *
 * @param[in] inicio Puntero al primer elemento del rango.
 * @param[in] fin Puntero al limite superior (no inclusivo) del rango.
 *
 * @return Puntero constante (const int *) a la direccion del elemento minimo,
 *         o NULL si inicio es NULL, fin es NULL o si inicio >= fin.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena ascendentemente un arreglo de enteros aplicando el algoritmo de seleccion.
 *
 * En cada paso identifica la direccion del menor elemento restante con `buscar_puntero_minimo`
 * y efectua el intercambio in-place usando punteros sin el operador [].
 *
 * @pre `arreglo` debe apuntar a un bloque modificable de al menos `cantidad` enteros si cantidad > 0.
 * @post Si la ejecucion es exitosa, el arreglo queda ordenado de menor a mayor.
 *
 * @param[in, out] arreglo Puntero al inicio del bloque de memoria a ordenar.
 * @param[in] cantidad Cantidad de elementos enteros en el arreglo.
 *
 * @return true si el ordenamiento fue realizado o si cantidad <= 1,
 *         false si `arreglo` es NULL con cantidad > 0.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
