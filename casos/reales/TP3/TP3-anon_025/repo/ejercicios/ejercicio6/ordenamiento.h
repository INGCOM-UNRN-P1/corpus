#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca el puntero al elemento minimo en un rango semi-abierto [inicio, fin).
 * 
 * @param puntero_inicio Puntero al primer elemento del rango
 * @param puntero_fin Puntero al limite del rango (justo despues del ultimo elemento).
 * 
 * @return const int* Puntero constante al elemento minimo, o NULL si el rango es invalido.
 */
const int* buscar_puntero_minimo(const int *puntero_inicio, const int *puntero_fin0);

/**
 * @brief Ordena un arreglo de enteros ascendentemente usando el algoritmo de seleccion.
 * 
 * @param puntero_arreglo Puntero al inicio del arreglo.
 * @param cantidad_elementos Cantidad total de elementos en el arreglo.
 * 
 * @pre El puntero no puede ser NULL.
 */
void ordenar_seleccion_punteros(int *puntero_arreglo, size_t cantidad_elementos);

#endif 
