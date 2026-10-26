/**
 * @file csv.h
 * @brief Biblioteca para procesamiento e ingesta de archivos CSV en C11.
 *
 * Trabajo Práctico 7 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#ifndef CSV_H
#define CSV_H

#include <stdbool.h>
#include <stddef.h>


size_t csv_contar_filas(const char *ruta);
size_t csv_contar_columnas(const char *ruta);


size_t csv_leer_matriz(const char *ruta, int *destino, size_t filas, size_t columnas);

#endif 
