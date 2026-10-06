#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Ordena dos variables enteras recibidas por referencia de menor a mayor.
 *
 * @details Si el valor apuntado por 'menor' es estrictamente mayor que el
 *          valor apuntado por 'mayor', los intercambia invocando a la función
 *          'intercambiar'. Si alguno de los punteros es NULL o los valores
 *          ya están ordenados, no realiza ningún cambio.
 *
 * @param[in,out] menor Puntero a la variable entera que debe contener el valor menor.
 * @param[in,out] mayor Puntero a la variable entera que debe contener el valor mayor.
 *
 * @pre Ninguna (maneja de forma segura punteros válidos o NULL)
 * @post El valor en '*menor' es menor o igual al valor en '*mayor' (si ambos eran no NULL).
 *
 * @return Ninguno (void).
 */

void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres variables enteras recibidas por referencia en orden ascendente (*a <= *b <= *c).
 *
 * @details Utiliza llamadas sucesivas a 'ordenar_par' e 'intercambiar' para garantizar que
 *          los tres valores queden ordenados de menor a mayor. Si alguno de los punteros
 *          es NULL, la función no realiza ninguna modificación en la memoria.
 *
 * @param[in,out] a Puntero a la primera variable entera.
 * @param[in,out] b Puntero a la segunda variable entera.
 * @param[in,out] c Puntero a la tercera variable entera.
 *
 * @pre Ninguna (maneja de forma segura punteros válidos o NULL).
 * @post Los contenidos de las variables apuntadas cumplen que *a <= *b <= *c (si todos no eran NULL).
 *
 * @return Ninguno (void).
 */

void ordenar_tria(int *a, int *b, int *c);


/**
 * @brief Suma acumulativamente los elementos de un arreglo usando aritmética de punteros.
 *
 * @details Recorre el arreglo apuntado por 'arreglo' de forma secuencial mediante
 *          aritmética de punteros (sin utilizar el operador de indexación '[]')
 *          y almacena la suma total de los elementos en la dirección apuntada
 *          por 'resultado'.
 *
 * @param[in] arreglo Puntero constante al primer elemento del arreglo a sumar.
 * @param[in] cantidad de elementos en el arreglo.
 * @param[out] resultado Puntero a la variable de tipo long long donde se guardará la suma.
 *
 * @pre El puntero 'arreglo' debe apuntar a un arreglo válido de al menos 'cantidad' elementos.
 * @pre El puntero 'resultado' debe apuntar a una variable de tipo long long válida.
 * @post Si la función retorna true, el valor apuntado por 'resultado' contendrá
 *       la suma de todos los elementos. Si 'cantidad' es 0, '*resultado' será 0.
 *
 * @return 'true' si 'arreglo' y 'resultado' no son NULL; 'false' en caso contrario.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);


#endif 
