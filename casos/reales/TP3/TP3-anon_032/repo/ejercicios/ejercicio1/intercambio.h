#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Ordena dos numeros enteros que se pasan por puntero.
 * @param menor El puntero al primer numero, que sera el mas chico.
 * @param mayor El puntero al segundo numero, que sera el mas grande.
 * @pre Los punteros menor y mayor deben no deben ser nulos.
 * @post De ser menor mas grande que mayor se intercambiaran los valores a los que
 * apunta cada puntero.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief  Ordena tres valores de modo que queden ordenados ascendentemente.
 * @param a El puntero al primer numero a ordenar, sera el mas chico.
 * @param b El puntero al segundo numero a ordenar, sera el del medio.
 * @param c El puntero al tercer numero a ordenar, sera el mas grande.
 * @pre Los punteros no deben ser nulos.
 * @post Se asegurara que el orden de los punteros sea a <= b <= c intercambiando
 * sus valores.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma acumulada de los elementos de un arreglo y guarda la
 * suma en resultado.
 * @param arreglo EL arreglo a sumar.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @param resultado Un puntero a un long long donde se guardara el resultado.
 * @pre Ninguno de los punteros debe ser nulo y cantidad no debe ser cero. La suma
 * total de los elementos no debe sobrepasar los limites de long long.
 * @post Se guarda el resultado en de la suma en la variable apuntada por resultado.
 * @returns Retorna true si pudo efectuar el cálculo, o false si arreglo o
 *    resultado son NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
