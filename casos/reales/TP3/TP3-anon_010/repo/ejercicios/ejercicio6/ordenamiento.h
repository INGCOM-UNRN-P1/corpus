#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca el elemento mínimo dentro de un rango de un arreglo de enteros.
 *
 * Recorre el rango semi-abierto ['inicio', 'fin'), exclusivamente con
 * aritmética de punteros (sin `[]`).
 *
 * @param[in] inicio Puntero al primer elemento del rango a considerar.
 * @param[in] fin Puntero a la posición siguiente al último elemento del
 * rango (no se desreferencia).
 *
 * @pre Si 'inicio' y 'fin' no son NULL, apuntan a posiciones del mismo
 * arreglo, con 'inicio' en una posición igual o anterior a 'fin'.
 *
 * @post No se modifica ninguna posición de memoria.
 *
 * @return Puntero al elemento mínimo del rango ['inicio', 'fin'); NULL si
 * 'inicio' es NULL, 'fin' es NULL, o el rango es inválido (`inicio >= fin`).
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena ascendentemente un arreglo de enteros mediante el algoritmo
 * de Selección.
 *
 * Para cada posición, busca el mínimo del rango restante con
 * 'buscar_puntero_minimo' y lo intercambia con la posición actual mediante
 * 'intercambiar' de libpunteros. No utiliza el operador `[]`.
 *
 * @param[in, out] arreglo  Arreglo de enteros a ordenar.
 * @param[in] cantidad Cantidad de elementos del arreglo.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y modificables.
 *
 * @post Si 'arreglo' no es NULL, sus elementos quedan ordenados de forma
 * ascendente.
 * @post Los valores finales son una permutación de los originales: no se
 * introducen valores nuevos.
 * @post Si 'arreglo' es NULL, no se accede a memoria y no se modifica nada.
 */
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
