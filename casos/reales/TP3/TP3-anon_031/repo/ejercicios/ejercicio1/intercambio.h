#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Ordena dos valores enteros de menor a mayor.
 *
 * Compara los valores apuntados por menor y mayor. Si están desordenados,
 * utiliza intercambiar de libpunteros para corregir su orden.
 *
 * @param menor Puntero al valor que debe quedar como el menor.
 * @param mayor Puntero al valor que debe quedar como el mayor.
 *
 * @pre Los punteros pueden ser NULL.
 *
 * @post Si ambos punteros son válidos, se cumple *menor <= *mayor.
 * Si alguno es NULL, la función no realiza ningún cambio.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros en forma ascendente.
 *
 * Ordena los valores apuntados por a, b y c mediante llamadas sucesivas
 * a ordenar_par.
 *
 * @param a Puntero al primer valor.
 * @param b Puntero al segundo valor.
 * @param c Puntero al tercer valor.
 *
 * @pre Los punteros pueden ser NULL.
 *
 * @post Si los tres punteros son válidos, se cumple *a <= *b <= *c.
 * Si alguno es NULL, la función no realiza ningún cambio.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma acumulada de un arreglo de enteros.
 *
 * Recorre el arreglo exclusivamente mediante aritmética de punteros y
 * almacena el resultado de la suma en la dirección apuntada por resultado.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos a sumar.
 * @param resultado Puntero donde se almacenará la suma.
 *
 * @return true si la operación pudo realizarse.
 * @return false si arreglo o resultado son NULL.
 *
 * @pre Si cantidad es mayor que cero, arreglo debe apuntar a una secuencia
 * válida de al menos cantidad enteros.
 *
 * @post Ante éxito, *resultado contiene la suma de los elementos.
 * Si cantidad es cero, *resultado queda en cero.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
