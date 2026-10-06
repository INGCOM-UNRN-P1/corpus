#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Copia los elementos de un arreglo fuente a un arreglo destino.
 * 
 * Recorre y copia 'cantidad' elementos enteros desde un arreglo de origen
 * hacia un arreglo de destino utilizando exclusivamente aritmética de punteros
 * (punteros origen y destino avanzando con operadores de incremento).
 * 
 * @param origen Puntero constante al primer elemento del arreglo origen (solo lectura).
 * @param destino Puntero al primer elemento del arreglo destino (donde se escribirá).
 * @param cantidad Número de elementos a copiar.
 * 
 * @return true Si la copia se realizó con éxito.
 * @return false Si 'origen' o 'destino' son NULL.
 * 
 * El arreglo destino debe tener capacidad suficiente para albergar la cantidad indicada.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * @brief Invierte el orden de los elementos de un arreglo "in-place".
 * 
 * Modifica el arreglo original invirtiendo sus elementos utilizando dos punteros
 * (uno al inicio y otro al final) que convergen hacia el centro incrementándose
 * y decrementándose respectivamente. Se apoya en la función de intercambio.
 * 
 * @param arreglo Puntero al primer elemento del arreglo a invertir.
 * @param cantidad Número de elementos que contiene el arreglo.
 * 
 * @return true Si la inversión se realizó con éxito.
 * @return false Si 'arreglo' es NULL.
 * 
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
