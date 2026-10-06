/**
 * @file cadenas.h
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
 * @brief Clona una cadena en el heap inspeccionando a lo sumo 'capacidad_max' caracteres.
 *
 * @param origen Cadena a clonar.
 * @param capacidad_max Máxima cantidad de caracteres de 'origen' que se pueden inspeccionar.
 *
 * @pre Si 'origen' no es NULL, debe ser legible hasta su '\0' o hasta 'capacidad_max' caracteres.
 * @post Si retorna un puntero no nulo, apunta a una copia terminada en '\0' que ocupa
 *       exactamente longitud + 1 bytes, y el llamador es responsable de liberarla.
 *
 * @return Puntero a la copia en heap, o NULL si 'origen' es NULL, 'capacidad_max' es 0
 *         o falla malloc.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);
 
/**
 * @brief Concatena dos cadenas en un nuevo bloque de heap de tamaño exacto.
 *
 * @param primera Primera cadena.
 * @param cap_primera Máxima cantidad de caracteres de 'primera' que se pueden inspeccionar.
 * @param segunda Segunda cadena.
 * @param cap_segunda Máxima cantidad de caracteres de 'segunda' que se pueden inspeccionar.
 *
 * @pre 'primera' y 'segunda' deben ser legibles hasta su '\0' o hasta su capacidad máxima.
 * @post Las cadenas de entrada no se modifican. El resultado es 'primera' seguida de
 *       'segunda', terminado en '\0', y el llamador es responsable de liberarlo.
 *
 * @return Puntero a la cadena concatenada en heap, o NULL si alguna cadena es NULL
 *         o falla malloc.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera, const char *segunda, size_t cap_segunda);
 
/**
 * @brief Libera una cadena dinámica y deja el puntero del llamador en NULL.
 *
 * @param puntero_cadena Dirección del puntero a la cadena a liberar.
 *
 * @pre Si '*puntero_cadena' no es NULL, debe apuntar a memoria dinámica vigente.
 * @post '*puntero_cadena' es NULL. Si 'puntero_cadena' o '*puntero_cadena' eran NULL,
 *       no se realiza ninguna acción.
 */
void cadena_liberar_segura(char **puntero_cadena);
 
/**
 * @brief Extrae una subcadena en un nuevo bloque de heap de tamaño exacto.
 *
 * @param origen Cadena de la que se extrae.
 * @param capacidad_max Máxima cantidad de caracteres de 'origen' que se pueden inspeccionar.
 * @param inicio Índice del primer carácter a copiar.
 * @param cantidad Máxima cantidad de caracteres a copiar.
 *
 * @pre Si 'origen' no es NULL, debe ser legible hasta su '\0' o hasta 'capacidad_max' caracteres.
 * @post 'origen' no se modifica. El resultado está terminado en '\0', ocupa exactamente
 *       caracteres_copiados + 1 bytes y el llamador es responsable de liberarlo.
 *
 * @return Puntero a la subcadena en heap (cadena vacía si 'inicio' alcanza o supera la
 *         longitud de 'origen'), o NULL si 'origen' es NULL o falla malloc.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad);
 
/**
 * @brief Genera en el heap una nueva cadena con los caracteres de 'origen' en orden inverso.
 *
 * @param origen Cadena a invertir.
 * @param capacidad_max Máxima cantidad de caracteres de 'origen' que se pueden inspeccionar.
 *
 * @pre Si 'origen' no es NULL, debe ser legible hasta su '\0' o hasta 'capacidad_max' caracteres.
 * @post 'origen' no se modifica. El resultado está terminado en '\0' y el llamador es
 *       responsable de liberarlo.
 *
 * @return Puntero a la cadena invertida en heap, o NULL si 'origen' es NULL o falla malloc.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
