#ifndef CONSOLA_H
#define CONSOLA_H

#include <stdbool.h>

/**
 * @brief Limpia el bufer de entrada estandar descartando caracteres hasta
 *        el salto de linea o EOF.
 */
void limpiar_buffer_entrada(void);

/**
 * @brief Lee un numero entero desde la entrada estandar mostrando un mensaje.
 *
 * @param mensaje Mensaje o prompt a mostrar al usuario.
 * @return int El numero entero ingresado por el usuario.
 */
int leer_entero(const char *mensaje);

/**
 * @brief Lee un numero entero dentro de un rango inclusivo [min, max].
 *
 * @param mensaje Mensaje o prompt a mostrar al usuario.
 * @param min Limite inferior admisible.
 * @param max Limite superior admisible.
 * @return int El numero entero dentro del rango ingresado.
 */
int leer_entero_entre(const char *mensaje, int min, int max);

/**
 * @brief Lee un numero de coma flotante desde la entrada estandar.
 *
 * @param mensaje Mensaje o prompt a mostrar al usuario.
 * @return float El numero flotante ingresado por el usuario.
 */
float leer_flotante(const char *mensaje);

/**
 * @brief Lee un numero flotante dentro de un rango inclusivo [min, max].
 *
 * @param mensaje Mensaje o prompt a mostrar al usuario.
 * @param min Limite inferior admisible.
 * @param max Limite superior admisible.
 * @return float El numero flotante dentro del rango ingresado.
 */
float leer_flotante_entre(const char *mensaje, float min, float max);

/**
 * @brief Lee un unico caracter desde la entrada estandar mostrando un mensaje.
 *
 * @param mensaje Mensaje o prompt a mostrar al usuario.
 * @return char El caracter ingresado por el usuario.
 */
char leer_caracter(const char *mensaje);

/**
 * @brief Lee un valor logico (booleano) desde la entrada estandar.
 *
 * @param mensaje Mensaje o prompt a mostrar al usuario.
 * @return bool Valor de verdad obtenido (true o false).
 */
bool leer_logico(const char *mensaje);

/**
 * @brief Determina si un valor entero se encuentra dentro de [min, max].
 *
 * @param valor Valor entero a verificar.
 * @param min Limite inferior del rango.
 * @param max Limite superior del rango.
 * @return bool true si min <= valor <= max, false en caso contrario.
 */
bool esta_en_rango_entero(int valor, int min, int max);

/**
 * @brief Determina si un valor flotante se encuentra dentro de [min, max].
 *
 * @param valor Valor flotante a verificar.
 * @param min Limite inferior del rango.
 * @param max Limite superior del rango.
 * @return bool true si min <= valor <= max, false en caso contrario.
 */
bool esta_en_rango_flotante(float valor, float min, float max);

#endif 
