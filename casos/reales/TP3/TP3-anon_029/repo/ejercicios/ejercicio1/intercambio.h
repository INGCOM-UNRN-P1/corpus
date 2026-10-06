#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**
 * @brief Se comparan dos valores para saber cual es el menor.
 * @pre 'menor' y 'mayor' no peuden ser NULL.
 * @post Intercambia las posiciones de los valores en el caso de que sean
 * mayor y menor, respectivamente.
 * @param menor Es el valor menor.
 * @param mayor Es el valor mayor.
 * @return Devuelve al par ordenado de menor a mayor.
 * Si fallan las precondicones se corta el procedimiento.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Se ordenan 3 valores de amnera ascendente.
 * @pre Ni 'numero1', 'numero2', 'nuemro3' pueden ser NULL.
 * @post Se ordenan ascendentemente llamando a 'ordenar_par'
 * @param numero1 Es el primer numero
 * @param numero2 Es el segundo numero.
 * @param numero3 Es el tercer numero.
 * @return devuelve la tria ordenada.
 * Si fallan las precondicones se corta el procedimiento.
 */
void ordenar_tria(int *numero1, int *numero2, int *numero3);

/**
 * @brief Se suman los elementos de un arreglo.
 * @pre 'arreglo', 'resultado' no pueden ser NULL.
 * @post retorna false si false si arreglo o resultado son NULL.
 * Y si se pudo efectuar el calculo.
 * @param arreglo Es el arreglo que tiene los elemntos a sumar.
 * @param cantidad Es la cantidad de elementos de arreglo.
 * @param resultado Es el puntero de salida.
 * @return retorna false si false si arreglo o resultado son NULL.
 * Y si se pudo efectuar el calculo.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);
#endif 
