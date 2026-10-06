#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca el elemento mínimo dentro de un rango semiabierto de punteros.
 *
 * Recorre el rango [inicio, fin) mediante aritmética de punteros y retorna
 * un puntero constante al elemento de menor valor.
 *
 * @param inicio Puntero al primer elemento del rango.
 * @param fin Puntero a una posición posterior al último elemento del rango.
 *
 * @return Puntero al elemento mínimo del rango.
 * @return NULL si inicio o fin son NULL, o si el rango es vacío o inválido.
 *
 * @pre Si ambos punteros son válidos, deben pertenecer al mismo arreglo.
 *
 * @post El contenido del rango no se modifica.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena un arreglo de enteros en forma ascendente mediante Selection Sort.
 *
 * En cada paso busca el menor elemento del rango restante utilizando
 * buscar_puntero_minimo y lo intercambia con la posición actual mediante
 * la función intercambiar de libpunteros.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @return true si la operación pudo realizarse.
 * @return false si arreglo es NULL.
 *
 * @pre Si cantidad es mayor que cero, arreglo debe apuntar a una secuencia
 * válida de al menos cantidad enteros.
 *
 * @post Ante éxito, el arreglo queda ordenado en forma ascendente.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
