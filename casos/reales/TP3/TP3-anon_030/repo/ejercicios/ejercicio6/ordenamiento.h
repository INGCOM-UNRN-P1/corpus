#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca el elemento minimo dentro de un rango de punteros.
 *
 * @param inicio Puntero al primer elemento del rango.
 * @param fin Puntero a la posicion posterior al ultimo elemento.
 *
 * @pre inicio y fin deben pertenecer al mismo arreglo.
 * @post El arreglo no es modificado.
 *
 * @return Puntero al elemento minimo.
 * @return NULL si el rango es invalido.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena un arreglo de menor a mayor mediante seleccion.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre arreglo debe ser un puntero valido.
 * @post El arreglo queda ordenado de forma ascendente.
 *
 * @return true si el ordenamiento se realizo correctamente.
 * @return false si arreglo es NULL.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
