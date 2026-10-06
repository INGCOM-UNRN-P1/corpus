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
 * Recibe una cadena de caracteres 'origen' y una 'capacidad_max' de inspección.
 * Calcula su longitud real sin exceder 'capacidad_max' (garantizando no leer
 * memoria fuera de límites si faltase el terminador '\0').
 * Reserva exactamente en el heap la memoria necesaria (longitud + 1 byte para '\0')
 * y copia el contenido.
 * Retorna el puntero char* a la memoria asignada en heap, o NULL si origen es
 * NULL, capacidad_max es 0 o falla malloc.
 **/
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);

/**
 * Recibe dos cadenas de caracteres ('primera' y 'segunda') y sus respectivas
 * capacidades máximas de inspección ('cap_primera' y 'cap_segunda').
 * Mide ambas cadenas de forma segura, reserva en el heap la cantidad exacta
 * (longitud1 + longitud2 + 1 byte para '\0') y construye la cadena concatenada.
 * Retorna el puntero char* al nuevo bloque en heap, o NULL ante argumentos
 * inválidos o fallo de memoria.
 **/
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);

/**
 * Recibe un doble puntero char **puntero_cadena.
 * Libera con free(*puntero_cadena) y asigna *puntero_cadena = NULL para
 * evitar punteros colgantes (dangling pointers).
 * Si puntero_cadena es NULL o *puntero_cadena ya es NULL, no realiza ninguna acción.
 **/
void cadena_liberar_segura(char **puntero_cadena);

/**
 * Extraer una porción de 'origen' a partir del índice 'inicio', copiando a lo
 * sumo 'cantidad' caracteres en un nuevo bloque de memoria dinámica en el heap.
 * La cadena resultante debe quedar siempre finalizada en '\0' ocupando exactamente
 * el espacio necesario (longitud_extraida + 1).
 * Si 'inicio' supera la longitud de la cadena, retorna una cadena vacía en heap ("").
 * Si 'origen' es NULL o falla la memoria, retorna NULL.
 *
 * Tarea del estudiante:
 * 1. Diseñar y declarar el prototipo formal en este archivo cabecera.
 * 2. Redactar la documentación formal Doxygen.
 * 3. Implementar la función en string.c y sus pruebas en prueba.c.
 **/
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_origen, size_t inicio, size_t cantidad);

/**
 * Generar y retornar una nueva cadena en memoria dinámica que contenga los
 * caracteres de 'origen' en orden invertido, finalizada en '\0'.
 * No debe modificar la cadena origen.
 * Si 'origen' es NULL o falla malloc, retorna NULL.
 *
 * Tarea del estudiante:
 * 1. Diseñar y declarar el prototipo formal en este archivo cabecera.
 * 2. Redactar la documentación formal Doxygen.
 * 3. Implementar la función en string.c y sus pruebas en prueba.c.
 **/
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);


#endif 
