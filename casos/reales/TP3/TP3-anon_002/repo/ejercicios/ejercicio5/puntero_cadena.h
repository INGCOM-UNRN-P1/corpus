/**
 * @file puntero_cadena.h
 * @brief Biblioteca de manipulación de cadenas seguras mediante punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * Uso exclusivo de aritmética de punteros para recorrer y modificar cadenas.
 * No se utiliza indexación mediante [].
 * RECIBE LA CAPACIDAD: Parámetro 'size_t cap' con el tamaño total
 * del búfer destino en memoria física (incluyendo terminador).
 * GARANTÍA DE TERMINADOR: Si capacidad > 0, el búfer destino se mantiene
 * terminado con el carácter nulo '\0' cuando la operación es válida.
 * CONTROL DE LÍMITES: Nunca se escribe fuera de [0, capacidad - 1].
 */

#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/** =========================================================================
 * Ejercicio 1: Copia Segura con Aritmética de Punteros
 * =========================================================================
 * @brief Copia una cadena utilizando exclusivamente aritmética de punteros.
 *
 * @param dest Buffer mutable donde se copiará la cadena.
 * @param cap Capacidad total del buffer de destino.
 * @param src Cadena fuente de solo lectura.
 *
 * @pre 'dest' y 'src' no deben ser NULL, 'cap' > 0.
 * @post 'dest' queda terminada con '\0' si la operación es válida.
 *
 * @return bool 'true' si la cadena cupo completa;
 *              'false' si hubo truncamiento o los parámetros son inválidos.
 */
bool copiar_con_punteros(char *dest, size_t cap, const char *src);

/** =========================================================================
 * Ejercicio 2: Concatenación Segura con Aritmética de Punteros
 * =========================================================================
 * @brief Anexa una cadena al final de otra utilizando exclusivamente
 *        aritmética de punteros.
 *
 * @param dest Buffer mutable que contiene la cadena inicial y recibirá
 *             el anexo.
 * @param cap Capacidad total del buffer de destino.
 * @param src Cadena a anexar de solo lectura.
 *
 * @pre 'dest' y 'src' no deben ser NULL, 'cap' > 0.
 * @pre 'dest' debe estar terminada con '\0' dentro de la capacidad indicada.
 * @post 'dest' queda terminada con '\0' si la operación es válida.
 *
 * @return bool 'true' si la cadena se concatenó completa;
 *              'false' si faltó espacio o los parámetros son inválidos.
 */
bool concatenar_con_punteros(char *dest, size_t cap, const char *src);

/** =========================================================================
 * Ejercicio 3: Medición Segura de Longitud con Aritmética de Punteros
 * =========================================================================
 * @brief Mide la longitud de una cadena respetando la capacidad indicada.
 *
 * @param s Cadena de caracteres de solo lectura.
 * @param cap Cantidad máxima de caracteres que pueden recorrerse.
 *
 * @pre 's' debe apuntar a una cadena válida si 'cap' > 0.
 * @post No se modifica el contenido de la cadena.
 *
 * @return size_t Cantidad de caracteres útiles antes de '\0', o 'cap'
 *                si no se encuentra el terminador dentro del límite.
 */
size_t longitud_con_punteros(const char *s, size_t cap);

#endif 