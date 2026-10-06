/**
 * @file estadistica.h
 * @brief Funciones de calculo estadistico y conteo en rango mediante aritmetica de punteros.
 *
 * Ejercicio 2 - Trabajo Practico 3
 * Programacion 1 - Universidad Nacional de Rio Negro
 */

#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Determina los extremos (minimo y maximo) y calcula la media aritmetica de un arreglo de enteros.
 *
 * Obtiene los valores extremos delegando en `obtener_min_max` de libpunteros y recorre la secuencia
 * contigua con aritmetica de punteros para acumular la sumatoria y obtener el promedio.
 *
 * @pre El puntero `arreglo` debe referenciar un bloque valido de al menos `cantidad` enteros.
 * @pre Los punteros de salida `minimo`, `maximo` y `promedio` deben apuntar a memoria modificable.
 * @post Si la funcion tiene exito, escribe los valores en las direcciones provistas sin alterar el arreglo original.
 *
 * @param[in] arreglo Puntero de lectura al inicio del arreglo de enteros.
 * @param[in] cantidad Numero de elementos contenidos en el arreglo.
 * @param[out] minimo Puntero donde se almacenara el valor minimo hallado.
 * @param[out] maximo Puntero donde se almacenara el valor maximo hallado.
 * @param[out] promedio Puntero donde se almacenara la media aritmetica calculada.
 *
 * @return true si se calcularon y asignaron los tres valores correctamente,
 *         false si alguno de los punteros es NULL o si `cantidad` es 0.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta cuantos elementos del arreglo caen dentro del intervalo cerrado [limite_inf, limite_sup].
 *
 * Itera el arreglo exclusivamente mediante punteros incrementales, acumulando la cantidad de
 * coincidencias en la variable referenciada por `coincidencias`.
 *
 * @pre El puntero `arreglo` debe ser valido si `cantidad > 0`.
 * @pre El puntero `coincidencias` debe apuntar a una variable size_t modificable.
 * @post `*coincidencias` contendra la cantidad de valores que cumplen limite_inf <= x <= limite_sup.
 *
 * @param[in] arreglo Puntero de solo lectura al inicio de la secuencia de enteros.
 * @param[in] cantidad Cantidad de elementos del arreglo.
 * @param[in] limite_inf Cota inferior del rango cerrado.
 * @param[in] limite_sup Cota superior del rango cerrado.
 * @param[out] coincidencias Puntero a la variable donde se guardara la cantidad total de coincidencias.
 *
 * @return true si se realizo el conteo con exito, false si `arreglo` es NULL (con cantidad > 0)
 *         o si `coincidencias` es NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
