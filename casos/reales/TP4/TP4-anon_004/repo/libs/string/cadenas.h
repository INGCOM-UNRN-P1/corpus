/**
 * @file string.h
 * @brief Biblioteca libstring: manipulación y gestión de cadenas seguras en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica en heap debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - Sin uso de structs: operaciones sobre char* y dobles punteros char**.
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Clona una cadena de caracteres en el heap inspeccionando como maximo capacidad_max bytes.
 *
 * @pre origen apunta a una secuencia de caracteres legible de al menos capacidad_max bytes o es NULL si capacidad_max es 0.
 * @post Reserva memoria dinamica con malloc para (longitud + 1) caracteres, copia la cadena e incluye el '\0'. Retorna el puntero char* a la memoria asignada, o NULL si origen es NULL, capacidad_max es 0 o falla malloc.
 *
 * @param origen Cadena de texto original de solo lectura a duplicar.
 * @param capacidad_max Limite maximo de inspeccion de caracteres en origen para evitar lecturas fuera de rango.
 * @return char* Puntero al bloque reservado en heap con la copia de la cadena, o NULL en caso de error.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);



/**
 * @brief Concatena dos cadenas de texto calculando y reservando el espacio exacto en el heap.
 *
 * @pre primera y segunda son cadenas de texto validas inspeccionables hasta cap_primera y cap_segunda respectivamente.
 * @post Reserva memoria en heap con malloc para (longitud1 + longitud2 + 1) caracteres y copia ambas cadenas. Retorna el puntero char* a la nueva cadena unida, o NULL si alguna entrada es NULL o falla la asignacion.
 *
 * @param primera Primera cadena de texto de solo lectura.
 * @param cap_primera Capacidad maxima de inspeccion para la primera cadena.
 * @param segunda Segunda cadena de texto de solo lectura a anexar.
 * @param cap_segunda Capacidad maxima de inspeccion para la segunda cadena.
 * 
 * @return char* Puntero al bloque reservado en heap con la cadena concatenada, o NULL en caso de error.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);



/**
 * @brief Libera la memoria dinamica apuntada por un doble puntero a cadena y le asigna NULL.
 *
 * @pre puntero_cadena es un doble puntero char** valido o NULL.
 * @post Libera con free(*puntero_cadena) la memoria asignada en heap y asigna *puntero_cadena = NULL. Si puntero_cadena o *puntero_cadena son NULL, no realiza ninguna accion.
 *
 * @param puntero_cadena Puntero a la direccion del puntero de la cadena a liberar.
 */
void cadena_liberar_segura(char **puntero_cadena);



/**
 * @brief Extrae una porcion de texto a partir de un indice creando un nuevo bloque dinámico en heap.
 *
 * @pre origen apunta a una cadena valida inspeccionable hasta capacidad_max bytes.
 * @post Reserva la memoria exacta en heap para (longitud_extraida + 1) caracteres y copia la subcadena. Si inicio es mayor a la longitud de origen, retorna una cadena vacia en heap (""). Retorna NULL si origen es NULL, capacidad_max es 0 o falla malloc.
 *
 * @param origen Cadena original de solo lectura.
 * @param capacidad_max Capacidad maxima de inspeccion de la cadena origen.
 * @param inicio Indice inicial desde donde comenzar la extraccion.
 * @param cantidad Cantidad maxima de caracteres a extraer.
 * 
 * @return char* Puntero a la nueva subcadena en heap, o NULL ante error.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);



/**
 * @brief Genera una nueva cadena en el heap con los caracteres de la cadena original en orden inverso.
 *
 * @pre origen apunta a una cadena valida terminada en '\0' inspeccionable hasta capacidad_max bytes.
 * @post Reserva memoria exacta en heap con malloc y copia los caracteres en orden invertido finalizando en '\0'. Retorna el puntero char* a la cadena invertida, o NULL si origen es NULL, capacidad_max es 0 o falla malloc.
 *
 * @param origen Cadena de texto de solo lectura a invertir.
 * @param capacidad_max Capacidad maxima de inspeccion para la cadena origen.
 * 
 * @return char* Puntero a la nueva cadena invertida en heap, o NULL en caso de error.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
