#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief busca la primera aparición de un valor en un arreglo de enteros
 * recorriéndolo con aritmética de punteros.
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @param valor es el valor buscado.
 * 
 * @pre 'arreglo' debe ser un puntero válido y accesible.
 * 
 * @post determina el puntero de la primera coincidencia.
 * 
 * @return un puntero constante que apunta a la dirección de la primera coincidencia.
 * Null en caso de que no haya coincidencias o ante parámetros inválidos.
 */
const int *buscar_primero (const int *arreglo, const size_t cantidad, int valor);

/**
 * @brief calcula el índice de un elemento perteneciente a un arreglo mediante resta
 * de punteros.
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @param elemento es el puntero al que se le busca el índice.
 * 
 * @pre los punteros deben ser válidos y accesibles. 'elemento' debe ser un
 * puntero contenido en 'arreglo'
 * 
 * @post determina la distancia entre el inicio del arreglo y el elemento (el índice).
 * 
 * @return el índice del elemento. -1 en caso de que algun puntero sea nulo o 'elemento'
 * no esté contenido en 'arreglo'.
 */
long long int distancia_punteros (const int *const arreglo, size_t cantidad, const int *const elemento);
#endif 
