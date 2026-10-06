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

#include "cadenas_tp2.h"


/**
 * @brief Duplica una cadena de manera segura.
 * @pre 'origen' no debe ser NULL.
 * @pre 'capacidad_max' no debe ser NULL.
 * @post devuelve un puntero con al direeccion de memoria de la copia
 *  del arreglo.
 * @param origen Es la cadena original.
 * @param capacidad_max Es el tamanio de la cadena.
 * @return devuelve el puntero apuntando a la cadena duplicada.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);


/**
 * @brief Concatena dos cadenas.
 * @pre 'primera' y 'segunda' no deben ser NULL.
 * @pre 'cap_primera' y 'cap_segunda' no deben ser 0.
 * @post retorna el puntero *char al nuevo cloquee o NULL ante
 *  argumentos invalidos o fallo de memoria.
 * @param primera es una cadena.
 * @param segunda es una cadena.
 * @param cap_primera es la capacidad de la cadena primera.
 * @param cap_segunda es la capacidad de la cadena segunda.
 * @return Retorna el puntero char *al nuevo bloque en heap, o NULL ante
 *  argumentos inválidos o fallo de memoria.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);


/**
 * @brief Se libera la memoria de la cadena.
 * @post Se libera el espacio en memoria y el puntero apuntara a NULL.
 * @param puntero_cadena es eel puntero que punta a la cadena
 */
void cadena_liberar_segura(char **puntero_cadena);


/**
 * @brief Se extrae un pedazo de la cadena.
 * @pre 'origen' no puede ser NULL.
 * @pre 'inicio' no puede superar la longitud de la cadena.
 * @post se devuelve el pedazo de la cadena extraida.
 * @param origen es la cadena original.
 * @param capacidad_max es el tamanio maximo de la cadena.
 * @param inicio es la pocision en la que iniciara la subcadena.
 * @param cantidad son la cantidad de caracteres que se extraeran en la cadena.
 * @return Si origen es NULL o falla la meemoria retorna NULL,
 *  sino retorna el pedazo de la cadena.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);


/**
 * @brief Se invierte la cadena.
 * @pre 'origen' no deeebe ser NULL.
 * @pre 'capacidad_max' no debe ser 0.
 * @post Devuelve la misma cadena pero copiada en el orden invertido.
 * @param origen es la cadena original.
 * @param invertida es la cadeena invertida.
 * @param capacidad_max es el tamanio total de elementos de las cadenas.
 * @return Devuelve la cadena invertida.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);
#endif 
