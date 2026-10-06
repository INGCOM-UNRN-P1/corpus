/**
 * @file cadenas.h
 * @brief Biblioteca de manipulación y gestión dinámica de cadenas.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación.
 */

#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Duplica una cadena en memoria dinámica.
 *
 * @param origen Cadena que se desea duplicar.
 * @param capacidad_max Capacidad máxima de la cadena de origen.
 *
 * @pre origen puede ser NULL; si no lo es, debe apuntar a una cadena válida
 *      y capacidad_max debe ser mayor que cero.
 *
 * @post Retorna una copia dinámica de la cadena, terminada en '\0',
 *       o NULL si la operación no puede realizarse.
 *
 * @return Puntero a la cadena duplicada o NULL ante un error.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);

/**
 * @brief Une dos cadenas en una nueva cadena dinámica.
 *
 * @param primera Primera cadena que se desea unir.
 * @param cap_primera Capacidad máxima de la primera cadena.
 * @param segunda Segunda cadena que se desea unir.
 * @param cap_segunda Capacidad máxima de la segunda cadena.
 *
 * @pre primera y segunda deben apuntar a cadenas válidas, y sus capacidades
 *      deben ser mayores que cero.
 *
 * @post Retorna una nueva cadena dinámica que contiene primera seguida de
 *       segunda, terminada en '\0', o NULL si la operación no puede realizarse.
 *
 * @return Puntero a la cadena unida o NULL ante un error.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);

/**
 * @brief Libera una cadena reservada dinámicamente.
 *
 * @param puntero_cadena Dirección del puntero que contiene la cadena dinámica.
 *
 * @pre puntero_cadena puede ser NULL o apuntar a un puntero de cadena válido.
 *
 * @post Si puntero_cadena y la cadena apuntada son válidos, la memoria es
 *       liberada y el puntero queda establecido en NULL.
 */
void cadena_liberar_segura(char **puntero_cadena);

/**
 * @brief Crea una subcadena en memoria dinámica.
 *
 * @param origen Cadena de la cual se extraerá la subcadena.
 * @param capacidad_max Capacidad máxima de la cadena de origen.
 * @param inicio Posición inicial de la subcadena.
 * @param cantidad Cantidad máxima de caracteres a extraer.
 *
 * @pre origen debe apuntar a una cadena válida y capacidad_max debe ser mayor
 *      que cero.
 *
 * @post Retorna una nueva cadena dinámica con los caracteres solicitados,
 *       terminada en '\0', o NULL si la operación no puede realizarse.
 *
 * @return Puntero a la subcadena o NULL ante un error.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);

/**
 * @brief Invierte una cadena en memoria dinámica.
 *
 * @param origen Cadena que se desea invertir.
 * @param capacidad_max Capacidad máxima de la cadena de origen.
 *
 * @pre origen debe apuntar a una cadena válida y capacidad_max debe ser mayor
 *      que cero.
 *
 * @post Retorna una nueva cadena dinámica con los caracteres de origen en
 *       orden inverso, terminada en '\0', o NULL si la operación no puede
 *       realizarse.
 *
 * @return Puntero a la cadena invertida o NULL ante un error.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

/**
 * prototipo de funciones del tp2
 *
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);
/**
 * @brief [completar: qué hace cadena_copiar]
 *
 * @param destino [completar: qué representa destino]
 * @param capacidad [completar: qué representa capacidad]
 * @param origen [completar: qué representa origen]
 * @return [completar: qué devuelve]
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);
/**
 * @brief [completar: qué hace cadena_concatenar]
 *
 * @param destino [completar: qué representa destino]
 * @param capacidad [completar: qué representa capacidad]
 * @param origen [completar: qué representa origen]
 * @return [completar: qué devuelve]
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

#endif 
