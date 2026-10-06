#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/** 
* @brief Calcula el valor mínimo, máximo y promedio aritmético de un arreglo de enteros. 
* Reutiliza la función 'obtener_min_max' de libpunteros para determinar los extremos
* y calcula el promedio acumulando la suma mediante aritmética.
*
* @param arreglo Puntero al primer elemento del arreglo de enteros (lectura exclusivamente).
* @param cantidad Cantidad de elementos válidos presentes en el arreglo. 
* @param minimo Puntero donde se almacenará el menor elemento hallado (salida). 
* @param maximo Puntero donde se almacenará el mayor elemento hallado (salida). 
* @param promedio Puntero donde se almacenará el promedio aritmético como double (salida). 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a memoria válida. 
* @post Si retorna true, *minimo, *maximo y *promedio contendrán los resultados calculados. 
* 
* @return true si se obtuvieron las estadísticas exitosamente, * false si algún puntero es NULL o si 'cantidad' es 0. 
*/ 
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
* @brief Cuenta los elementos de un arreglo pertenecientes a un intervalo cerrado. 
* Recorre el arreglo mediante aritmética de punteros evaluando 
* si cada elemento satisface la condición limite_inf <= elemento <= limite_sup. 
* Almacena la cantidad total de coincidencias. 
* 
* @param arreglo Puntero al primer elemento del arreglo (lectura exclusivamente). 
* @param cantidad Cantidad de elementos a evaluar. 
* @param limite_inf Límite inferior del intervalo cerrado (incluido). 
* @param limite_sup Límite superior del intervalo cerrado (incluido). 
* @param coincidencias Puntero donde se almacenará el total de elementos en el rango (salida). 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a memoria válida.
* @post Si retorna true, *coincidencias contendrá la cantidad de elementos hallados en el rango. 
* 
* @return true si se efectuó el conteo con éxito, * false si 'arreglo' o 'coincidencias' son NULL. 
*/ 
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
