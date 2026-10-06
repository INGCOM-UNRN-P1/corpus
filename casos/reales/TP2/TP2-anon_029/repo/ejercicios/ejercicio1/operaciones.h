#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Se calcula el promedio de los elementos de un arreglo enteros.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede ser 0.
 * @post Devuelve el promedio de los elemntos del arreglo.
 * @param arreglo es el arreglo en el que se encuentran los numeros.
 * @param cantidad cantidad de elementos del arreglo.
 * @return devuelve el promedio de los elementos contenidos en la cadena.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);


/**
 * @brief se busca el numero que pertenece al arreglo.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede ser 0.
 * @post devuelve un valor booleano si se encuentra
 * el numero buscado en el arreeglo.
 * @param arreglo es el arreglo en el que se encuentran los numeros.
 * @param cantidad cantidad de elementos del arreglo.
 * @return devuelve true, si se encuentra el numero bsucado, sino false.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
