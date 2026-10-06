/**
 * @file string.h
 * @brief Biblioteca libstring: manipulación y gestión de cadenas seguras en
 * heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica en heap debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - Sin uso de structs: operaciones sobre char *y dobles punteros char**.
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/** COPIADA DE UN TP ANTERIOR Y MODIFICADA PARA QUE OPERE CON ARITMETICA DE
 * PUNTEROS
 * @brief Determina la longitud útil de una cadena de caracteres antes del
 * caracter nulo.
 * @param cadena es el puntero al inicio de la cadena.
 * @param capacidad es la cantidad de elementos total de la cadena.
 *
 * @return la cantidad de caracteres útiles, 0 ante parámetros inválidos.
 */
size_t longitud_util_cadena(const char *cadena, size_t capacidad);

/** COPIADA DE UN TP ANTERIOR Y MODIFICADA PARA QUE OPERE CON CHAR
 * @brief Intercambia la posición de 2 elementos de una cadena mediante
 * aritmética de punteros.
 * @param primer es el puntero al primer caracter.
 * @param segundo es el puntero al regundo caracter.
 *
 * @pre los punteros deben ser válidos y accesibles.
 * @post intercambia la posición de los caracteres en la cadena si los
 * parámetros son válidos, no opera casoc ontrario.
 */
void intercambiar_char(char *primer, char *segundo);


/**
 * @brief Recibe una cadena de caracteres, su lonitud y la copia al heap.
 * @param origen es el puntero al inicio de la cadena.
 * @param capacidad_max es la capacidad máxima de la cadena 'origen'.
 *
 * @pre el puntero debe ser válido y accesible, capacidad > 0;
 *
 * @return el puntero a la copia de la cadena en el heap, NULL si los parámetros
 * son inválidos o malloc falla.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);


/**
 * @brief Recibe dos cadenas de caracteres y sus respectivas
 * capacidades máximas de inspección.Mide ambas cadenas de forma segura,
 * reserva en el heap la cantidad exacta (longitud1 + longitud2 + 1 byte para
 * '\0') y construye la cadena concatenada.
 * @param primera es el puntero a la primera cadena.
 * @param cap_primera es la capacidad máxima de la primera cadena.
 * @param segunda es el puntero a la segunda cadena.
 * @param cap_segunda es la capacidad máxima de la segunda cadena.
 *
 * @pre los punteros deben ser válidos y accesibles.
 * @return el puntero al nuevo bloque en el heap, Null ante argumentos inválidos
 * o fallo de memoria.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);


/**
 * @brief lubera de forma segura un bloque en el heap y asigna NULL a su puntero
 * de referencia.
 * @param puntero_cadena es el puntero del puntero que señala al inicio del
 * bloque.
 * @post libera el bloque y asigna NULL al puntero, si alguno de los punteros es
 * NULL no opera.
 */
void cadena_liberar_segura(char **puntero_cadena);


/**
 * @brief Extraer una porción de 'origen' a partir del índice 'inicio', copiando
 * a lo sumo 'cantidad' caracteres en un nuevo bloque de memoria dinámica en el
 * heap.La cadena resultante queda finalizada en el caracter nulo.
 * @param origen es el puntero a la cadena origen.
 * @param capacidad_max es la capacidad máxima de la cadena origen.
 * @param inicio es el índice desde donde se comienza a copiar.
 * @param cantidad es la cantidad de elementos a copiar.
 *
 * @return el puntero al inicio de la cadena resultante ene l heap. ("") si
 * 'inicio' supera la longitud de la cadena.NULL si 'origen' es NULL o galla la
 * memoria.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);


/**
 * @brief Genera y retornar una nueva cadena en memoria dinámica que contenga
 * los caracteres de 'origen' en orden invertido, finalizada en '\0'.
 * @param origen es el puntero al inicio de la cadena.
 * @param capacidad_max es el tamaño total de la cadena.
 *
 * @pre el puntero debe ser válido y accesible.
 *
 * @return el puntero al bloque del heap donde se encuentra la cadena invertida.
 * NULL si 'origen' es inválido o falla malloc.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
