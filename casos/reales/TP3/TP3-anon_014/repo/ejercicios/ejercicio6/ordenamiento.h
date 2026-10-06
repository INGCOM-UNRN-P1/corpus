#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Busca el menor elemento del rango semiabierto [inicio, fin), recorriéndolo
 * con aritmética de punteros.
 *
 * @param inicio Puntero al primer elemento del rango (solo lectura).
 * @param fin    Puntero a la posición siguiente al último elemento.
 *
 * @pre Si ninguno es NULL, ambos apuntan dentro del mismo arreglo (o 'fin'
 *      una posición después de su último elemento).
 *
 * @returns Un puntero al menor elemento del rango (el primero, si hay
 *          empates), o NULL si algún puntero es NULL o si el rango está
 *          vacío (fin <= inicio).
 *
 * @post El puntero retornado, si no es NULL, apunta dentro de
 *       [inicio, fin). El rango no se modifica.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * Ordena ascendentemente un arreglo de enteros con el algoritmo de
 * selección, usando buscar_puntero_minimo() e intercambiar().
 *
 * @param arreglo  Puntero al primer elemento del arreglo. Puede ser NULL.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @post Si arreglo no es NULL, sus elementos quedan en orden ascendente y
 *       son los mismos que antes. Si es NULL, no hace nada.
 */
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
