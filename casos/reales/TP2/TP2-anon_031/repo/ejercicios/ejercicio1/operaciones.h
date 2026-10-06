#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Calcula el promedio de los elementos de un arreglo de enteros.
 *
 * Utiliza la funcion arreglo_sumar de la biblioteca libarreglos
 * para obtener la suma total de los elementos.
 *
 * @param arreglo arreglo de numeros enteros.
 * @param cantidad cantidad de elementos del arreglo.
 * @return promedio de los elementos del arreglo. Retorna 0.0 si el arreglo es NULL o si la cantidad es 0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * Determina si un valor entero pertenece a un arreglo.
 *
 * Utiliza la funcion arreglo_buscar de la biblioteca libarreglos.
 *
 * @param arreglo arreglo de numeros enteros.
 * @param cantidad cantidad de elementos del arreglo.
 * @param valor valor entero que se desea buscar.
 * @return true si el valor se encuentra en el arreglo y false en caso contrario.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif