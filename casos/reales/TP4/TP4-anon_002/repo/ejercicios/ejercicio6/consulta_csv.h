/**
 * @file consulta_csv.h
 * @brief Biblioteca para almacenar y filtrar texto multilinea dinámico.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación.
 */

/**
 * @file consulta_csv.h
 * @brief Funciones para almacenar y filtrar líneas de texto dinámicamente.
 */

#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Agrega una copia dinámica de una línea a una lista.
 *
 * @param lineas Puntero al arreglo dinámico de líneas.
 * @param cantidad Cantidad actual de líneas almacenadas.
 * @param linea Línea que se desea agregar.
 * @pre lineas y cantidad deben ser punteros válidos y linea debe ser una cadena válida.
 * @post Si retorna true, la lista contiene una copia de linea y cantidad aumenta en uno.
 * @return true si la línea fue agregada correctamente, false en caso contrario.
 */
bool agregar_linea(char ***lineas, size_t *cantidad, const char *linea);

/**
 * @brief Determina si una cadena contiene una subcadena.
 *
 * @param linea Cadena en la que se realizará la búsqueda.
 * @param subcadena Subcadena que se desea buscar.
 * @pre linea y subcadena deben ser punteros válidos.
 * @post Las cadenas recibidas no son modificadas.
 * @return true si la subcadena está presente, false en caso contrario.
 */
bool contiene_subcadena(const char *linea, const char *subcadena);

/**
 * @brief Muestra las líneas que contienen una determinada subcadena.
 *
 * @param lineas Arreglo dinámico de líneas.
 * @param cantidad Cantidad de líneas almacenadas.
 * @param subcadena Subcadena utilizada para filtrar las líneas.
 * @pre lineas y subcadena deben ser punteros válidos.
 * @post Las líneas almacenadas no son modificadas.
 */
void mostrar_lineas_filtradas(char **lineas, size_t cantidad,
                              const char *subcadena);

/**
 * @brief Libera la memoria utilizada por una lista de líneas.
 *
 * @param lineas Arreglo dinámico de líneas.
 * @param cantidad Cantidad de líneas almacenadas.
 * @pre lineas debe apuntar a una lista de líneas válida o ser NULL.
 * @post La memoria de la lista y de cada una de sus líneas es liberada.
 */
void liberar_lineas(char **lineas, size_t cantidad);

#endif