/**
 * @file cadenas.h
 * @brief Biblioteca para manipular cadenas dinámicas seguras sin structs.
 */

#ifndef STRING_H
#define STRING_H

#include <stddef.h>

/**
 * @brief Duplica una cadena inspeccionando como máximo capacidad_max caracteres.
 * @param origen Cadena a duplicar.
 * @param capacidad_max Máximo de caracteres que se pueden inspeccionar.
 * @return Copia dinámica terminada en '\0' o NULL ante parámetros inválidos o falta de memoria.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);

/**
 * @brief Concatena dos cadenas en un bloque dinámico exacto.
 * @param primera Primera cadena.
 * @param cap_primera Máximo de caracteres a inspeccionar en primera.
 * @param segunda Segunda cadena.
 * @param cap_segunda Máximo de caracteres a inspeccionar en segunda.
 * @return Nueva cadena concatenada o NULL ante error.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);

/**
 * @brief Libera una cadena dinámica y deja el puntero en NULL.
 * @param puntero_cadena Dirección del puntero a la cadena.
 */
void cadena_liberar_segura(char **puntero_cadena);

/**
 * @brief Extrae una subcadena en un nuevo bloque dinámico.
 * @param origen Cadena de origen.
 * @param capacidad_max Máximo de caracteres a inspeccionar.
 * @param inicio Índice inicial de la porción.
 * @param cantidad Cantidad máxima de caracteres a copiar.
 * @return Subcadena dinámica; si inicio supera la longitud retorna "" en heap.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);

/**
 * @brief Crea una copia invertida de una cadena.
 * @param origen Cadena original.
 * @param capacidad_max Máximo de caracteres a inspeccionar.
 * @return Cadena invertida en heap o NULL ante error.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
