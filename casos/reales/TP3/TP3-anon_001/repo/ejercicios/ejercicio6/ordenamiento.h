#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca la dirección de memoria del elemento mínimo en un rango de enteros.
 *
 * @details Recorre el rango semi-abierto [inicio, fin) utilizando exclusivamente
 *          aritmética de punteros y retorna la posición del menor valor.
 *
 * @param[in] inicio Puntero al comienzo del rango a evaluar.
 * @param[in] fin Puntero al límite superior (no inclusivo) del rango.
 *
 * @pre 'inicio' debe ser menor que 'fin' para definir un rango válido.
 * @post No modifica los valores del arreglo referenciado.
 *
 * @return Puntero constante al valor mínimo encontrado dentro del rango.
 *         NULL si 'inicio' es NULL, o si el rango es inválido (inicio >= fin).
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena un arreglo de enteros de forma ascendente utilizando el algoritmo de Selección y punteros.
 *
 * @details Modifica el arreglo in-place iterando sobre los elementos mediante aritmética de punteros.
 *          Para cada posición, utiliza 'buscar_puntero_minimo' para hallar el menor elemento restante
 *          e intercambia sus valores. No utiliza el operador de indexación [].
 *
 * @param[in,out] arreglo Puntero al primer elemento del arreglo de enteros a ordenar.
 * @param[in] cantidad total de elementos presentes en el arreglo.
 *
 * @pre 'arreglo' no debe ser NULL si 'cantidad' es mayor a 0.
 * @post Los elementos en 'arreglo' quedan ordenados en forma no decreciente.
 */
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);


#endif 
