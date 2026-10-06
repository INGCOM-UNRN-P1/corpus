#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/** Valor que retorna distancia_punteros() ante argumentos inválidos. */
#define DISTANCIA_INVALIDA (-1)

/**
 * Busca la primera aparición de un valor en un arreglo de enteros,
 * recorriéndolo con aritmética de punteros.
 *
 * @param arreglo  Puntero al primer elemento del arreglo (solo lectura).
 * @param cantidad Cantidad de elementos del arreglo.
 * @param buscado  Valor a buscar.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @returns Un puntero a la primera posición que contiene 'buscado', o NULL
 *          si no aparece, si arreglo es NULL o si cantidad es 0.
 *
 * @post El puntero retornado, si no es NULL, apunta dentro de
 *       [arreglo, arreglo + cantidad). El arreglo no se modifica.
 *
 * @note A diferencia de buscar_puntero_minimo() (Ejercicio 6), que siempre
 *       recorre el rango completo, esta función corta al encontrar el
 *       valor. En el caso promedio revisa cerca de la mitad del arreglo,
 *       aunque en el peor caso (valor al final o ausente) las dos recorren
 *       los n elementos: ambas son O(n).
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado);

/**
 * Calcula el índice de un elemento dentro de un arreglo mediante la resta
 * de punteros (elemento - inicio).
 *
 * @param inicio   Puntero al primer elemento del arreglo.
 * @param elemento Puntero a un elemento del mismo arreglo.
 *
 * @pre Si ninguno es NULL, ambos apuntan dentro del mismo arreglo.
 *
 * @returns La distancia en elementos desde 'inicio' hasta 'elemento', o
 *          DISTANCIA_INVALIDA si alguno es NULL o si 'elemento' está antes
 *          de 'inicio'.
 *
 * @post Si el resultado no es DISTANCIA_INVALIDA, inicio + resultado ==
 *       elemento.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
