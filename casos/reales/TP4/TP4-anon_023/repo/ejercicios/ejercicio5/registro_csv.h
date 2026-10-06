/**
 * @file registro_csv.h
 * @brief Ejercicio 5: Arreglo Dinamico de Cadenas (Tokens de CSV) en Heap.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Tokeniza una linea de texto delimitada en un arreglo dinamico de cadenas en heap.
 *
 * Reserva un arreglo de punteros (char **) y asigna cada token en memoria dinamica independiente
 * con su respectivo terminador nulo ('\0').
 *
 * @param[in] linea Cadena con la linea a tokenizar.
 * @param[in] delimitador Caracter separador de campos.
 * @param[out] cantidad_tokens Puntero donde se almacenara la cantidad de tokens encontrados.
 *
 * @return Puntero char** al arreglo de cadenas en heap, o NULL ante linea invalida o fallo de memoria.
 */
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);

/**
 * @brief Libera simetricamente un arreglo dinamico de cadenas y anula el puntero original.
 *
 * Libera primero cada una de las cadenas individuales y finalmente el bloque del arreglo de punteros,
 * asignando NULL a *puntero_arreglo para prevenir punteros colgantes.
 *
 * @param[in, out] puntero_arreglo Direccion del puntero al arreglo de cadenas (char ***).
 * @param[in] cantidad Cantidad de cadenas contenidas en el arreglo.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 
