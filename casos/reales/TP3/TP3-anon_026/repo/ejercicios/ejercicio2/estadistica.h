#ifndef ESTADISTICA_H
#define ESTADISTICA_H

/**
*@file estadistica.h
*@brief estadisticas basicas y conteo por rango mediante punteros
*/

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
*@brief calcula minimo. maximo y promedio de un arreglo de enteros
*
*Usa obtener_min_max() para los extremos y acumula con aritmetica
*de punteros para el promedio
*
*@pre arreglo apunta a al menos 'cantidad' enteros contiguos
*@post si retorna true: *minimo, *maximo y *promedio estan asignados.
*@post si retorna false: ninguna salida se modifica.
*
*@param[in] arreglo arreglo de enteros (solo lectura)
*@param[in] cantidad cantidad de elementos (debe ser mayor de 0)
*@param[out] minimo direccion donde se guarda el minimo
*@param[out] maximo direccion donde se guarda el maximo
*@param[out] promedio direccion donde se guarda el promedio
*
*@return true si tuvo exito; false si algun puntero es NULL o cantidad == 0
*/
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
*@brief cuenta los elementos dentro del intervalo cerrado [limite_inf, limite_sup]
*
*recorre el arreglo unicamente con aritmetica de punteros
*
*@pre arreglo apunta a al menos 'canitdad' enteros contiguos.
*@post si retorna true:*coincidencias contiene el conteo (0 si cantidad == 0 o si limite_inf > limte_sup)
*@post si retorna false: *coincidencias no se modifica.
*
*@param[in] arreglo arreglo de enteros(solo lectura)
*@param[in] cantidad cantidad de elementos del arreglo
*@param[in] limite_inf limite inferior del rango (inclusive)
*@param[in] limite_sup limite superior del rango (inclusive)
*@param[out] coincidencias direccion donde se guarda el conteo
*
*@return true si se calculo conteo; false si arreglo o coincidecias son NULL
*/
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
