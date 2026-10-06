#ifndef BUSQUEDA_H
#define BUSQUEDA_H

/**
*@file busqueda.h
*@brief busqueda lineal con retorno de puntero y distancia entre punteros.
*/

#include <stdbool.h>
#include <stddef.h>

/**
*@brief busca l primera aparicion de un valor en un arreglo de enteros
*
*recorre el arreglo unicamente con aritmetica de punteros y se detiene al encontrar el valor (cortocircuito)
*
*@pre arreglo apinta a al menor 'cantidad' enteros contiguos
*@post el arrelo no se modifica
*@post si se encuentra el valor: el retorno apunta a su primera ocurrrencia dentro del arreglo
*
*@param[in] arreglo arreglo de enteros (solo lectura)
*@param[in] cantidad cantidad de elementos del arreglo
*@param[in] valor valor a buscar
*
*@return puntero a la primera ocurrencia 'valor', o NULL si no existe, si arreglo es NULL o si cantidad es 0
*/
const int *buscar_primera(const int *arreglo, size_t cantidad, int valor).

/**
*@brief calcula el indice relativo de un elemento respecto al inicio
*
*usa la resta de punteros (elemento - inicio)
*
*@pre elemento apunta dentro del mismo arreglo que inicio
*@post ningun dato se modifica
*
*@param[in] inicio puntero al primer elemento del arreglo
*@param[in] elemento puntero a un elemento del mismo arreglo
*
*@return distancia en elementos (indice relativo), o -1 si alguno de los punteros es NULL o si elemento esta entes de inicio
*/
ptrdiff_t distancia_puntero(const int *inicio, const int *elementos);

#endif 