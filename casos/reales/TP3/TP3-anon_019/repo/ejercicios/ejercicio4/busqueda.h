#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca la primera aparición de un valor en un arreglo.
 * 
 * @pre El puntero 'arreglo' no debe ser nulo.
 * @post Si el valor existe, se retorna un puntero a su ubicación exacta en memoria.
 * 
 * @param arreglo Puntero constante al arreglo a explorar.
 * @param cantidad Número de elementos en el arreglo.
 * @param valor El número entero que se desea encontrar.
 * @return const int* Puntero a la primera ocurrencia, o NULL si no existe o el arreglo es nulo.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula la distancia (índice) entre un puntero base y un puntero a elemento.
 * 
 * @pre Ambos punteros no deben ser nulos. El elemento no debe estar antes del inicio.
 * @post Se calcula la diferencia mediante resta directa de punteros.
 * 
 * @param inicio Puntero al inicio del arreglo.
 * @param elemento Puntero al elemento encontrado dentro del arreglo.
 * @return int El índice del elemento (su distancia), o -1 si hay error.
 */
int distancia_punteros(const int *inicio, const int *elemento);

#endif 