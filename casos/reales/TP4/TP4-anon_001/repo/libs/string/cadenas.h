/**
 * @file string.h
 * @brief Biblioteca libstring: manipulación y gestión de cadenas seguras en
 * heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica en heap debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - Sin uso de structs: operaciones sobre char *y dobles punteros char**.
 */

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Duplica una cadena de caracteres en el heap garantizando un límite de
 * inspección.
 *
 * Calcula la longitud de la cadena 'origen' sin inspeccionar más allá de
 * 'capacidad_max' bytes para evitar accesos fuera de límites si falta el
 * caracter terminador '\0'.Reserva memoria dinámica en el heap para alojar los
 * caracteres leídos más el byte nulo de finalización ('\0') y copia el
 * contenido.
 *
 * @param origen Puntero a la cadena de caracteres constante que se desea
 * duplicar
 * @param capacidad_max de caracteres a inspeccionar en la cadena origen.
 *
 * @return char *Puntero a la nueva cadena duplicada en el heap (debe ser
 * liberada con free), o NULL si 'origen' es NULL, si 'capacidad_max' es 0, o si
 * falla 'malloc'.
 */

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);



/**
* @brief Une dos cadenas de caracteres reservando la memoria exacta en el heap.
*
* Mide la longitud real de 'primera' y 'segunda' respetando sus respectivas
capacidades
* maximas de inspeccion.Asigna un bloque dinámico contiguo con el espacio justo
para
* albergar ambas cadenas y el terminador nulo ('\0'). Reutiliza las funciones de
    'cadenas_tp2.h' (cadena_copiar y cadena_concatenar) para realizar el copiado
y ensamblado final del bloque de memoria.

* @param primera Puntero a la primera cadena a concatenar.
* @param cap_primera Capacidad maxima de inspeccion de la primera cadena.
* @param segunda Puntero a la segunda cadena a concatenar.
* @param cap_segunda Capacidad maxima de inspeccion de la segunda cadena.
*
* @return char *Puntero al nuevo bloque de memoria en el heap con la cadena
resultante
*               (debe ser liberado posteriormente por el usuario con free), o
NULL si
*               los punteros son invalidos, si alguna capacidad es 0 o si falla
'malloc'.
*/

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);



/**
 * @brief Libera la memoria asignada dinámicamente a una cadena y anula su
 * puntero.
 *
 * Libera el bloque de memoria en el heap mediante 'free' y asigna NULL al
 * puntero referenciado ('*puntero_cadena') para prevenir punteros colgantes
 * (dangling pointers).
 *
 * @note Si 'puntero_cadena' es NULL o '*puntero_cadena' es NULL, la función no
 * realiza ninguna operación y finaliza de manera segura.
 *
 * @param puntero_cadena Dirección del puntero (doble puntero) que apunta a la
 * memoria a liberar en el heap.
 */

void cadena_liberar_segura(char **puntero_cadena);



/**
 * @brief Extrae una subcadena en memoria dinámica a partir de un índice
 * inicial.
 *
 * Asigna un nuevo bloque de memoria en el heap y copia a lo sumo 'cantidad'
 * caracteres de la cadena 'origen', comenzando desde la posición 'inicio'.La
 * cadena resultante queda siempre finalizada con '\0' y ocupa únicamente el
 * espacio exacto necesario (longitud_extraida + 1 bytes).
 *
 * @note Si 'inicio' supera o iguala la longitud real de la cadena (o
 * 'capacidad_max'), la función retorna una cadena vacía asignada en el heap
 * ("").
 *
 * @param origen Cadena fuente de la cual se extraerá la subcadena.
 * @param capacidad_max de seguridad para inspeccionar la memoria de 'origen'.
 * @param inicio Índice base a partir del cual se iniciará la copia.
 * @param cantidad de caracteres que se intentará extraer.
 *
 * @return Puntero al nuevo bloque de memoria en el heap con la subcadena,
 *         puntero a una cadena vacía en el heap si 'inicio' está fuera de
 * rango, o NULL si 'origen' es NULL o si falla la reserva de memoria.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);



/**
 * @brief Genera y retorna una nueva cadena en memoria dinámica con los
 * caracteres de 'origen' en orden invertido.
 *
 * Asigna un nuevo bloque de memoria en el heap de tamaño exacto (longitud + 1
 * bytes) y copia los caracteres de la cadena 'origen' en sentido inverso.La
 * cadena resultante queda siempre finalizada con el caracter nulo '\0'.No
 * modifica la cadena 'origen'.
 *
 * @param origen Cadena fuente cuyos caracteres se van a invertir.
 * @param capacidad_max Límite máximo de seguridad para inspeccionar la memoria
 * de 'origen'.
 *
 * @return Puntero al nuevo bloque de memoria en el heap con la cadena
 * invertida, o NULL si 'origen' es NULL o si falla la reserva de memoria.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
