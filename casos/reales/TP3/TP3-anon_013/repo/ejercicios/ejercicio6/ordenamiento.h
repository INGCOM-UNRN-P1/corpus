#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**
 * @brief recorre un rango entre punteros y obtiene el puntero del valor mínimo.
 * @param inicio es el puntero al inicio del rango.
 * @param fin es el puntero al final del rango.
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * 
 * @post obtiene el puntero al valor mínimo del rango.
 * 
 * @return el puntero constante al valor mínimo. NULL si los parámetros son inválidos.
 */
const int *buscar_puntero_minimo (const int *inicio, const int *fin);

/**
 * @brief ordena ascendentemente un arreglo de enteros.
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * 
 * @pre el puntero debe ser válido y accesible.
 * 
 * @post ordena el arreglo de forma ascendente.
 */
void ordenar_seleccion_punteros (int *arreglo, size_t cantidad);

#endif 
