#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief copia 'cantidad' elementos enteros desde un arreglo orgien hacia un destino utilizando aritmentica de punteros.
 * 
 * @param origen puntero al arreglo de entrada (solo de lectura).
 * @param destino puntero al arreglo donde se copiaran los datos.
 * @param cantidad numero de elementos a copiar.
 * @return ture si la copia fue exitosa, false si algun puntero es NULL.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * @brief invierte in-place un arreglo de enteros utilizando dos punteros que convergen (inicio++ y fin--), haciendo uso de intercambiar().
 * 
 * @param arreglo puntero al arreglo invertir.
 * @param cantidad numero de elementos en el arreglo.
 * @return true si la inversion fue exitosa, false si el arreglo es NULL.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);
#endif 
