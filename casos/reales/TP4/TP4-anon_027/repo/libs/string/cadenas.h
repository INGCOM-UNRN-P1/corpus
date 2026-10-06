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
 * @brief Calcula la longitud real de una cadena de caracteres sin exceder 
 * su capacidad máxima garantizando no leer memoria fuera de límites si 
 * faltase el terminador '\0'. Reserva exactamente en el heap la memoria 
 * necesaria (longitud + 1 byte para '\0') y copia el contenido.
 *
 * @param origen cadena de caracteres
 * @param capacidad_max capacidad de inspección de 'origen'.
 *
 * @pre se debe reservar exactamente en el heap la memoria 
 * necesaria (longitud + 1 byte para '\0').
 * 
 * @return Retorna el puntero char* a la memoria asignada en heap
 * ,o NULL si 'origen' es NULL, si 'capacidad_max' es 0 o si falla malloc.
 *
 * @post el resultado es la copia del contenido de 'origen' 
 * en el heap con su terminador "\0" incluido.
 *
 * @invariant 'origen'
*/
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);





 /** 
 * @brief Recibe dos cadenas de caracteres y sus respectivas
 * capacidades máximas de inspección.
 * Mide ambas cadenas de forma segura, reserva en el heap la cantidad 
 * exacta y construye la cadena concatenada.
 *
 * @param primera primer cadena de caracteres a concatenar
 * @param cap_primera capacidad de inspección de 'primera'
 * @param segunda segunda cadena de caracteres a concatenar.
 * @param cap_segunda capacidad de inspección de 'segunda'
 * 
 * @pre debe reservarse 1 byte para '\0' en la cadena concatenada.
 * 
 * @return el puntero char* al nuevo bloque en heap o NULL ante 
 * argumentos inválidos o fallo de memoria.
 *
 * @post El resultado de la nueva cadena concatenada es lo mismo que
 * decir: (longitud1 + longitud2 + 1 byte para '\0').
 *
 * @invariant '*primera' y '*segunda'
*/
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);





 /** 
 * @brief Recibe un doble puntero char **puntero_cadena. Libera con free
 * (*puntero_cadena) y asigna *puntero_cadena = NULL para
 * evitar punteros colgantes (dangling pointers).Si puntero_cadena es NULL 
 * o *puntero_cadena ya es NULL, no realiza ninguna 
 * acción.
 *
 * @param puntero_cadena doble puntero que apunta a un bloque de memoria 

 * @pre asignar obligatoriamente *puntero_cadena a NULL para evitar
 * dangling pointers. 
 * 
 * @return ---------------------------------------------------
 *
 * @post la función debe liberar memoria si 'puntero_cadena' !=NULL.
 *
 * @invariant ------------------------------------------------
*/
void cadena_liberar_segura(char **puntero_cadena);







 /** 
 * @brief Extraer una porción de 'origen' a partir del índice 
 * 'inicio', copiando a lo sumo 'cantidad' caracteres en un 
 * nuevo bloque de memoria dinámica en el heap.
 * 
 * @param origen cadena a copiar.
 * @param capacidad_max capacidad máxima de 'origen'.
 * @param inicio posición a copiar 'cantidad' caracteres en el 
 * nuevo bloque.
 * @param cantidad la cantidad de caracteres a copiar.
 * 
 * @pre La cadena resultante debe quedar siempre finalizada 
 * en '\0' ocupando exactamente el espacio necesario 
 * (longitud_extraida + 1).
 * 
 * @return una cadena vacía en heap ("") si 'inicio' supera 
 * la longitud de la cadena o NULL Si 'origen' es NULL o 
 * falla la memoria.
 *
 * @post el resultado debe ser la copia de 'origen' a partir
 * de 'inicio' en adelante en un nuevo bloque en el heap.
 *
 * @invariant 'origen'
*/
 char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, 
 size_t inicio, size_t cantidad);






 /** 
 * @brief Generar y retornar una nueva cadena en memoria dinámica 
 * que contenga los caracteres de 'origen' en orden invertido, 
 * finalizada en '\0'.
 *
 * @param origen cadena a copiar e invertir
 * @param capacidad_max define la capacidad máxima de 'origen'
 * 
 * @pre No debe modificar la cadena origen.
 * 
 * @return NULL si 'origen' es NULL o falla malloc. También puede 
 * retornar una nueva cadena en caso de éxito.
 *
 * @post el resultado debe retornar una cadena nueva con los caracteres
 * de 'origen' invertidos.
 *
 * @invariant 'origen'
*/
  char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);
  
#endif 
