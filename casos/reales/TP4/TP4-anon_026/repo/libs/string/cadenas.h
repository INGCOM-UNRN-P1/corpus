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
 * @brief Duplica una cadena en el heap inspeccionando a lo sumo @p capacidad_max caracteres.
 * Mide @p origen sin leer más allá de @p capacidad_max bytes (seguro aunque falte el terminador '\0'), reserva exactamente longitud + 1 bytes y copia el contenido.
 * La copia siempre queda terminada en '\0'.
 * @param origen Cadena a duplicar. No se modifica.
 * @param capacidad_max Cantidad máxima de caracteres a inspeccionar en @p origen.
 * @return Puntero a la copia en heap, o NULL si @p origen es NULL, @p capacidad_max es 0 o falla malloc.
 * @post La longitud de la copia es el menor entre la longitud real de @p origen y
 * @p capacidad_max.
 * @note El llamador es responsable de liberar el resultado con cadena_liberar_segura().
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);


/**
 * @brief Concatena dos cadenas en un nuevo bloque del heap de tamaño exacto.
 *
 * Mide cada cadena sin exceder su capacidad de inspección, reserva
 * longitud1 + longitud2 + 1 bytes y construye la cadena unida, terminada en '\0'.
 * Las cadenas de entrada no se modifican.
 * @param primera Primera cadena.
 * @param cap_primera Cantidad máxima de caracteres a inspeccionar en @p primera.
 * @param segunda Segunda cadena.
 * @param cap_segunda Cantidad máxima de caracteres a inspeccionar en @p segunda.
 * @return Puntero a la cadena unida en heap, o NULL si algún puntero es NULL, alguna capacidad es 0, la longitud total desborda size_t o falla malloc.
 * @note El llamador es responsable de liberar el resultado con cadena_liberar_segura().
 */

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);


 /**
 * @brief Libera una cadena del heap y deja el puntero del llamador en NULL.
 *
 * @param puntero_cadena Dirección del puntero a la cadena a liberar. Si es NULL,
 *        o si @c *puntero_cadena ya es NULL, no se realiza ninguna acción.
 *
 * @post Si se liberó memoria, @c *puntero_cadena vale NULL (sin puntero colgante).
 */

void cadena_liberar_segura(char **puntero_cadena);


/**
 * @brief Extrae una subcadena de @p origen en un nuevo bloque del heap de tamaño exacto.
 *
 * Copia a lo sumo @p cantidad caracteres de @p origen a partir del índice @p inicio.
 * La longitud de @p origen se mide sin exceder @p capacidad_max. El resultado
 * ocupa exactamente longitud_extraida + 1 bytes y siempre termina en '\0'.
 *
 * @param origen Cadena de la que se extrae la porción. No se modifica.
 * @param capacidad_max Cantidad máxima de caracteres a inspeccionar en @p origen.
 * @param inicio Índice del primer carácter a extraer.
 * @param cantidad Cantidad máxima de caracteres a extraer.
 * @return Puntero a la subcadena en heap, o NULL si @p origen es NULL o falla malloc.
 *         Si @p inicio supera la longitud (o @p cantidad es 0) retorna una cadena
 *         vacía ("") en heap, no NULL.
 *
 * @note El llamador es responsable de liberar el resultado con cadena_liberar_segura().
 */

 char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad);


 /**
 * @brief Genera en el heap una nueva cadena con los caracteres de @p origen invertidos.
 *
 * La longitud de @p origen se mide sin exceder @p capacidad_max. La cadena origen
 * no se modifica y el resultado siempre termina en '\0'.
 *
 * @param origen Cadena a invertir.
 * @param capacidad_max Cantidad máxima de caracteres a inspeccionar en @p origen.
 * @return Puntero a la cadena invertida en heap, o NULL si @p origen es NULL o falla
 *         malloc. Si la longitud medida es 0 retorna una cadena vacía ("") en heap.
 *
 * @note El llamador es responsable de liberar el resultado con cadena_liberar_segura().
 */
 char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
