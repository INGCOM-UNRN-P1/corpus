#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula el promedio de los elementos de un arreglo de enteros.
 * 
 * Hace uso de la función arreglo_sumar de la biblioteca libarreglos.
 * 
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 * @return double Promedio de los elementos, o 0.0 si el arreglo es NULL o cantidad es 0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Determina si un número entero buscado pertenece al arreglo.
 * 
 * Hace uso de la función arreglo_buscar de la biblioteca libarreglos.
 * 
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 * @param valor Número entero que se desea buscar.
 * @return true Si el valor existe en el arreglo.
 * @return false Si el valor no se encuentra, o si el arreglo es NULL o cantidad es 0.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
