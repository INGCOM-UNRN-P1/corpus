#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"
/**
 * @brief Operaciones de ordenamiento y acumulación mediante punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

/**
 * @brief Ordena dos valores enteros de menor a mayor.
 *
 * Si los punteros son válidos, garantiza que el valor apuntado por
 * 'menor' sea menor o igual al valor apuntado por 'mayor'.
 * El intercambio de valores debe realizarse mediante la función
 * intercambiar() de libpunteros.
 *
 * @param menor Puntero al primer valor entero.
 * @param mayor Puntero al segundo valor entero.
 *
 * @pre Ninguna.
 *
 * @post Si alguno de los punteros es NULL, no se modifica ningún valor.
 * @post Si ambos punteros son válidos, *menor <= *mayor.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros de menor a mayor.
 *
 * Si los tres punteros son válidos, ordena los valores de forma ascendente.
 * Si alguno de los punteros es NULL, no modifica ningún valor.
 *
 * @param a Puntero al primer valor entero.
 * @param b Puntero al segundo valor entero.
 * @param c Puntero al tercer valor entero.
 *
 * @pre Ninguna.
 *
 * @post Si alguno de los punteros es NULL, no se modifica ningún valor.
 * @post Si los tres punteros son válidos, *a <= *b <= *c.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma de los elementos de un arreglo.
 *
 * Recorre el arreglo exclusivamente mediante aritmética de punteros
 * y almacena la suma acumulada en la dirección indicada por 'resultado'.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param resultado Puntero donde se almacenará la suma.
 *
 * @pre Ninguna.
 *
 * @post Si 'arreglo' o 'resultado' es NULL, retorna false.
 * @post Si 'arreglo' y 'resultado' son válidos, almacena la suma de
 *       los elementos en *resultado y retorna true.
 * @post Si cantidad == 0 y los punteros son válidos, almacena 0
 *       en *resultado y retorna true.
 *
 * @return true si pudo realizar el cálculo, false si 'arreglo' o
 *         'resultado' es NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 