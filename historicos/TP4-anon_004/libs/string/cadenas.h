/**
 * @file string.h
 * @brief Biblioteca libstring: manipulación y gestión de cadenas seguras en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica en heap debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - Sin uso de structs: operaciones sobre char* y dobles punteros char**.
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>


char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);


char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);


void cadena_liberar_segura(char **puntero_cadena);





#endif 
