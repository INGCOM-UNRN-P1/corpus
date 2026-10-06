#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief copia un arreglo origen en otro destino usando aritmética de punteros,
 * garantizando terminación nula con '\0' dentro del rango seguro.
 * @param destino es el puntero al inicio de la cadena destino.
 * @param capacidad es la cantidad de elementos de la cadena destino.
 * @param origen es el puntero al inicio de la cadena origen.
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * 
 * @post copia los 'capacidad' elementos antes del arreglo 'origen' antes del '\0'
 * en el arreglo destino.
 * 
 * @return true si se copiaron todos los elementos, false si hubo parámetros
 * inválidos o truncamientos.
 */
bool copiar_con_punteros (char *destino, size_t capacidad, const char *origen);

/**
 * @brief copia los caracteres de una cadena origen en una cadena destino a
 * partir de su último caracter.
 * @param destino es el puntero al inicio de la cadena destino.
 * @param capacidad es la cantidad de caracteres de destino.
 * @param origen es el puntero al inicio de la cadena origen.
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * 
 * @post concatena el contenido de 'origen' con el final de 'destino'.
 * 
 * @return true si se pudo concatenar la cadena completa. false caso contrario.
 */
bool concatenar_con_punteros (char *destino, size_t capacidad, const char *origen);
#endif 
