/**
 * @file string.h
 * @brief Biblioteca libstring: manipulacion y gestion de cadenas seguras en heap sin structs.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Duplica una cadena en el heap midiendo su longitud de forma acotada.
 *
 * @param[in] origen Cadena de caracteres a duplicar.
 * @param[in] capacidad_max Limite maximo de inspeccion para prevenir desbordes de lectura.
 *
 * @return Puntero a la nueva cadena en el heap (char *), o NULL si origen es NULL,
 *         capacidad_max es 0 o falla la memoria.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);

/**
 * @brief Une dos cadenas en un nuevo bloque en el heap con asignacion exacta.
 *
 * @param[in] primera Primera cadena a concatenar.
 * @param[in] cap_primera Capacidad maxima de inspeccion de la primera cadena.
 * @param[in] segunda Segunda cadena a concatenar.
 * @param[in] cap_segunda Capacidad maxima de inspeccion de la segunda cadena.
 *
 * @return Puntero a la cadena resultante en heap, o NULL ante parametros invalidos o fallo de memoria.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);

/**
 * @brief Libera una cadena dinamica y anula el puntero original.
 *
 * @param[in, out] puntero_cadena Direccion del puntero a la cadena (char **).
 */
void cadena_liberar_segura(char **puntero_cadena);

/**
 * @brief Extrae una porcion de una cadena en un nuevo bloque de memoria en heap.
 *
 * @param[in] origen Cadena de entrada.
 * @param[in] capacidad_max Limite maximo de inspeccion de la cadena origen.
 * @param[in] inicio Indice inicial de la subcadena.
 * @param[in] cantidad Cantidad maxima de caracteres a extraer.
 *
 * @return Puntero a la subcadena en heap terminada en '\0', o NULL si origen es NULL o falla memoria.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);

/**
 * @brief Genera una nueva cadena en el heap con los caracteres invertidos.
 *
 * @param[in] origen Cadena de caracteres a invertir.
 * @param[in] capacidad_max Limite maximo de inspeccion de la cadena origen.
 *
 * @return Puntero a la cadena invertida en heap, o NULL si origen es NULL o falla memoria.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 