/**
 * @file busqueda.h
 * @brief Funciones de busqueda lineal con retorno de direccion de memoria y calculo de distancias.
 *
 * Ejercicio 4 - Trabajo Practico 3
 * Programacion 1 - Universidad Nacional de Rio Negro
 */

#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca la primera aparicion de un valor entero en un arreglo.
 *
 * Itera la secuencia de memoria contigua mediante aritmetica de punteros pura sin indexacion ([]).
 *
 * @pre `arreglo` debe apuntar a un bloque continuo de memoria de al menos `cantidad` enteros si cantidad > 0.
 * @post No modifica los datos del arreglo apuntado.
 *
 * @param[in] arreglo Puntero de solo lectura al inicio del arreglo.
 * @param[in] cantidad Cantidad de enteros presentes en el arreglo.
 * @param[in] valor Elemento entero a localizar.
 *
 * @return Puntero constante (const int *) a la direccion del elemento si se encuentra,
 *         o NULL si el valor no existe en el arreglo, si `arreglo` es NULL o si `cantidad` es 0.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * @brief Calcula el indice o distancia relativa de un puntero respecto al inicio del arreglo.
 *
 * Determina el desplazamiento mediante la resta de punteros (p - inicio).
 *
 * @pre Ambos punteros deben pertenecer al mismo bloque de memoria o ser compatibles.
 * @post No se altera ninguna variable ni contenido en memoria.
 *
 * @param[in] inicio Puntero al comienzo del arreglo.
 * @param[in] elemento Puntero a la posicion interna cuya distancia se desea calcular.
 *
 * @return La distancia o indice como ptrdiff_t (>= 0), o -1 si alguno de los punteros es NULL
 *         o si `elemento` apunta a una posicion anterior a `inicio`.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
