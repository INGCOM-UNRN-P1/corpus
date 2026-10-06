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
 * @brief Cuenta los caracteres utiles de la cadena antes del terminador nulo.
 *
 * @pre El puntero a cadena no debe ser nulo (NULL).
 * @post La cadena de origen no se modifica.
 * 
 * @param cadena Arreglo de caracteres de solo lectura.
 * @param capacidad Limite maximo de bytes a inspeccionar en memoria.
 * @return size_t Cantidad de caracteres. Retorna capacidad si no halla '\0', 
 *         o 0 si cadena es nula o capacidad es 0.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);

/**
 * @brief Copia una cadena origen en un bufer destino de forma segura.
 *
 * @pre Ningun puntero debe ser nulo (NULL).
 * @post El bufer destino queda modificado y con el terminador nulo garantizado.
 * 
 * @param destino Bufer de caracteres mutable.
 * @param capacidad Tamanio total fisico del bufer destino.
 * @param origen Cadena de caracteres a copiar.
 * @return bool true si se copio completa, false si hubo truncamiento o error.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Concatena una cadena origen al final de una cadena destino de forma segura.
 *
 * @pre Ningun puntero debe ser nulo (NULL).
 * @post El bufer destino contiene la concatenacion y garantiza el terminador nulo.
 * 
 * @param destino Bufer de caracteres mutable conteniendo el texto inicial.
 * @param capacidad Tamanio total fisico del bufer destino.
 * @param origen Cadena de caracteres a anexar al final.
 * @return bool true si se concateno completa sin truncamiento, false en caso contrario.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Convierte in-place los caracteres en minuscula a mayuscula de forma segura.
 *
 * @pre El puntero a cadena no debe ser nulo (NULL).
 * @post Los caracteres ASCII del bufer cambian a su equivalente en mayuscula.
 * 
 * @param cadena Bufer de caracteres mutable a procesar.
 * @param capacidad Capacidad maxima fisica del bufer.
 * @return size_t Cantidad de conversiones realizadas exitosamente.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);

/**
 * @brief Extrae una porcion de una cadena origen hacia un bufer destino seguro.
 *
 * @pre Ningun puntero debe ser nulo (NULL).
 * @post El bufer destino contiene la subcadena extraida con terminador nulo.
 * 
 * @param destino Bufer de caracteres mutable.
 * @param capacidad Tamanio total fisico del bufer destino.
 * @param origen Cadena de caracteres de la cual extraer texto.
 * @param inicio Indice en base cero desde donde comenzar la extraccion.
 * @param cantidad Maximo de caracteres a extraer del origen.
 * @return bool true si opero correctamente, false ante error de parametros.
 */
bool cadena_subcadena(char destino[], size_t capacidad, 
                      const char origen[], size_t inicio, size_t cantidad);

/**
 * @brief Convierte un numero entero a su representacion textual decimal.
 *
 * @pre El puntero destino no debe ser nulo (NULL).
 * @post El bufer destino contiene el texto del numero con terminador nulo.
 * 
 * @param destino Bufer de caracteres mutable.
 * @param capacidad Tamanio total fisico del bufer destino.
 * @param valor Numero entero a convertir.
 * @return bool true si cupo correctamente, false si hubo truncamiento o error.
 */
bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 