/**
 * @file registro_csv.h
 * @brief Biblioteca para gestionar listas dinámicas de cadenas en heap.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación.
 */

#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una lista dinámica vacía de cadenas.
 *
 * @pre No requiere parámetros.
 *
 * @post Retorna una lista vacía o NULL.
 *
 * @return Puntero a la lista vacía o NULL.
 */
char **lista_cadenas_crear(void);

/**
 * @brief Agrega una copia dinámica de una cadena a la lista.
 *
 * La cadena recibida se duplica y la copia se agrega al final de la lista.
 *
 * @param lista Puntero al puntero que contiene la lista.
 * @param cantidad Puntero a la cantidad actual de cadenas.
 * @param cadena Cadena que se desea agregar.
 *
 * @pre lista y cantidad deben ser válidos y cadena no debe ser NULL.
 *
 * @post Si la operación es exitosa, la lista contiene una nueva copia de
 *       cadena y cantidad se incrementa en uno.
 *
 * @return true si la cadena fue agregada correctamente, false en caso
 *         contrario.
 */
bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena);

/**
 * @brief Libera una lista dinámica de cadenas.
 *
 * Primero libera cada cadena almacenada y luego libera el arreglo de
 * punteros.
 *
 * @param lista Lista dinámica de cadenas.
 * @param cantidad Cantidad de cadenas almacenadas.
 *
 * @pre Si lista no es NULL, cantidad debe corresponder a la cantidad de
 *      cadenas almacenadas.
 *
 * @post Toda la memoria asociada a la lista y sus cadenas es liberada.
 */
void lista_cadenas_destruir(char **lista, size_t cantidad);

#endif 
