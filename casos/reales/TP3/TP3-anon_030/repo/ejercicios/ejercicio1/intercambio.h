#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Ordena dos valores enteros de menor a mayor.
 *
 * @param menor Puntero al primer valor.
 * @param mayor Puntero al segundo valor.
 *
 * @pre Los punteros deben apuntar a variables enteras válidas.
 * @post El valor apuntado por menor será menor o igual al apuntado por mayor.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros de menor a mayor.
 *
 * @param a Puntero al primer valor.
 * @param b Puntero al segundo valor.
 * @param c Puntero al tercer valor.
 *
 * @pre Los punteros deben apuntar a variables enteras válidas.
 * @post Los valores quedan ordenados de forma ascendente: *a <= *b <= *c.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Suma todos los elementos de un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param resultado Puntero donde se guarda la suma.
 *
 * @pre arreglo y resultado no deben ser NULL.
 * @post resultado contiene la suma de todos los elementos.
 *
 * @return true si la operación fue correcta.
 * @return false si arreglo o resultado son NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 