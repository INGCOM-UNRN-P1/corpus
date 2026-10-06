/**
 * @file puntero_cadena.h
 * @brief Funciones para copia y concatenacion segura de cadenas usando punteros.
 *
 * Ejercicio 5 - Trabajo Practico 3
 * Programacion 1 - Universidad Nacional de Rio Negro
 */

#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia una cadena fuente en un bufer destino de tamano acotado usando punteros.
 *
 * Desplaza los punteros de lectura y escritura asegurando que no se sobrepase `capacidad`.
 * Siempre garantiza la terminacion con caracter nulo ('\0') si capacidad > 0.
 *
 * @pre `destino` debe apuntar a un bloque de memoria de al menos `capacidad` bytes si capacidad > 0.
 * @pre `origen` debe ser una cadena valida terminada en '\0'.
 * @post Si capacidad > 0, `destino` contendra una cadena valida terminada en '\0'.
 *
 * @param[out] destino Puntero al bufer donde se almacenara la cadena copiada.
 * @param[in] capacidad Capacidad total en bytes del bufer de destino.
 * @param[in] origen Puntero a la cadena de solo lectura que se desea copiar.
 *
 * @return true si la cadena origen entro completa (con su terminador nulo),
 *         false si se produjo truncamiento o si los parametros son invalidos (punteros NULL o capacidad == 0).
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena una cadena fuente al final de una cadena destino usando punteros.
 *
 * Localiza el terminador nulo preexistente en destino y agrega los caracteres de origen,
 * garantizando que el total no exceda `capacidad` y colocando el terminador nulo final.
 *
 * @pre `destino` debe apuntar a una cadena valida terminada en '\0' dentro del espacio `capacidad`.
 * @pre `origen` debe ser una cadena valida terminada en '\0'.
 * @post Si capacidad > 0 y destino era valida, el resultado estara terminado en '\0'.
 *
 * @param[in, out] destino Puntero a la cadena que recibira los caracteres concatenados.
 * @param[in] capacidad Capacidad total en bytes del bufer de destino.
 * @param[in] origen Puntero a la cadena de solo lectura que se va a anexar.
 *
 * @return true si la cadena resultante entro completa sin truncar,
 *         false si hubo truncamiento o ante parametros invalidos.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
