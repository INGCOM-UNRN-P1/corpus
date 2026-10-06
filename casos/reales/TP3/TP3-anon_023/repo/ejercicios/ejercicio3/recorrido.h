/**
 * @file recorrido.h
 * @brief Funciones de recorrido, copia e inversion in-place mediante aritmetica de punteros.
 *
 * Ejercicio 3 - Trabajo Practico 3
 * Programacion 1 - Universidad Nacional de Rio Negro
 */

#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Copia una cantidad especifica de elementos desde un arreglo de origen a uno destino.
 *
 * El copiado se realiza elemento a elemento desplazando punteros en memoria contigua,
 * prohibiendo estrictamente el operador de indexacion ([]).
 *
 * @pre `destino` debe apuntar a un bloque con capacidad para al menos `cantidad` enteros si cantidad > 0.
 * @pre `origen` debe apuntar a un bloque valido con al menos `cantidad` enteros si cantidad > 0.
 * @post Si la operacion es exitosa, los primeros `cantidad` elementos de `destino` son identicos a `origen`.
 *       El bloque apuntado por `origen` no se modifica.
 *
 * @param[out] destino Puntero al inicio del bloque de memoria destino donde se escribiran los datos.
 * @param[in] origen Puntero al inicio del arreglo fuente de solo lectura.
 * @param[in] cantidad Cantidad de elementos enteros a copiar.
 *
 * @return true si la copia se realizo correctamente (o si cantidad == 0), false si `destino` u `origen` son NULL
 *         estando cantidad > 0.
 */
bool copiar_arreglo(int *destino, const int *origen, size_t cantidad);

/**
 * @brief Invierte los elementos de un arreglo in-place mediante dos punteros convergentes.
 *
 * Utiliza dos punteros (uno al inicio y otro al ultimo elemento valido) que avanzan
 * hacia el centro intercambiando valores a traves de la funcion `intercambiar`.
 *
 * @pre `arreglo` debe apuntar a un bloque contiguo de memoria modificable de al menos `cantidad` enteros.
 * @post Si la operacion tiene exito, el orden de los elementos en `arreglo` queda invertido.
 *       Si `arreglo` es NULL o `cantidad <= 1`, la memoria queda sin alteraciones.
 *
 * @param[in, out] arreglo Puntero al inicio del arreglo de enteros a invertir.
 * @param[in] cantidad Cantidad de elementos presentes en el arreglo.
 *
 * @return true si la inversion se efectuo o si cantidad <= 1 con arreglo valido,
 *         false si `arreglo` es NULL con cantidad > 0.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
