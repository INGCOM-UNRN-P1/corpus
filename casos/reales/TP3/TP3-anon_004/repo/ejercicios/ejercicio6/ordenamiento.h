#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Localiza el puntero al elemento con menor valor en un rango semiabierto [inicio, fin).
 *
 * @pre inicio y fin pertenecen al mismo arreglo y definen un rango valido con inicio < fin.
 * @post Retorna el puntero al menor elemento del rango; retorna NULL si los punteros son invalidos o inicio >= fin.
 *
 * @param inicio Puntero al primer elemento del rango a evaluar.
 * @param fin    Puntero limite exclusivo del rango a evaluar.
 *
 * @return int* Puntero a la posicion donde reside el menor valor.
 */
int *buscar_puntero_minimo(int *inicio, int *fin);

/**
 * @brief Ordena in-place un arreglo mediante Selection Sort usando punteros e intercambiar.
 *
 * @pre arreglo apunta a una secuencia contigua valida de al menos cantidad enteros.
 * @post Ordena los elementos ascendentemente in-place; no produce cambios si arreglo es NULL o cantidad <= 1.
 *
 * @param arreglo  Puntero al inicio del arreglo a ordenar.
 * @param cantidad Cantidad de elementos del arreglo.
 */
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
