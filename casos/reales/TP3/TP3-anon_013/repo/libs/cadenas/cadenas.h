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
 * @brief Contar y retornar la cantidad de caracteres útiles de la cadena antes del
 * terminador nulo '\0'
 * @param cadena[] es el puntero al inicio de la cadena.
 * @param capacidad es el numero de elementos de la cadena.
 * @return la cantidad de caracteres útiles, 0 si la cadena es nula o capacidad es 0.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);


/**
 * @brief Copia la cadena origen en el búfer destino de tamaño 'capacidad' bytes.
 * @param destino[] es el puntero donde comeinza la cadena destino.
 * @param capacidad es la cantidad de elementos en la cadena destino.
 * @param origen[] es el puntero al origen de la cadena de origen.
 * @return true si se pudo copiar la cadena completa, false caso contrario.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Anexa el contenido de origen al final del texto preexistente en destino.
 * @param destino[] es el puntero donde comeinza la cadena destino.
 * @param capacidad es la cantidad de elementos en la cadena destino.
 * @param origen[] es el puntero al origen de la cadena de origen.
 * @return true si se pudo concatenar la cadena completa, false caso contrario.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Convierte in-place a mayúsculas los caracteres minúsculas ASCII ('a'-'z')
 * presentes en la cadena.
 * @param cadena[] es el puntero al inicio de la cadena.
 * @param capacidad es el numero de elementos de la cadena.
 * @return la cantidad de caracteres convertidos, 0 en caso de cadena nula
 * o capacidad = 0;
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);


/**
 * @brief extrae una proción de una cadena origen a partir de una posición inicial.
 * @param destino[] es el puntero a la cadena destino.
 * @param capacidad es la cantidad de elementos en la cadena destino.
 * @param origen[] es el puntero a la cadena origen.
 * @param inicio es la posición de la cadena origen a partir de la cual se hace la extracción.
 * @param cantidad es la cantidad de elementos a extraer de la cadena origen.
 * @return true si la porción se extrajo de forma satisfactoria, false caso contrario.
 */
 bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);


/**
 * @brief Convierte un int con signo a cadena.
 * @param destino es el puntero al comienzo de la cadena destino.
 * @param capacidad es la cantidad de elementos de la cadena destino.
 * @param valor es el entero a convertir.
 * @return false si la capacidad es insuficiente, true en caso de que la
 * conversion haya tenido éxito.
 */
 bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 
