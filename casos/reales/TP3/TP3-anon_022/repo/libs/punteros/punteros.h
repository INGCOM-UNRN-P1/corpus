/**
 * @file punteros.h
 * @brief Biblioteca de operaciones fundamentales con punteros y aritmética de punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda manipulación de secuencias o arreglos debe resolverse estrictamente
 *   mediante aritmética de punteros (*p, p++, p + offset, fin - inicio),
 *   evitando el operador de indexación arreglo[i].
 * - Uso riguroso de const-correctness (const char*, const int*) en accesos
 *   de solo lectura.
 * - Validación exhaustiva de punteros nulos (NULL).
 *
 * Observación importante de diseño:
 * Recuerden que no está permitido utilizar ALV's (Arreglos de Longitud Variable / VLA),
 * pero también, este ejercicio no está pensado para utilizar memoria dinámica.
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Intercambia los valores enteros apuntados por dos punteros.
 *
 * Realiza un intercambio (swap) clásico mediante una variable temporal,
 * modificando directamente el contenido de las direcciones de memoria
 * recibidas.
 *
 * @param primer  Puntero a la primera variable entera a intercambiar.
 *                Puede ser NULL.
 * @param segundo Puntero a la segunda variable entera a intercambiar.
 *                Puede ser NULL.
 *
 * @pre  Si 'primer' y 'segundo' son ambos no NULL, deben apuntar a
 *       memoria válida y accesible en escritura.
 * @post Si ambos punteros son no NULL y distintos: *primer contiene el
 *       valor original de *segundo, y *segundo contiene el valor
 *       original de *primer.
 * @post Si 'primer' o 'segundo' es NULL: no se produce ningún efecto
 *       (no se desreferencia ningún puntero).
 * @post Si 'primer' y 'segundo' apuntan a la misma dirección de memoria:
 *       el valor apuntado se preserva sin alteraciones.
 *
 */
void intercambiar(int *primer, int *segundo);


/**
 * @brief Determina el valor mínimo y máximo de un arreglo de enteros.
 *
 * Recorre el arreglo mediante aritmética de punteros, comparando sus
 * elementos para determinar los valores extremos, y los escribe en las
 * variables de salida provistas por el llamador.
 *
 * @param arreglo  Puntero constante al primer elemento del arreglo de
 *                 enteros a recorrer.
 * @param cantidad Número de elementos válidos en 'arreglo'. Debe ser
 *                 mayor a 0.
 * @param minimo   Puntero de salida donde se escribirá el valor mínimo
 *                 encontrado.
 * @param maximo   Puntero de salida donde se escribirá el valor máximo
 *                 encontrado.
 *
 * @pre Para obtener un resultado exitoso, 'arreglo' debe apuntar a una
 *      región de memoria válida con al menos 'cantidad' elementos
 *      contiguos de tipo int.
 * @pre Para obtener un resultado exitoso, 'minimo' y 'maximo' deben
 *      apuntar a memoria válida en escritura.
 *
 * @post Si la función retorna true, 'minimo' contiene el menor valor del
 *       arreglo y 'maximo' contiene el mayor valor del arreglo.
 * @post Si 'arreglo' es NULL, 'cantidad' es 0, o 'minimo'/'maximo' es
 *       NULL, la función retorna false y no modifica ninguna salida válida.
 *
 * @return true si pudo determinar el mínimo y el máximo exitosamente.
 *         false si alguno de los parámetros no permite realizar la
 *         operación.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
