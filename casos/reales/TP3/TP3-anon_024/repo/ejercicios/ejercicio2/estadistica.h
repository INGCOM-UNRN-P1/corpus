#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * =========================================================================
 * Ejercicio 2: Estadísticas, Promedio y Filtrado por Rango con Punteros
 * =========================================================================
 * Calcula el valor minimo, maximo y promedio de una secuencia de enteros.
 *
 * @param arreglo puntero al primer elemento del arreglo a procesar.
 * @param cantidad de elementos presentes dentro del contenedor.
 * @param minimo puntero de salida donde se almacenara el valor minimo.
 * @param maximo puntero de salida donde se almacenara el valor maximo.
 * @param promedio puntero de salida donde se almacenara el promedio.
 * @pre El puntero arreglo debe apuntar a una secuencia valida de al menos
 *      cantidad elementos si cantidad > 0.
 * @post El contenido de la secuencia procesada no resulta alterado. Si la
 *       función retorna true, las posiciones apuntadas por minimo, maximo
 *       y promedio contendrán los valores calculados.
 * @returns true si se calcularon los datos estadísticos con exito.
 *          Retorna false si arreglo, minimo, maximo o promedio resultan
 *          nulos, o si la cantidad es igual a 0.
*/
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * Cuenta cuantos elementos se encuentran dentro de un intervalo cerrado.
 *
 * @param arreglo puntero al primer elemento del arreglo a evaluar.
 * @param cantidad de enteros presentes en el contenedor.
 * @param limite_inf del intervalo cerrado.
 * @param limite_sup del intervalo cerrado.
 * @param coincidencias puntero de salida donde se guarda el total contado.
 * @pre El puntero arreglo debe apuntar a una secuencia valida de al menos
 *      cantidad elementos si cantidad > 0.
 * @post El contenido de la secuencia evaluada permanece inalterado. Si la
 *       funcion retorna true, la variable apuntada por coincidencias
 *       almacena la cantidad de elementos dentro del rango.
 * @returns true si el conteo en el rango se completo con exito.
 *          Retorna false si el parametro arreglo resulta nulo o si
 *          coincidencias resulta nulo.
*/
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
