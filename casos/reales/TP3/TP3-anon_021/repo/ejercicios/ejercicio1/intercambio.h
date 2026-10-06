#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * Asegura que el primer valor sea menor o igual que el segundo.
 * 
 * @param menor Puntero al entero que debe contener el valor menor.
 * @param mayor Puntero al entero que debe contener el valor mayor.
 * 
 * @pre 'menor' y 'mayor' no deben ser NULL.
 * @post Si *menor > *mayor, se intercambian sus contenidos mediante libpunteros.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * Ordena ascendentemente tres valores enteros recibidos por referencia.
 * 
 * @param a Puntero al primer entero.
 * @param b Puntero al segundo entero.
 * @param c Puntero al tercer entero.
 * 
 * @pre Ninguno de los tres punteros debe ser NULL.
 * @post Los valores quedan ordenados de forma que *a <= *b <= *c.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * Calcula la suma acumulada de un arreglo utilizando aritmética de punteros.
 * 
 * @param arreglo Puntero constante al primer elemento del arreglo (solo lectura).
 * @param cantidad Número de elementos del arreglo.
 * @param resultado Puntero donde se almacenará el total de la suma.
 * 
 * @return true Si el cálculo se efectuó con éxito.
 * @return false Si 'arreglo' o 'resultado' son NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
