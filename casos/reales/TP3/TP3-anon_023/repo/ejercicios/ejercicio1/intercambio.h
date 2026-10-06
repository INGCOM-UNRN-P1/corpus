/**
 * @file intercambio.h
 * @brief Funciones de ordenamiento por referencia y sumatoria acumulada con punteros.
 *
 * Ejercicio 1 - Trabajo Practico 3
 * Programacion 1 - Universidad Nacional de Rio Negro
 */

#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Asegura que el valor apuntado por `menor` sea menor o igual al apuntado por `mayor`.
 *
 * Compara los valores desreferenciados y delega la permutacion en la funcion
 * `intercambiar` provista por libpunteros si se encuentran fuera de orden.
 *
 * @pre Ambos punteros deben apuntar a variables enteras validas si no son NULL.
 * @post Si ambos punteros son validos, *menor <= *mayor. Si alguno es NULL, no produce cambios.
 *
 * @param[in, out] menor Puntero a la variable que debe almacenar el valor inferior.
 * @param[in, out] mayor Puntero a la variable que debe almacenar el valor superior.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros en forma ascendente (*a <= *b <= *c).
 *
 * Realiza un ordenamiento por red de comparaciones invocando consecutivamente a `ordenar_par`.
 *
 * @pre Los punteros deben apuntar a memoria modificable si no son NULL.
 * @post Si los tres punteros son no nulos, *a <= *b <= *c con los mismos elementos originales.
 *       Si alguno de los tres punteros es NULL, la funcion retorna sin modificar las posiciones.
 *
 * @param[in, out] a Puntero al primer valor entero.
 * @param[in, out] b Puntero al segundo valor entero.
 * @param[in, out] c Puntero al tercer valor entero.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma acumulada de una secuencia de enteros mediante aritmetica de punteros.
 *
 * Itera el bloque de memoria contigua sin emplear operadores de indexacion, escribiendo
 * el total acumulado en la variable de salida apuntada por `resultado`.
 *
 * @pre El puntero `arreglo` debe apuntar a un bloque continuo de al menos `cantidad` enteros si cantidad > 0.
 * @pre El puntero `resultado` debe apuntar a una variable long long valida y modificable.
 * @post Si la operacion es exitosa, `*resultado` almacena la sumatoria de los elementos (o 0 si cantidad == 0).
 *       El arreglo de origen permanece inalterado.
 *
 * @param[in] arreglo Puntero de lectura al inicio de la secuencia de enteros.
 * @param[in] cantidad Cantidad de elementos validos en el arreglo.
 * @param[out] resultado Puntero donde se escribira la sumatoria final calculada.
 *
 * @return true si el calculo se realizo y se guardo el valor, false si `arreglo` es NULL
 *         (y cantidad > 0) o si `resultado` es NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
