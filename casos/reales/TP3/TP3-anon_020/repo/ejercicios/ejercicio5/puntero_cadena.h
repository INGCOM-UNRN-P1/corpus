#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia una cadena en un buffer destino usando aritmética de punteros.
 *
 * @param destino Buffer de destino.
 * @param capacidad Tamaño total del buffer destino.
 * @param origen Cadena fuente que se desea copiar.
 *
 * @return true si la cadena completa quedó copiada dentro del buffer; false si
 *         se produjo truncamiento o si algún parámetro es inválido.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Agrega una cadena al final de otra cadena ya existente.
 *
 * @param destino Buffer de destino que ya contiene una cadena válida.
 * @param capacidad Tamaño total del buffer destino.
 * @param origen Cadena que se quiere concatenar.
 *
 * @return true si la concatenación no truncó datos; false si se truncó o si
 *         alguno de los parámetros es inválido.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
