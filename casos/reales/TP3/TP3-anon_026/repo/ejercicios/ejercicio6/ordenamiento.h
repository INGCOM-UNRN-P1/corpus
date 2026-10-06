#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

/**
*@file ordenamiento.h
*@brief ordenamiento por seleccion con aritmetica de punteros
*/

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
*@brief busca el elemento minimo en el rango semiabierto [inicio, fin)
*
*Recorre el rango unicamente con aritmetica de punteros. ante empates retorna la primera ocurrencia del minimo
*
*@pre inicio y fin pertenecen al mismo arreglo (fin es una posicion valida o uno pasado el ultimo elemento)
*@post ningun dato se modifica
*
*@param[in] inicio puntero al primer elemento del rango (inclusive)
*@param[in] fin puntero al final del rango (exclusive)
*
*@return puntero al elemento minimo, o NULL si inicio o fin son NULL o si el rango esta vacio o es invalido (inicio >= fin)
*/
const int *buscar_puntero_minimo(const int *inicio, cons tint *fin);

/**
*@brief ordena un arreglo de enteros de forma ascendente (seleccion)
*
*@por cada posicion busca el minimo del resto con buscar_puntero_minimo()y lo intercambia con intercambiar(). Sin indexacion[]
*
*@pre arreglo apunta a al menos 'cantidad' entero contiguos.
*@post si retorna true: arreglo [0] <= arreglo [1] <= ... (ordenado) y contiene los mismos elementos que antes
*@post si retorna false: el arreglo no se modifica
*
*@param[in, out] arreglo arreglo a ordenar
*@param[in] cantidad cantidad de elementos del arreglo
*
*@return trtue si se ordeno (cantidad 0 o 1 incluidas); false si arreglo es NULL
*/
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
