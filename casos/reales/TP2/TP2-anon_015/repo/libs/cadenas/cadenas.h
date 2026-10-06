/**
 * @file cadenas.h
 * @brief Biblioteca de manipulación de cadenas seguras (Safe Strings) en C11.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - RECIBE LA CAPACIDAD: Parámetro 'size_t capacidad' con el tamaño total
 *   del búfer destino en memoria física (incluyendo terminador).
 * - GARANTÍA DE TERMINADOR: Si capacidad > 0, el búfer destino siempre
 *   finaliza con el carácter nulo '\0'.
 * - CONTROL DE LÍMITES: Nunca se escribe fuera de [0, capacidad - 1].
 */

#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Cuenta la cantidad de caracteres de una cadena
 * @param cadena Cadena del usuario a medir
 * @param capacidad Límite predefinido del espacio en memoria de la cadena
 * @pre La cadena no puede ser nula ni su capacidad puede ser 0
 * @post Si la cadena es nula o su capacidad es 0 devuelve 0
 * @return Cantidad de caracteres de la cadena antes del terminador nulo
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);


/**
 * @brief Copia una cadena en una de destino con una capacidad predefinida
 * @param origen Cadena a copiar en otra
 * @param destino Cadena con una capacidad predefinida que debe recibir otra
 * @param capacidad Espacio de la cadena de destino predefinido
 * @pre La cadena origen no puede ser más grande que destino ni puede ser nula
 * @post Devuelve false si origen > destino y 0 si origen es nulo
 * @return Devuelve true si no hay problemas a la hora de copiar ca
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Se unen dos cadenas evitando desbordamientos de buffer 
 * @param origen Cadena inicial a copiar al final de destino
 * @param destino Cadena en la que se copia otra evitando desbordamientos
 * @param capacidad Espacio en memoria predestinado a la cadena de destino
 * @pre Ninguna de las cadenas puede ser nulas ni la cantidad 0
 * @post Si hay cadenas nulas o cantidad 0 se devuelve false
 * @return Concatena las dos cadenas y devuelve true si no hubo truncamientos
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Se cambian las minusculas por mayusculas en una cadena 
 * @param origen Cadena de base a operar
 * @param capacidad Espacio en memoria destinado a la cadena
 * @pre La cadena no puede ser nula ni su capacidad 0
 * @post Si hay cadenas nulas o cantidad 0 se devuelve 0
 * @return Devuelve la cantidad de caracteres de la cadena convertidos
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);



/**
 * @brief Se copia un rango desde un punto hasta el fin de una cadena en otra
 * @param destino Cadena en la que debe terminar el resultado de la operación
 * @param capacidad Espacio en memoria restringido a la cadena final
 * @param origen Cadena desde la que se copia el rango de caracteres
 * @param inicio Límite inferior del rango a copiar
 * @param cantidad Límite superior del rango a copiar
 * @pre Capacidad debe ser mayor a 0, inicio debe ser menor a origen
 * @post En caso que capacidad sea < 0 o inicio > origen devuelve false
 * @return True si la operación se dió con existo
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);



#endif 
