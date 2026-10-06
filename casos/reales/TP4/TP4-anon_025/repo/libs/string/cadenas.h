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


/**
 * @brief Clona una cadena limitando la inspeccion para mayor seguridad
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);



 /**
  * @brief Concatena dos cadenas reservando el heap exacto para ambos
  */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);



 /**
  * @brief Libera la memoria de una cadena dinamica y anula su puntero
  */
void cadena_liberar_segura(char **puntero_cadena);



/**
 * @brief Extrae un fragmento de la cadena origen creando una nueva cadena
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad);



 /**
  * @brief Crea una nueva cadena en heap con los caracteres de origen inversos
  */
 char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
