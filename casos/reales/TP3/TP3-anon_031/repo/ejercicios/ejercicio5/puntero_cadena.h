#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia una cadena origen en destino usando aritmética de punteros.
 *
 * Copia caracteres desde origen hacia destino sin utilizar indexación.
 * Si la capacidad no alcanza, copia todo lo posible y garantiza terminación
 * nula siempre que capacidad sea mayor que cero.
 *
 * @param destino Puntero al buffer de destino.
 * @param capacidad Capacidad total del buffer destino, incluyendo el terminador.
 * @param origen Puntero a la cadena de origen.
 *
 * @return true si la cadena se copió completamente.
 * @return false si hubo truncamiento o si algún parámetro es inválido.
 *
 * @pre destino y origen deben ser punteros válidos cuando capacidad sea mayor que cero.
 *
 * @post Si capacidad > 0 y destino es válido, destino queda terminado en '\0'.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena una cadena origen al final de destino usando punteros.
 *
 * Busca el terminador nulo de destino dentro de la capacidad disponible y,
 * si lo encuentra, copia a continuación los caracteres de origen.
 *
 * @param destino Puntero al buffer que contiene la cadena inicial.
 * @param capacidad Capacidad total del buffer destino.
 * @param origen Puntero a la cadena que se desea concatenar.
 *
 * @return true si la concatenación fue completa.
 * @return false si hubo truncamiento, destino no estaba terminado dentro de
 * la capacidad o algún parámetro es inválido.
 *
 * @post Si capacidad > 0 y destino es válido, se conserva una terminación
 * nula dentro del rango seguro cuando es posible procesar el buffer.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Calcula la longitud de una cadena dentro de una capacidad máxima.
 *
 * Recorre la cadena mediante aritmética de punteros hasta encontrar '\0'
 * o alcanzar la capacidad indicada.
 *
 * @param cadena Puntero a la cadena.
 * @param capacidad Cantidad máxima de caracteres que se pueden inspeccionar.
 *
 * @return Longitud encontrada antes del terminador nulo.
 * @return capacidad si no se encontró '\0' dentro del rango.
 * @return 0 si cadena es NULL.
 */
size_t longitud_con_punteros(const char *cadena, size_t capacidad);

#endif 
