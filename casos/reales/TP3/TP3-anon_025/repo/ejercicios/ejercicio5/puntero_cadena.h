#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia una cadena origen en un destino de forma segura
 * 
 * @param puntero_destino Puntero al buffer donde se guardara la copia.
 * @param capacidad_destinio Tamaño maximo del buffer destino.
 * @param puntero_origen Puntero a la cadena de solo lectura que se desea copiar.
 * 
 * @return true Si se copio completa.
 * @return false Si hubo truncamiento por falta de espacio.
 */
bool copiar_con_punteros(char *puntero_destino, size_t capacidad_destino, const char *puntero_origen);

/**
 * @brief Concatena una cadena origen al final de una cadena destino usando punteros.
 * 
 * @param puntero_destino Puntero al buffer destino que ya contiene la primera cadena
 * @param capacidad_destino Tamaño total del buffer destino.
 * @param puntero_origen Puntero a la cadena que se añadira al final.
 * 
 * @return ture Si se concateno completa sin perder caracteres.
 * @return false Si hubo truncamiento por falta de espacio.
 */
bool concatenar_con_punteros(char *puntero_destino, size_t capacidad_destino, const char *puntero_origen);

#endif 
