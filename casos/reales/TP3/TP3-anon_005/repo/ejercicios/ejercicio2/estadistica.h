#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Calcula el minimo, maximo y promedio de los elementosde un arreglo
 *        de enteros, utilizando obtener_min_max de libpunteros y acumulacion
 *        con aritmetica de punteros para el promedio.
 * @param arreglo Puntero al primer el elemento del arreglo de enteros a analizar
 * @param cantidad Cantidad de elementos que contien el arreglo.
 * @param minimo Puntero de salida donde se almacenara el valor minimo del arreglo.
 * @param maximo Puntero de salida donde se almacenara el valor maximo del arreglo.
 * @param promedio Puntero de salida donde se almacenara el promedio de los elementos.
 * @pre arreglo, minimo, maximo y promedio pueden ser NULL.
 * @pre cantidad puede ser 0.
 * @post Si todos los puntero son distintos de NULL y cantidad es mayor a 0,
 *       *minimo y *maximo contienen los elemntos divida por cantidad.
 * @post Si algun puntero es NULL, cantidad es 0 o falla obtener_min_max,
 *       la funcion no produce ningun efecto sobre las salidas y retonar falso
 * @return true si pudo calcular las tres estadisticas exitosamente.
 * @return false si algun puntero es NULL, cantidad es 0, o fallo la 
 *         obtencion de minimo y maximo.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);
#endif 
