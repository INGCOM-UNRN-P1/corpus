#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula la longitud de una cadena respetando una capacidad maxima.
 *
 * @param cadena Puntero al primer caracter de la cadena.
 * @param capacidad Cantidad maxima de caracteres a recorrer.
 *
 * @pre cadena debe ser un puntero valido.
 * @post La cadena no es modificada.
 *
 * @return Cantidad de caracteres encontrados antes de '\0' o capacidad.
 * @return 0 si cadena es NULL.
 */
size_t longitud_con_punteros(const char *cadena, size_t capacidad);

/**
 * @brief Copia una cadena origen en una cadena destino.
 *
 * @param destino Puntero a la cadena destino.
 * @param capacidad Capacidad total disponible en destino.
 * @param origen Puntero a la cadena origen.
 *
 * @pre destino y origen no deben ser NULL.
 * @post destino queda terminado con '\0' si capacidad es mayor que cero.
 *
 * @return true si la cadena entro completamente.
 * @return false si hubo truncamiento o parametros invalidos.
 */
bool copiar_con_punteros(char *destino, size_t capacidad,
                         const char *origen);

/**
 * @brief Concatena una cadena origen al final de destino.
 *
 * @param destino Puntero a la cadena destino.
 * @param capacidad Capacidad total disponible en destino.
 * @param origen Puntero a la cadena que se desea agregar.
 *
 * @pre destino y origen no deben ser NULL.
 * @post destino queda terminado con '\0' si capacidad es mayor que cero.
 *
 * @return true si la cadena entro completamente.
 * @return false si hubo truncamiento o parametros invalidos.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad,
                             const char *origen);

#endif 