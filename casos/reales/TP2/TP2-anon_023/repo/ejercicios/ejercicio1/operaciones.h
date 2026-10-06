#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula el promedio aritmetico de los elementos de un arreglo de enteros.
 *
 * Hace uso de la biblioteca libarreglos para obtener la sumatoria de los elementos.
 *
 * @pre El puntero `arreglo` debe apuntar a un bloque de memoria valido si `cantidad > 0`.
 * @post No modifica el arreglo original.
 *
 * @param arreglo Arreglo de enteros a promediar. Puede ser NULL si cantidad es 0.
 * @param cantidad Numero de elementos contenidos en el arreglo.
 *
 * @return Promedio en punto flotante (double) de los valores. Si el arreglo es nulo
 *         o la cantidad es 0, retorna 0.0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Determina si un numero entero especifico pertenece al arreglo.
 *
 * Utiliza la funcion `arreglo_buscar` provista por la biblioteca libarreglos.
 *
 * @pre El puntero `arreglo` debe ser valido si `cantidad > 0`.
 * @post No modifica el arreglo original.
 *
 * @param arreglo Arreglo de enteros sobre el cual realizar la busqueda.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Numero entero a buscar.
 *
 * @return true si el valor se encuentra presente en el arreglo, false en caso contrario
 *         o si los parametros son invalidos.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
