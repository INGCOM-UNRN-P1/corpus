#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula el promedio de los elementos de un arreglo.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post El arreglo no se modifica.
 *
 * @return El promedio de los elementos.
 * @return 0.0 si el arreglo es NULL o cantidad es 0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Verifica si un valor se encuentra dentro de un arreglo.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Numero que se desea buscar.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post El arreglo no se modifica.
 *
 * @return true si el valor se encuentra en el arreglo.
 * @return false si el valor no se encuentra.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
