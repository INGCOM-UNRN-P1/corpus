#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

/**
*@file puntero_cadena.h
*@brief cadenas seguras (longitud, copia y concatenacion) con aritmetica de punteros
*/

#include <stdbool.h>
#include <stddef.h>

/**
*@brief mide la longitud de una cadena examinando como maximo 'capacidad' de Bytes
*
* equivalente a cadena_longitud() del TP2, in indexacion []
*
*@pre cadena apunta a al menos 'capacidad' bytes legibles, o es NULL.
*@post la cadena no se modifica
*
*@param[in] cadena cadena a medir (solo lectura)
*@param[in] capacidad cantidad maxima de bytes a examinar
*
*@return cantidad de caracteres antes del '\0'; 'capacidad' si no se halla '\0' dentro del rango 0; 0 si cadena es NULL o capacidad es 0
*/
size_t longitud_con_punteros(const char *cadena, size_t capacidad);

/**
*@brief copia origen en destino sin escribir fuera de [0, capacidad -1]
*
*equivalente a cadena_copiar() del TP2, sin indexacion[]
*
*@pre destino apunta a al menos 'capacidad de bytes escribibles
*@pre origen es una cadena teminada en '\0'
*@pre destino y orifen no se superponen en memoria
*@post si capacidad > 0 y los punteros son validos: desino termina en '\0'
*@post si retorna false por parametros invalidos: destino no se modifica
*
*@param[out] destino bufer donde se copia el texto
*@param[in] capacidad tamaño total del bufer destino (inclye el '\0')
*@param[in] origen cadena fuente (solo lectura)
*
*@return true si origen se copio completo; false si hubo truncamiento o si destino u origen son NULL o capacidad es 0
*/
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
*@brief anexa origen al final del texto de destino respetando la capacidad
*
*equivalente a cadena_concatenar() del TP2, sin indexacion []
*
*@pre destino apunta a al menos 'capacidad' de bytes escribibles
*@pre origen es una cadena terminada en '\0'
*@pre destino y origen no se superponen en la memoria
*@post si capacidad > 0 y los punteros osn validos: destino termina en '\0'
*@post si retorna false por parametros invalidos: destino no se modifica
*
*@param[in, out] destino bufer con el texto preexistente
*@param[in] capacidad tamaño total del bufer destino (incluye el '\0')
*@param[in] origen cadena a anexar (solo lectura)
*
*@return true si origen se anexo completo; false si hubo truncamiento o si destino u origen son NULL o capacidad es 0
*/
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
