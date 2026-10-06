#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stddef.h>

/**
 * @brief Busca la primera aparicion de un valor en un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Valor que se desea buscar.
 *
 * @pre arreglo debe ser un puntero valido.
 * @post Si encuentra el valor, retorna un puntero a su primera aparicion.
 *
 * @return Puntero al elemento encontrado.
 * @return NULL si no se encuentra o arreglo es NULL.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula la distancia entre el inicio de un arreglo y un elemento.
 *
 * @param inicio Puntero al inicio del arreglo.
 * @param elemento Puntero a un elemento del arreglo.
 *
 * @pre Ambos punteros deben pertenecer al mismo arreglo.
 *
 * @return Distancia entre elemento e inicio.
 * @return -1 si algun puntero es NULL o elemento esta antes de inicio.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
