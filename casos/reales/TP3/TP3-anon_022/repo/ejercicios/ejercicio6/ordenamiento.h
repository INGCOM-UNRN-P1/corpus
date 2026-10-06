#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca el elemento mínimo dentro de un rango de punteros.
 *
 * Recorre el rango semiabierto [inicio, fin) mediante aritmética de
 * punteros y determina la posición del elemento con menor valor.
 *
 * @pre inicio y fin deben apuntar al mismo arreglo, o fin debe ser el
 *      puntero posterior al último elemento de ese arreglo.
 * @pre Si el rango es válido, fin debe ser igual o posterior a inicio.
 *
 * @param inicio Puntero al primer elemento del rango, inclusive.
 * @param fin Puntero al elemento posterior al último del rango, exclusivo.
 *
 * @return Puntero al elemento mínimo del rango.
 *         Retorna NULL si inicio o fin es NULL, o si el rango está vacío
 *         o invertido.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena un arreglo de enteros mediante Selection Sort.
 *
 * Recorre el arreglo mediante aritmética de punteros. En cada posición
 * busca el menor elemento del rango restante y lo intercambia con la
 * posición actual.
 *
 * @pre Si cantidad es mayor que 0, arreglo debe apuntar a una zona de
 *      memoria válida que contenga al menos cantidad elementos de tipo int.
 *
 * @post Si arreglo no es NULL y cantidad es mayor que 1, sus elementos
 *       quedan ordenados de forma ascendente.
 * @post Si arreglo es NULL o cantidad es menor o igual a 1, no se modifica
 *       la memoria.
 *
 * @param arreglo Puntero al primer elemento del arreglo a ordenar.
 * @param cantidad de elementos válidos del arreglo.
 */
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
