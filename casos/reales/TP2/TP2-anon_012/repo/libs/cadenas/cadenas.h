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
* @brief Toma una medida de la longitud útil de una cadena de caracteres de forma segura. 
* 
* @param cadena Cadena de caracteres a medir (lectura exclusivamente). 
* @param capacidad Límite máximo de bytes a examinar en memoria. 
* 
* @pre Si capacidad > 0, el puntero 'cadena' debe apuntar a un bloque de memoria válido. 
*
* @post El contenido de la cadena permanece inalterado. 
* 
* @return La cantidad de caracteres útiles antes del '\0', 'capacidad' si no se encuentra 
* el '\0' dentro del rango, o 0 si 'cadena' es NULL o 'capacidad' es 0. 
*/ 
size_t cadena_longitud(const char cadena[], size_t capacidad);


/** 
* @brief Copia la cadena origen en el búfer destino respetando su capacidad máxima. 
* 
* @param destino Búfer donde se almacenará la copia (salida). 
* @param capacidad Tamaño total en bytes del búfer destino. 
* @param origen Cadena a copiar (lectura exclusivamente). 
* 
* @pre Si capacidad > 0 y destino != NULL, 'destino' debe apuntar a un bloque de memoria válido. 
* @pre Si origen != NULL, debe ser una cadena válida terminada en '\0'. 
*
* @post 'destino' contendrá una cadena terminada en '\0' (si capacidad > 0 y destino != NULL). 
* 
* @return true si la cadena se copió completa sin truncar, 
* false si ocurrió truncamiento, si 'destino' u 'origen' son NULL o si 'capacidad' es 0. 
*/ 
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);


/** 
* @brief Concatena la cadena origen al final de la cadena destino respetando la capacidad del búfer. Busca el final del texto preexistente en 'destino' y anexa el contenido de 'origen'. 
* Garantiza que el resultado quede siempre finalizado en '\0' si capacidad > 0. 
* 
* @param destino Búfer que contiene la cadena inicial y donde se anexará el resultado . 
* @param capacidad Tamaño total en bytes del búfer destino. 
* @param origen Cadena a anexar al final de destino (lectura exclusivamente). 
* 
* @pre Si capacidad > 0 y destino != NULL, 'destino' debe ser una cadena válida terminada en '\0'. 
* @pre Si origen != NULL, 'origen' debe ser una cadena válida terminada en '\0'. 
*
* @post 'destino' contendrá la concatenación terminada en '\0' (si capacidad > 0 y destino != NULL). 
* 
* @return true si toda la cadena origen se concatenó sin truncamiento, 
* false si ocurrió truncamiento, si 'destino' u 'origen' son NULL o si 'capacidad' es 0. 
*/ 
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);


/** 
* @brief Convierte in-place a mayúsculas los caracteres minúsculas ASCII ('a'-'z'). Modifica la cadena directamente en memoria sin sobrepasar el límite y se detiene en el primer terminador '\0'.
* 
* @param cadena Cadena de caracteres a modificar (se modifica in-place). 
* @param capacidad Límite máximo de bytes a examinar en memoria. 
* 
* @pre Si capacidad > 0 y cadena != NULL, 'cadena' debe apuntar a un bloque de memoria válido. 
* @post Los caracteres en el rango 'a'-'z' quedan convertidos a mayúsculas en 'cadena'. 
* 
* @return La cantidad de caracteres efectivamente convertidos a mayúscula (size_t), 
* o 0 si 'cadena' es NULL o 'capacidad' es 0.
*/ 

size_t cadena_a_mayusculas(char cadena[], size_t capacidad);





#endif 
