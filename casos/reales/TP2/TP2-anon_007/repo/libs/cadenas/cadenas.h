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
#include <ctype.h>


/**
 * @brief Realiza un conteo de todos los caracteres en una cadena, hasta capacidad o hasta encontrar el caracter '\0'.
 *          La cadena no debe ser NULL y la cantidad de caracteres debe ser mayor a 0.
 * @param cadena[char] direccion a una cadena de caracteres.
 * @param capacidad[size_t] limite de caracteres que puede tener una cadena.
 * @return Largo total de la cadena.
 */

size_t cadena_longitud(const char cadena[], size_t capacidad);


/**
 * @brief Realiza una copia de una cadena de caracteres a otra verificando su seguridad, y forzando
 *      el caracter terminador al final de la cadena destino.
 *          La cadena no debe ser NULL y la cantidad de caracteres debe ser mayor a 0.
 * @param origen[char] de la cadena de caracteres a copiar.
 * @param destino[char][in] cadena de caracteres vacio.
 * @param capacidad[size_t] limite de caracteres que puede tener una cadena.
 * @return false si la cadena copiada no copia completamente o si los parametros son invalidos
 *          true si la cadena se copio completamente con caracter '\0' incluido.
 *          destino[char][out] cadena copiada o parcialmente copiada.
 */
 bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Realiza una concatenacion de una cadena de caracteres con otra 
 *          empezando donde termina la segunda, y forzando
 *          el caracter terminador al final de la cadena destino.
 *          Las cadenas no deben ser NULL y la cantidad de caracteres debe ser mayor a 0.
 * @param origen[char] de la cadena de caracteres a concatenar.
 * @param destino[char][in] cadena de caracteres destino.
 * @param capacidad[size_t] limite de caracteres que puede tener una cadena.
 * @return false si la suma de los largos de ambas cadenas es menor a la capacidad total del destino
 *          true si la cadena se copio completamente con caracter '\0' incluido.
 *          destino[char][out] cadenas concatenadas con caracter terminador incluido.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Realiza la transformacion de todos los caracteres de una cadena
 *          que no sean caracteres minusculos, a mayusculos.
 * @param cadena[char][in] cadena de caracteres.
 * @param capacidad[size_t] limite de caracteres que puede tener una cadena.
 * @return conteo de cantidad de caracteres transformados a mayusculo
 *          o 0 si no hay caracteres a trasformar o si los parametros son invalidos.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);


/**
 * @brief Realiza una copia de una cadena de caracteres a otra, a partir de un punto
 *          en la cadena origen hasta cantidad o hasta capacidad.
 *          Las cadenas no deben ser NULL y la cantidad de caracteres debe ser mayor a 0.
 * @param origen[char] de la cadena de caracteres a concatenar.
 * @param destino[char][in] cadena de caracteres destino.
 * @param capacidad[size_t] limite de caracteres que puede tener una cadena.
 * @param inicio[size_t] de la cadena a copiar.
 * @param cantidad[size_t] maxima de caracteres que se pueden copiar.
 * @return false si: Los parametros son invalidos.
 *                   El parametro inicio es mayor al largo total del origen.
 *                   
 *          true si la cadena se copio completamente con caracter '\0' incluido.
 *          destino[char][out] cadena copiada del origen desde inicio hasta cantidad o capacidad.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);



#endif 
