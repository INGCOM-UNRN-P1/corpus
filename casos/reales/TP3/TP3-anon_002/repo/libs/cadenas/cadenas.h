/**
 * @file cadenas.h
 * @brief Biblioteca de manipulación de cadenas seguras (Safe Strings) en C11.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 * sin abreviaturas y con un máximo de 12 caracteres.
 * RECIBE LA CAPACIDAD: Parámetro 'size_t capacidad' con el tamaño total
 * del búfer destino en memoria física (incluyendo terminador).
 * GARANTÍA DE TERMINADOR: Si capacidad > 0, el búfer destino siempre
 * finaliza con el carácter nulo '\0'.
 * CONTROL DE LÍMITES: Nunca se escribe fuera de [0, capacidad - 1].
 */

#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>

/** =========================================================================
 * Ejercicio 1: Medición Segura de Longitud
 * =========================================================================
 * @brief Mide la longitud de una cadena respetando la capacidad.
 * @param cadena Cadena de caracteres de solo lectura.
 * @param capacidad Tamaño máximo del buffer.
 * @return size_t Cantidad de caracteres útiles (sin '\0').
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);

/** =========================================================================
 * Ejercicio 2: Copia Segura con Control de Búfer
 * =========================================================================
 * @brief Copia el contenido de origen en destino garantizando el cierre con '\0'.
 * @param destino Buffer mutable donde se copiará la cadena.
 * @param capacidad Capacidad total del buffer de destino.
 * @param origen Cadena fuente de solo lectura.
 *
 * @pre 'destino' y 'origen' no deben ser NULL, 'capacidad' > 0.
 * @post 'destino' queda terminado con '\0' si la copia es exitosa.
 *
 * @return bool 'true' si la cadena cupo completa;
 *              'false' si hubo desbordamiento o error.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);

/** =========================================================================
 * Ejercicio 3: Concatenación Segura con Control de Búfer
 * =========================================================================
 * @brief Anexa el contenido de origen al final de destino sin rebasar la capacidad.
 * @param destino Buffer que contiene la cadena inicial y recibirá el anexo.
 * @param capacidad Capacidad total del buffer de destino.
 * @param origen Cadena a anexar de solo lectura.
 *
 * @pre 'destino' y 'origen' no deben ser NULL, 'capacidad' > 0.
 * @post 'destino' conserva el resultado concatenado finalizado con '\0'.
 *
 * @return bool 'true' si se concatenó completa; 'false' si faltó espacio o hubo error.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/** =========================================================================
 * Ejercicio 4: Normalización a Mayúsculas Segura
 * =========================================================================
 * @brief Convierte todas las letras minúsculas de una cadena a mayúsculas.
 *
 * @param cadena Cadena mutable de caracteres a modificar in-place.
 * @param capacidad Capacidad máxima del buffer de la cadena.
 *
 * @pre Si 'capacidad' &gt; 0, 'cadena' no debe ser NULL.
 * @post Las letras entre 'a' y 'z' se transforman a su equivalente en mayúscula.
 *
 * @return size_t Cantidad de caracteres efectivamente modificados.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);

/** =========================================================================
 * Ejercicio 5: Extracción de Subcadena Segura (Sin prototipo previo)
 * =========================================================================
 * @brief Extrae una porción de una cadena origen a partir de una posición inicial.
 * Copia a lo sumo 'cantidad' caracteres en 'destino' garantizando el remate con '\0'.
 * Si 'inicio' supera la longitud de 'origen', 'destino' queda como cadena vacía ("").
 *
 * @param destino Buffer seguro donde se guardará la subcadena extraída.
 * @param capacidad Capacidad total máxima del buffer de destino.
 * @param origen Cadena fuente de solo lectura.
 * @param inicio Índice base cero a partir del cual se extrae.
 * @param cantidad Cantidad máxima de caracteres a extraer.
 *
 * @pre 'destino' y 'origen' no deben ser NULL, 'capacidad' > 0.
 * @post 'destino' queda finalizada con '\0'.
 *
 * @return bool 'true' si la operación fue exitosa; 'false' si los parámetros son inválidos.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);



#endif 
