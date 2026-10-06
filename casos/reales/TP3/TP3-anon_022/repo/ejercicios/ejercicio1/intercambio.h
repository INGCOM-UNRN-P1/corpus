#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Ordena dos enteros de modo que el valor apuntado por 'menor'
 *        sea menor o igual que el apuntado por 'mayor'.
 *
 * @pre Si 'menor' no es NULL, debe apuntar a un entero válido.
 *      Si 'mayor' no es NULL, debe apuntar a un entero válido.
 *
 * @post Si ambos punteros son válidos, se cumple *menor <= *mayor.
 *       Si alguno de los punteros es NULL, no se modifica ningún valor.
 *
 * @param menor Puntero al valor que debe quedar como el menor.
 * @param mayor Puntero al valor que debe quedar como el mayor.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres enteros de forma ascendente, de modo que
 *        *a <= *b <= *c.
 *
 * @pre Si 'a' no es NULL, debe apuntar a un entero válido.
 *      Si 'b' no es NULL, debe apuntar a un entero válido.
 *      Si 'c' no es NULL, debe apuntar a un entero válido.
 *
 * @post Si los tres punteros son válidos, se cumple *a <= *b <= *c.
 *       Si alguno de los punteros es NULL, no se modifica ningún valor.
 *
 * @param a Puntero al primer valor.
 * @param b Puntero al segundo valor.
 * @param c Puntero al tercer valor.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma de los elementos de un arreglo mediante
 *        aritmética de punteros.
 *
 * @pre Si 'arreglo' no es NULL, debe apuntar a 'cantidad' enteros válidos.
 *      Si 'resultado' no es NULL, debe apuntar a una variable long long válida.
 *
 * @post Si 'arreglo' y 'resultado' no son NULL, *resultado contiene
 *       la suma de los 'cantidad' elementos del arreglo.
 *       Si 'arreglo' o 'resultado' es NULL, no se modifica 'resultado'.
 *
 * @param arreglo de enteros cuyos elementos se suman.
 * @param cantidad de elementos válidos del arreglo.
 * @param resultado Puntero donde se almacena la suma calculada.
 *
 * @return true si se pudo realizar el cálculo.
 *         false si 'arreglo' o 'resultado' es NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 