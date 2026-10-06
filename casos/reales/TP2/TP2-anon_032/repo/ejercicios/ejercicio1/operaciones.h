#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Calcula el promedio de los elementos de un arreglo de enteros.
 * @param arreglo El arreglo del que se calculara el promedio.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @pre El arreglo no debe ser nulo y cantidad debe ser mayor a cero.
 * @post Se devolvera un double que representa el promedio de lo elementos en el arreglo sin modificarlo.
 * @returns Retorna el promedio del valor de los elementos, si el arreglo es 
 * nulo o cantidad es cero retorna 0.0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Determina si un número entero buscado pertenece al arreglo.
 * @param arreglo El arreglo en el que se buscara el numero.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @param valor El valor a buscar.
 * @pre Cantidad debe ser mayor a cero y el arreglo no debe ser nulo.
 * @post Retorna un booleano sin modificar el arreglo.
 * @returns Si el arreglo contiene el valor retorna true, si no lo contiene o hubo
 * errores retorna false.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
