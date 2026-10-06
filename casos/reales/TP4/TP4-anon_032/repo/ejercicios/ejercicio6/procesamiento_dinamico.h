#ifndef PROCESAMIENTO_DINAMICO_H
#define PROCESAMIENTO_DINAMICO_H

#include "lista_dinamica.h" // Incluido a la fuerza debido a problemas tecnicos
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


/**
 * @brief Determina si una cadena contiene un patron.
 *
 * @param pajar La cadena sdonde se buscara el patron.
 * @param capacidad_pajar La capacidad de pajar.
 * @param aguja La cadena que representa el patron a buscar en pajar.
 * @param capacidad_aguja La capacidad de aguja.
 * @pre Los punteros no deben ser nulos y las capacidades de las cadenas no deben
 * ser cero.
 * @post Se determinara si la cadena contiene el patron sin modificar ninguna cadena.
 * @return Devuelve true si la operacion se completo con exito o false en
 * caso contrario.
 */
bool contiene_subcadena(const char *pajar, size_t capacidad_pajar, const char *aguja, size_t capacidad_aguja);

/**
 * @brief Lee las lineas de stdin hasta encontrar EOF y guarda sus copias.
 *
 * @param lista La lista donde se guardaran los punteros a las listsa.
 * @param cantidad La cantidad de lineas guardadas en lista.
 * @pre Los parametros no deben ser nulos y cantidad debe ser una variable
 * reservada para contar las lineas guardadas en lista ya que se modifica.
 * @post Se guardara cada linea en su propio bloque en heap y se agregara su puntero a lista.
 * @return Devuelve true si la operacion se completo con exito o false en
 * caso contrario.
 */
bool leer_lineas(char ***lista, size_t *cantidad);

/**
 * @brief Filtra lineas para imprimir las que contengan un patron.
 *
 * @param lista La lista de donde se imprimiran las cadenas.
 * @param cantidad La cantidad de cadenas en lista.
 * @param subcadena El patron a buscar en las cadenas de lista.
 * @param capacidad La capacidad de subcadena.
 * @pre Ninguno de los punteros pasados por parametro debe ser nulo y capacidad debe ser
 * mayor a cero.
 * @post Se imprimiran las lineas que tengan el patron sin modificar sus bloques ni la lista
 * de punteros. 
 */
void filtrar_lineas(char **lista, size_t cantidad, const char *subcadena, size_t capacidad);
#endif
