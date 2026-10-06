#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca el elemento de valor mínimo en un rango de un arreglo de
 * enteros, se recorre mediante arigmetica de punteros.
 * @pre 'inicio' y 'fin' no deben ser NULL.
 * Y 'inicio' no puede ser mayor a 'fin'.
 * @post Se devuelve el elemento minimo dentro del rango.
 * @param inicio Puntero constante al comienzo del rango.
 * @param fin Puntero constante al final del rango.
 * @return Puntero constante al elemento mínimo dentro del rango
 * o NULL si inicio o fin son NULL, o si inicio es menor igual a fin.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);
/**
 * @brief Se ordenan ascendentemente lso elementos contenidos en el arreglo.
 * @pre 'arreglo' no puede ser NULL. Y 'cantidad' no puede ser 0.
 * @post El arreglo ordenado de menor a mayor, true. Sino false.
 * @param arreglo es el arreglo.
 * @param capacidad es el espacio en la memoria de arrelgo.
 * @return Devuelve el arreglo ordenado
 */
int *ordenar_seleccion_punteros(int *arreglo, size_t capacidad);

#endif 
