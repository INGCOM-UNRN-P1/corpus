#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * Copia una cadena de caracteres de origen a destino de forma segura.
 * 
 * Emplea exclusivamente aritmética de punteros para desplazar origen y destino.
 * Garantiza la terminación nula ('\0') dentro del rango seguro [0, capacidad - 1].
 * 
 * @param dest Puntero al arreglo de destino donde se copiará la cadena.
 * @param cap Capacidad máxima en bytes del arreglo de destino.
 * @param src Puntero a la cadena de origen (solo lectura).
 * 
 * @return true Si la cadena cupo por completo (sin truncamiento), 
 *         false Si hubo truncamiento, capacidad insuficiente o punteros nulos.
 */
bool copiar_con_punteros(char *dest, size_t cap, const char *src);

/**
 *  Concatena una cadena de origen al final de una cadena de destino de forma segura.
 * 
 * Avanza un puntero auxiliar hasta el terminador '\0' del destino y a continuación
 * copia los caracteres del origen empleando punteros, respetando la capacidad máxima.
 * Garantiza terminador nulo si capacidad > 0.
 * 
 * @param dest Puntero al arreglo de destino que contiene la cadena inicial.
 * @param cap Capacidad total máxima del arreglo de destino.
 * @param src Puntero a la cadena que se desea concatenar (solo lectura).
 * 
 * @return true Si se concatenó por completo sin truncar, 
 *         false Si hubo truncamiento, capacidad excedida o punteros nulos.
 */
bool concatenar_con_punteros(char *dest, size_t cap, const char *src);

/**
 * Calcula la longitud de una cadena de forma segura utilizando punteros.
 * 
 * Recorre la cadena mediante aritmética de punteros hasta encontrar el terminador '\0'
 * o hasta alcanzar el límite de capacidad especificado.
 * 
 * @param s Puntero a la cadena de caracteres (solo lectura).
 * @param cap Capacidad máxima o límite de revisión.
 * 
 * @return size_t El número de caracteres de la cadena (excluyendo el '\0'), 
 *                o 0 si el puntero es NULL.
 */
size_t longitud_con_punteros(const char *s, size_t cap);

#endif 
