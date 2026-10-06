#ifndef RECORRIDO_H
#define RECORRIDO_H

/**
*@file recorrido.h
*@brief copia e inversion de arreglos de enteros con aritmetica de punteros
*/

#include <stdbool.h>
#include <stddef.h>

/**
*@brief copia 'cantidad' enteros desde un arreglo origen a un destino
*
*recorre ambos arreglos unicamente con aritmetica de punteros
*
*@pre origen apunta a al menos 'cantidad' enteros contiguos
*@pre destino apunta a al menos 'capacidad' enteros contiguos
*@pre los arreglos origen y destino no se superponen en memori
*@post si retorna true: los primeros ' cantidad' elementos de destino son iguales  los de origen. origen no se modifica.
*@post si rtorna false: destino no se modifica
*
*@param[out] destino arreglo donde se copian los elementos
*@param[in] capacidad cantidad de elementos que admite destino
*@param[in] origen arreglo fuente (solo lectura)
*@param[in] cantidad cantidad de elementos a copiar
*
*@return true si se copio; false si destino u origen son NULL o si capacidad es menor que cantidad.
*/
bool copiar_arreglo(int *destino, size_t capacidad, const int *origen, size_t cantidad);

/**
*@brief invierte un arreglo de entero in-place
*
*@pre arreglo apunta a al menos 'cantidad' entero contiguos
*@post si retorna true: el elemento en la posicion k pasa a la posicion cantidad -1 -k. con cantidad 0 o 1 el arreglo no cambia
*@post si retorna false: el arreglo no se modifica
*
*@param[in, out] arreglo arreglo a invertir
*@param[in] cantidad cantidad de elementos del arreglo.
*
*@return true si se invirtio; false si arreglo es NULL.
*/
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
