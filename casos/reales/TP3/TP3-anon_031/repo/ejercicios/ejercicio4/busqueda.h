#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca la primera aparición de un valor en un arreglo de enteros.
 *
 * Recorre el arreglo mediante aritmética de punteros y retorna un puntero
 * constante a la primera posición donde aparece el valor buscado.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Valor que se desea buscar.
 *
 * @return Puntero al primer elemento que coincide con valor.
 * @return NULL si el valor no existe o si arreglo es NULL.
 *
 * @pre Si cantidad es mayor que cero, arreglo debe apuntar a una secuencia
 * válida de al menos cantidad enteros.
 *
 * @post El arreglo no es modificado.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula la distancia relativa entre dos punteros de un mismo arreglo.
 *
 * Calcula el índice relativo del elemento mediante la resta de punteros
 * elemento - inicio.
 *
 * @param inicio Puntero al comienzo del arreglo.
 * @param elemento Puntero a un elemento del mismo arreglo.
 *
 * @return Distancia relativa entre elemento e inicio.
 * @return -1 si alguno de los punteros es NULL o si elemento está antes de inicio.
 *
 * @pre Si ambos punteros son válidos, deben pertenecer al mismo arreglo.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
