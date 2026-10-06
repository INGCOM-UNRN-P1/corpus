#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca la primera aparición de un valor en un arreglo.
 *
 * Recorre el arreglo utilizando exclusivamente aritmética de punteros
 * y retorna un puntero constante a la primera posición donde aparece
 * el valor buscado.
 *
 * @param arreglo Arreglo en el que se realizará la búsqueda.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Valor que se desea buscar.
 *
 * @pre arreglo != NULL.
 * @pre cantidad > 0.
 * @pre arreglo apunta a un arreglo de al menos 'cantidad' elementos.
 *
 * @return Puntero constante al primer elemento que coincide con valor,
 *         o NULL si el valor no se encuentra o alguna precondición no se cumple.
 *
 * @post Si retorna un puntero distinto de NULL, apunta a la primera
 *       aparición de valor dentro del arreglo.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula la distancia relativa entre dos posiciones de un arreglo.
 *
 * Calcula la cantidad de elementos entre inicio y elemento mediante
 * la resta de punteros.
 *
 * @param inicio Puntero al primer elemento del arreglo.
 * @param elemento Puntero a un elemento del arreglo.
 *
 * @pre inicio y elemento pertenecen al mismo arreglo.
 * @pre inicio != NULL.
 * @pre elemento != NULL.
 * @pre elemento apunta a una posición igual o posterior a inicio.
 *
 * @return Distancia relativa entre elemento e inicio, o -1 si alguna
 *         precondición no se cumple.
 *
 * @post Si retorna un valor distinto de -1, representa la posición
 *       relativa de elemento respecto de inicio.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
