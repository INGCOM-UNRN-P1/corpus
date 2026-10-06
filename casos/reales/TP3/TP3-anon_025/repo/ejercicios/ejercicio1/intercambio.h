#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



 /** 
  * @brief Ordena tres valores enteros de forma ascendente (*a <= *b <= *c)
  * 
  * @param puntero_menor Puntero a la variable que almacenara el valor menor.
  * @param puntero_mayor Puntero a la variable que almacenara el valos mayor.
  * 
  * @pre Los punreros no deben ser NULL.
 */
void ordenar_par(int *puntero_menor, int *puntero_mayor);

/**
 * @brief Ordena tres valores enteros de forma ascendente.
 * 
 * @param puntero_primeo Puntero a la primera variable de la secuencia
 * @param puntero_segundo Puntero a la segunda variable de la secuencia
 * @param puntero_tercero Puntero a la segunda variable de la secuencia
 * 
 * @pre Los punteros no deben ser NULL
 */
void ordenar_tria(int *puntero_primero, int *puntero_segundo, int *puntero_tercero);

/**
 * @brief Calcula la suma acumulada de un arreglo usando punteros
 * 
 * @param arreglo_fuente Puntero de solo lectura al inicio del arreglo
 * @param cantidad_elementos Cantidad de elementos a procesar en el arreglo
 * @param puntero_resultado_suma Puntero donde se almacenara la suma total
 * @param true Si se pudo realizar la suma
 * @param false Si el arreglo o el puntero de resultado son nulos
 */
bool sumar_acumulado(const int *arreglo_fuente, size_t cantidad_elementos, long long)

#endif 
