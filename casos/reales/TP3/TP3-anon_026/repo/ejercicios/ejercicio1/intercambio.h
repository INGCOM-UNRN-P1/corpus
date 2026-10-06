#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

/**
* @file intercambio.h
* @brief ordenamiento de pares, trios y suma acumulada mediante punteros
*/

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
*@brief Ordena un par de enteros de forma ascendente
*
* Si *menor > *mayor, intercambia los valores usando intercambiar()
*
*@pre menor y mayor apuntan a enteros validos; o alguno es NULL.
*@post Si ambos ounteros son validos: *menor <= *mayor.
*@post Si alguno es NULL: no se modifica ningun valor.
*
*@param[in,out] menor puntero al entero que quedara como el menor.
*@param[in,out] mayor puntero al entero que quedara como el mayor.
*/
void ordenar_par (int *menor, int *mayor);

/**
*@brief ordena tres enteros de forma ascendente.
*
* Se resuelve con llamadas sucesivas a ordenar_par()
*
*@pre a, b y c apuntan a enteros validos, o alguno es NULL.
*@post si los tres punteros son validos: *a <= *b <= *c.
*@post si alguno es NULL: no se modifica ningun valor.
*
*@param[in, out] a puntero al primer entero
*@param[in, out] b puntero al segundo entero
*@param[in, out] c puntero al tercer entero
*/
void ordenar_tria(int *a, int *b, int*c);

/**
*@brief suma todos los elemntos de un arreglo
*
* recorre el arreglo unicamente con aritmetica de punteros.
*
*@pre arreglo apunta a al menos 'cantidad'  enteros cotiguos.
*@pre resultado apunta a una variable long long valida.
*@post si retorna true: *resultado contiene la suma (0 si cantidad == 0)
*@post si returna false: *resultado no se modifica
*
*@param[in] arreglo  arreglo de enteros a sumar (solo lectura)
*@param[in] cantidad cantidad de elementos al arreglo.
*@param[out] resultado direccion donde se guarda la suma
*
*@return true si se calculo la suma; false si arreglo o resultado son NULL
*/
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
