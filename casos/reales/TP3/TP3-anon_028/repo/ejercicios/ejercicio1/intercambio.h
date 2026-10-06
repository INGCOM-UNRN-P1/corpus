#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Ordena dos valores enteros de forma ascendente.
 *
 * @param menor Puntero al entero que contendrá el menor valor.
 * @param mayor Puntero al entero que contendrá el mayor valor.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros de forma ascendente (*a <= *b <= *c).
 *
 * @param a Puntero al primer valor.
 * @param b Puntero al segundo valor.
 * @param c Puntero al tercer valor.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Suma acumulada de un arreglo utilizando aritmética de punteros pura.
 *
 * @param arreglo Puntero al inicio del arreglo.
 * @param cantidad Número de elementos.
 * @param resultado Puntero a variable donde se almacenará la suma.
 * @return true si la suma fue calculada con éxito, false si arreglo o resultado son NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
