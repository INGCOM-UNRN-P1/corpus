/**
 * @file puntero_cadena.h
 * @brief Prototipos para copia y concatenación segura de cadenas mediante punteros.
 */

#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia una cadena en otra utilizando aritmética de punteros.
 * 
 * @pre Los punteros 'destino' y 'origen' no deben ser nulos. La capacidad debe ser mayor a 0.
 * @post Copia la cadena 'origen' en 'destino' garantizando el terminador nulo '\0'.
 * 
 * @param destino Puntero al buffer donde se guardará la cadena.
 * @param capacidad Tamaño máximo del buffer (incluyendo '\0').
 * @param origen Puntero a la cadena a copiar.
 * @return true si la copia se realizó completa sin truncar, false en caso contrario o error.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena una cadena al final de otra utilizando aritmética de punteros.
 * 
 * @pre Los punteros 'destino' y 'origen' no deben ser nulos. La capacidad debe ser mayor a 0.
 * @post Añade la cadena 'origen' al final de 'destino', asegurando el terminador nulo '\0'.
 * 
 * @param destino Puntero al buffer que contiene la cadena base.
 * @param capacidad Tamaño máximo total del buffer de destino (incluyendo '\0').
 * @param origen Puntero a la cadena que se va a concatenar.
 * @return true si la concatenación se realizó completa sin truncar, false en caso contrario o error.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 