#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Calcula el promedio de los elementos de un arreglo de enteros.
 *          El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor a 0.
 * @param arreglo[int] de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @return valor double resultante del promedio de los elementos del arreglo.
 *          Retorna 0.0 si el arreglo es NULL o la cantidad es 0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);


/**
 * @brief Busca en un arreglo de enteros un valor especifico.
 *          El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor a 0.
 * @param arreglo[int] de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @return true si el valor buscado pertenece al arreglo.
 *          false si los parametros son invalidos o si no se encuentra el valor buscado.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
