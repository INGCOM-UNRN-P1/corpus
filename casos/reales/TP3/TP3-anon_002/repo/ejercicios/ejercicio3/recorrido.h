#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Copia los elementos de un arreglo fuente a un arreglo destino.
 *
 * Copia exactamente 'cantidad' elementos desde el arreglo fuente hacia
 * el arreglo destino utilizando exclusivamente aritmética de punteros.
 *
 * @param fuente Arreglo del cual se copiarán los elementos.
 * @param destino Arreglo donde se copiarán los elementos.
 * @param cantidad Cantidad de elementos a copiar.
 *
 * @pre fuente != NULL.
 * @pre destino != NULL.
 * @pre cantidad > 0.
 * @pre fuente apunta a un arreglo de al menos 'cantidad' elementos.
 * @pre destino apunta a un espacio de al menos 'cantidad' elementos.
 *
 * @return true si la copia se realiza correctamente, false si alguna
 *          precondición no se cumple.
 *
 * @post Los primeros 'cantidad' elementos de destino contienen los mismos
 *       valores que los correspondientes elementos de fuente.
 */
bool copiar_arreglo(const int *fuente, int *destino, size_t cantidad);


/**
 * @brief Invierte los elementos de un arreglo in-place.
 *
 * Invierte el orden de los elementos del arreglo utilizando dos punteros
 * que convergen desde los extremos y la función intercambiar.
 *
 * @param arreglo Arreglo cuyos elementos serán invertidos.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre arreglo != NULL.
 * @pre cantidad > 0.
 * @pre arreglo apunta a un arreglo de al menos 'cantidad' elementos.
 *
 * @return true si la inversión se realiza correctamente, false si alguna
 *         precondición no se cumple.
 *
 * @post Los elementos de arreglo quedan en orden inverso al orden original.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
