#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Ordena dos valores enteros para que el primero sea menor o igual al segundo.
 * 
 * @pre Los punteros 'menor' y 'mayor' no deben ser nulos.
 * @post El valor apuntado por 'menor' será menor o igual al apuntado por 'mayor'.
 *       Si algún puntero es nulo, la función no tiene efecto.
 * 
 * @param menor Puntero a la variable que almacenará el valor más chico.
 * @param mayor Puntero a la variable que almacenará el valor más grande.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros de forma ascendente (*a <= *b <= *c).
 * 
 * @pre Los punteros 'a', 'b' y 'c' no deben ser nulos.
 * @post Los valores se ordenan de menor a mayor utilizando llamadas a ordenar_par.
 *       Si algún puntero es nulo, la función no tiene efecto.
 * 
 * @param a Puntero a la primera variable (menor).
 * @param b Puntero a la segunda variable (medio).
 * @param c Puntero a la tercera variable (mayor).
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma acumulada de los elementos de un arreglo.
 * 
 * @pre El 'arreglo' y el 'resultado' no deben ser nulos.
 * @post La sumatoria total se almacena en la dirección apuntada por 'resultado'.
 *       El arreglo se recorre estrictamente con aritmética de punteros.
 * 
 * @param arreglo Puntero al inicio del arreglo a sumar.
 * @param cantidad Cantidad de elementos en el arreglo.
 * @param resultado Puntero a la variable de salida (long long) para evitar desbordamientos.
 * @return true si el cálculo se completó exitosamente.
 * @return false si 'arreglo' o 'resultado' son nulos.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 