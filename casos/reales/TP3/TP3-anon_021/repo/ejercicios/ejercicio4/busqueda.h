#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Busca la primera aparición de un valor en un arreglo de enteros.
 * 
 * Recorre el arreglo empleando aritmética de punteros pura. Al encontrar
 * la primera coincidencia con el valor buscado, aplica un cortocircuito
 * (retorna inmediatamente el puntero a esa posición sin seguir recorriendo).
 * 
 * @param arreglo Puntero constante al primer elemento del arreglo (solo lectura).
 * @param cantidad Número de elementos que contiene el arreglo.
 * @param valor Valor entero que se desea buscar.
 * 
 * @return const int* Puntero a la celda exacta donde se encontró el valor, 
 *                    o NULL si el valor no existe o si 'arreglo' es NULL.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * Calcula la distancia relativa (índice) entre el inicio de un arreglo y un puntero interno.
 * 
 * Emplea la resta de punteros (p - inicio) para determinar la posición relativa 
 * del elemento dentro del arreglo.
 * 
 * @param inicio Puntero al primer elemento del arreglo.
 * @param elemento Puntero a un elemento interno (por ejemplo, retornado por buscar_primero).
 * 
 * @return ptrdiff_t El índice relativo (número de elementos de distancia), 
 *                   o -1 si alguno de los punteros es NULL o si 'elemento' precede a 'inicio'.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 