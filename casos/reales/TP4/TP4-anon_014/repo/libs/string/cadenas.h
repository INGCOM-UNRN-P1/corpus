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
 * @brief Duplica en heap una cadena, midiendo a lo sumo capacidad_max bytes.
 * @param origen cadena a duplicar.
 * @param capacidad_max cantidad máxima de caracteres a inspeccionar.
 * @returns nueva cadena en heap, o NULL si origen es NULL, capacidad_max es
 *          0 o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);


/**
 * @brief Concatena dos cadenas en un bloque nuevo de tamaño exacto.
 * @param primera primera cadena.
 * @param cap_primera máximo de caracteres a inspeccionar en primera.
 * @param segunda segunda cadena.
 * @param cap_segunda máximo de caracteres a inspeccionar en segunda.
 * @returns nueva cadena en heap, o NULL si alguna cadena es NULL o falla
 *          malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);


/**
 * @brief Libera una cadena en heap y deja el puntero en NULL.
 * @param puntero_cadena dirección del puntero a la cadena (acepta NULL).
 * @post *puntero_cadena vale NULL.
 */
void cadena_liberar_segura(char **puntero_cadena);





/**
 * @brief Extrae una subcadena de origen en un bloque nuevo de tamaño exacto.
 * @param origen cadena de la que se extrae.
 * @param capacidad_max máximo de caracteres a inspeccionar en origen.
 * @param inicio índice del primer carácter a copiar.
 * @param cantidad máximo de caracteres a copiar.
 * @returns nueva cadena en heap ("" si inicio supera la longitud), o NULL si
 *          origen es NULL o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);

/**
 * @brief Genera una nueva cadena con los caracteres de origen invertidos.
 * @param origen cadena a invertir (no se modifica).
 * @param capacidad_max máximo de caracteres a inspeccionar en origen.
 * @returns nueva cadena en heap, o NULL si origen es NULL o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
