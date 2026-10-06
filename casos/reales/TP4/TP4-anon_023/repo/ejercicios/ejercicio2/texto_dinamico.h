/**
 * @file texto_dinamico.h
 * @brief Ejercicio 2: Normalizacion y Limpieza Dinamica de Cadenas (sin structs).
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Elimina espacios iniciales y finales (trimming) copiando el resultado en heap.
 *
 * Reserva el bloque de memoria exacto en heap para alojar la subcadena sin espacios
 * en los extremos junto con el caracter terminador nulo ('\0').
 *
 * @param[in] origen Cadena de caracteres original a procesar.
 *
 * @return Puntero a la nueva cadena limpia en heap (char *), o NULL si origen es NULL,
 *         si la cadena solo contiene espacios o si falla la memoria.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Replica una cadena de caracteres un numero determinado de veces en un nuevo bloque en heap.
 *
 * Si veces es 0, retorna una cadena vacia dinamica ("") de 1 byte ('\0').
 *
 * @param[in] origen Cadena de texto base a duplicar en secuencia.
 * @param[in] veces Cantidad de repeticiones consecutivas a generar.
 *
 * @return Puntero a la cadena resultante en heap, o NULL si origen es NULL o si falla la asignacion.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 