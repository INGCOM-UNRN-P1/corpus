#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>




/**
 * @brief Busca la primera aparición de un valor en un arreglo de enteros.
 *
 * Recorre el arreglo exclusivamente con aritmética de punteros (sin `[]`).
 *
 * @param[in] arreglo  Arreglo de enteros donde buscar (solo lectura).
 * @param[in] cantidad Cantidad de elementos del arreglo a considerar.
 * @param[in] valor    Valor a buscar.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y legibles.
 *
 * @post El contenido de 'arreglo' no se modifica.
 *
 * @return Puntero a la primera posición de 'arreglo' cuyo valor es igual a
 * 'valor'; NULL si no se encuentra, si 'arreglo' es NULL o si 'cantidad' es 0.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);


/**
 * @brief Calcula la distancia entre el inicio de un arreglo y un elemento
 * interno, mediante resta de punteros.
 *
 * @param[in] inicio   Puntero al primer elemento del arreglo.
 * @param[in] elemento Puntero a un elemento del mismo arreglo.
 *
 * @pre Si 'inicio' y 'elemento' no son NULL, ambos apuntan a posiciones del
 * mismo arreglo.
 *
 * @post No se modifica ninguna posición de memoria.
 *
 * @return La distancia `elemento - inicio`, equivalente al índice de
 * 'elemento' dentro del arreglo; -1 si 'inicio' o 'elemento' es NULL, o si
 * 'elemento' apunta a una posición anterior a 'inicio'.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);


#endif 
