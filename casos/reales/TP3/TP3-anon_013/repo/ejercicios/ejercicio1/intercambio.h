#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**
 * @brief ordena un par de punteros para que la posición apuntada por 'menor'
 * contenga un valor menor a la apuntada por 'mayor'.
 * @param menor es el puntero del valor menor.
 * @param mayor es el puntero del valor mayor.
 * 
 * @pre si los punteros son NULL no opera. Si no son NULL deben apuntar a un entero
 * válido.
 * 
 * @post si los punterós son válidos y 'menor' > 'mayor' hace el intercambio.
 * @post si los punteros son válidos y 'menor' <= 'mayor' no opera.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief recibe tres punteros a entero (int *a, int *b, int *c).
 * Ordena los tres valores de modo que queden ordenados ascendentemente (*a <= *b <= *c).
 * @param a es el puntero al primer valor.
 * @param b es el puntero al segundo valor.
 * @param c es el puntero al tercer valor.
 * 
 * @pre a, b y c deben ser punteros válidos y accesibles.
 * 
 * @post ordena los valores de modo que *a <= *b <= *c.
 * @post si los punteros no son válidos, no opera. 
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma acumulada de los elementos de un arreglo
 * y almacena el total en la dirección apuntada por 'resultado'.
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @param resultado es el puntero hacia donde se almacena el resultado.
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * 
 * @post almacena el resultado de la suma de los elementos del arreglo en
 * la dirección asociada a 'resultado.
 * 
 * @return true si pudo efectuar el cálculo, o false si arreglo o
 * resultado son NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);
#endif 
