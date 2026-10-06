#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Calcular el promedio de los elementos de un arreglo de enteros haciendo uso
 * de la biblioteca libarreglos.
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @return el promedio de los elementos del arreglo.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);


/**
 * @brief Determina si un arreglo de enteros contiene el valor buscado,
 * haciendo uso de la función arreglo_buscar de libarreglos.
 * @param arreglo es el puntero al inicio del del arreglo.
 * @param cantidad es el número de elementos que contiene el arreglo.
 * @param valor es el número que se busca dentro del arreglo.
 * @return true si el valor pertenece al arreglo, false caso contrario.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
