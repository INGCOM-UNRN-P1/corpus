#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * =========================================================================
 * Ejercicio 5: Copia y Concatenación con Punteros (Complementario a libcadenas TP2)
 * =================================================================
 * Copia el contenido de la cadena origen en destino utilizando punteros.
 *
 * @param destino bufer de caracteres donde se escribirá la copia.
 * @param capacidad total asignado en memoria fisica al bufer destino.
 * @param origen es la cadena a copiar.
 * @pre La memoria reservada en destino debe ser de al menos 'capacidad'
 *      de caracteres.
 * @post El resultado en destino siempre va a estar finalizado en nulo si
 *       capacidad > 0.
 * @returns true si el contenido de origen se copia  completamente.
 *          Retorna false si el contenido fue truncado para no desbordar,
 *          o si destino u origen son nulos, o si capacidad == 0.
*/
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * Anexa el contenido de la cadena origen al final del texto contenido
 * en destino.
 *
 * @param destino bufer que alberga el texto base y recibira la adición.
 * @param capacidad total de memoria fisica del bufer destino.
 * @param origen es la cadena que se agrega al final.
 * @pre destino debe contener una cadena valida terminada en nulo dentro
 *      del rango de capacidad.
 * @post El resultado dentro de destino siempre finalizara en nulo si
 *       capacidad > 0 y la cadena previa era valida.
 * @returns true si la adicion se hizo de forma completa.
 *          Retorna false si la cadena resultante debia truncarse, o si
 *          algún parametro es nulo, o si destino no estaba finalizado
 *          en nulo dentro del limite de capacidad.
*/
bool concatenar_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
