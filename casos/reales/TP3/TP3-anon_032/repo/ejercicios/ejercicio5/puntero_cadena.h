#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * copiar_con_punteros: recibe char *destino, size_t capacidad, const char *origen.
 *    Copia origen en destino utilizando exclusivamente aritmética de punteros
 *    (desplazando punteros destino y origen con *dst++ = *src++).
 *    Garantiza terminación nula '\0' dentro del rango seguro [0, capacidad - 1].
 *    Retorna true si cupo completa, o false si hubo truncamiento o parámetros inválidos.
 */

/**
 * concatenar_con_punteros: recibe char *destino, size_t capacidad, const char *origen.
 *    Avanza un puntero auxiliar hasta el terminador '\0' de destino y a continuación
 *    copia los caracteres de origen con punteros, respetando la capacidad máxima.
 *    Garantiza terminador nulo si capacidad > 0. Retorna true si no truncó, false si truncó.
 */

/**
 * @brief Copia una cadena en otra de forma segura.
 *
 * @param destino La cadena donde se copiara origen.
 * @param capacidad La capacidad de destino.
 * @param origen La cadena que se copiara en destino.
 * @pre los punteros no deben ser nulos y capacidad debe ser mayor a cero. Capacidad
 * debe ser mayor o igual al largo de origen.
 * @post Se copiara origen en destino de forma segura y asegurando la existencia de un caracter
 * terminador al final de la cadena.
 * @return Se retornara true si la funcion se completo con exito o false si hubo
 * truncamiento,si alguno de los punteros es nulo o capacidad es cero.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena dos cadenas de forma segura.
 *
 * @param destino La cadena donde se concatenara origen.
 * @param capacidad La capacidad de destino.
 * @param origen La cadena que se copiara en destino.
 * @pre Los punteros no deben ser nulos y capacidad debe ser mayor o igual a la 
 * suma de destino y origen.
 * @post Se concatenaran las cadenas de forma segura respetando la capacidad de desitno
 * y asegurando el caracter terminador.
 * @return Retorna true si la operacion se completo con exito o false si
 * destino o origen son nulos, capacidad es cero o hubo truncamiento.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Calcula el largo de una cadena de forma segura.
 * @param cadena La cadena a calcular.  
 * @param capacidad La capacidad de cadena.
 * @pre Cadena no debe ser un arreglo nulo y capacidad debe ser mayor a 0;
 * @post Se devolvera un size_t que representa el largo de la cadena.
 * @returns El largo de la cadena, 0 si los parametros con invalidos.
 */
size_t longitud_con_punteros(const char *s, size_t capacidad);
#endif 
