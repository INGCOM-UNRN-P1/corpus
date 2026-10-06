/**
 * @file estadistica.h
 * @brief Operaciones de estadísticas y filtrado por rango mediante punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Toda manipulación de secuencias o arreglos debe realizarse mediante
 * aritmética de punteros, evitando el operador de indexación arreglo[i].
 */

#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Calcula el mínimo, máximo y promedio de un arreglo de enteros.
 *
 * Utiliza obtener_min_max() de libpunteros para determinar los extremos
 * del arreglo y recorre la secuencia mediante aritmética de punteros
 * para calcular la suma y el promedio.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo Puntero donde se almacenará el menor elemento.
 * @param maximo Puntero donde se almacenará el mayor elemento.
 * @param promedio Puntero donde se almacenará el promedio aritmético.
 *
 * @pre Ninguna.
 *
 * @post Si arreglo, minimo, maximo o promedio es NULL, retorna false.
 * @post Si cantidad == 0, retorna false.
 * @post Si los parámetros son válidos, minimo contiene el menor elemento,
 *       maximo contiene el mayor elemento y promedio contiene el promedio
 *       aritmético de los elementos.
 *
 * @return true si pudo calcular las estadísticas, false si los parámetros
 *         son inválidos.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad,
                           int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta los elementos que pertenecen a un intervalo cerrado.
 *
 * Recorre el arreglo exclusivamente mediante aritmética de punteros y
 * cuenta los elementos cuyo valor pertenece al intervalo
 * [limite_inf, limite_sup].
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param limite_inf Límite inferior del intervalo.
 * @param limite_sup Límite superior del intervalo.
 * @param coincidencias Puntero donde se almacenará la cantidad de elementos
 *                      encontrados dentro del intervalo.
 *
 * @pre Ninguna.
 *
 * @post Si arreglo o coincidencias es NULL, retorna false.
 * @post Si los parámetros son válidos, coincidencias contiene la cantidad
 *       de elementos pertenecientes al intervalo cerrado
 *       [limite_inf, limite_sup].
 * @post Si cantidad == 0 y los punteros son válidos, almacena 0 en
 *       *coincidencias y retorna true.
 *
 * @return true si pudo realizar el conteo, false si arreglo o coincidencias
 *         es NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad,
                     int limite_inf, int limite_sup,
                     size_t *coincidencias);

#endif 