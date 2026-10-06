#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia una cantidad de elementos desde un arreglo origen a un arreglo destino.
 *
 * La copia se realiza exclusivamente mediante aritmética de punteros.
 *
 * @param origen Puntero al primer elemento del arreglo de origen.
 * @param destino Puntero al primer elemento del arreglo de destino.
 * @param cantidad Cantidad de elementos que se deben copiar.
 *
 * @return true si la copia pudo realizarse.
 * @return false si origen o destino son NULL.
 *
 * @pre Si cantidad es mayor que cero, origen debe apuntar a una secuencia válida
 * de al menos cantidad enteros y destino debe disponer de espacio para al menos
 * cantidad enteros.
 *
 * @post Ante éxito, los primeros cantidad elementos de destino contienen los
 * mismos valores que los primeros cantidad elementos de origen.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * @brief Invierte in-place un arreglo de enteros.
 *
 * Utiliza dos punteros que avanzan desde los extremos hacia el centro y
 * reutiliza intercambiar de libpunteros.
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
 * @post Ante éxito, el arreglo queda con sus elementos en el orden inverso
 * respecto de su estado inicial.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
