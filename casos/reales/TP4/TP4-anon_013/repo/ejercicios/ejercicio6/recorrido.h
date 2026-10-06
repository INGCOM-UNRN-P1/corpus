#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**
 * @brief copia una cierta cantidad de elementos de un arreglo desde una posición dada,
 * a otro arreglo destino.
 * 
 * @param origen es el puntero al inicio del arreglo origen.
 * @param cantidad_origen es la cantidad de elementos del arreglo origen.
 * @param destino es el puntero al inicio del arreglo destino.
 * @param cantidad_destino es la cantidad de elementos del arreglo destino.
 * @param inicio es la posición a partir de la cual comenzar a copiar.
 * @param cantidad_a_copiar es la cantidad de elementos a copiar.
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * 
 * @post la cantidad de elementos de 'origen' se copia a 'destino'.
 * 
 * @return true si la operación fué exitosa. false caso contrario
 */
bool copiar_arreglo (int *origen, size_t cantidad_origen, int *destino, size_t cantidad_destino, size_t inicio, size_t cantidad_a_copiar);

/**
 * @brief invierte in-place un arreglo de enteros utilizando
 * dos punteros (uno al inicio y otro al final, convergiendo con inicio++ y fin--).
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * 
 * @pre 'arreglo' debe ser un puntero válido y accesible.
 * 
 * @post invierte el orden de los elementos del arreglo.
 * 
 * @return true si la operación fué exitosa, false caso contrario.
 */
bool invertir_arreglo (int *arreglo, size_t cantidad);
#endif 
