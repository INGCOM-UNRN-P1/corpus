#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h" 

/**
 * Ordena dos enteros de modo que el primero quede menor o igual que el
 * segundo, delegando el intercambio en intercambiar().
 *
 * @param menor Puntero al valor que debe quedar como menor. Puede ser NULL.
 * @param mayor Puntero al valor que debe quedar como mayor. Puede ser NULL.
 *
 * @pre Ninguna: si alguno de los punteros es NULL la función no hace nada.
 *
 * @post Si ambos punteros son válidos, *menor <= *mayor y los dos valores
 *       originales se conservan.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * Ordena ascendentemente tres enteros recibidos por referencia, mediante
 * llamadas sucesivas a ordenar_par() e intercambiar().
 *
 * @param a Puntero al valor que debe quedar como menor. Puede ser NULL.
 * @param b Puntero al valor que debe quedar en el medio. Puede ser NULL.
 * @param c Puntero al valor que debe quedar como mayor. Puede ser NULL.
 *
 * @pre Ninguna: si alguno de los punteros es NULL la función no hace nada.
 *
 * @post Si los tres punteros son válidos, *a <= *b <= *c y los tres valores
 *       originales se conservan.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * Suma todos los elementos de un arreglo recorriéndolo con aritmética de
 * punteros.
 *
 * @param arreglo   Puntero al primer elemento del arreglo (solo lectura).
 * @param cantidad  Cantidad de elementos a sumar.
 * @param resultado Parámetro de salida donde se guarda la suma.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @returns true si guardó la suma en *resultado; false si arreglo o
 *          resultado son NULL.
 *
 * @post Si retorna true, *resultado es la suma de los elementos (0 si
 *       cantidad es 0). Si retorna false, *resultado no se modifica.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad,
                     long long *resultado);

#endif 
