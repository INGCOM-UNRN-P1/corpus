/**
 * @file cadenas.h
 * @brief Biblioteca de manipulación de cadenas seguras (Safe Strings) en C11.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - RECIBE LA CAPACIDAD: Parámetro 'size_t capacidad' con el tamaño total
 *   del búfer destino en memoria física (incluyendo terminador).
 * - GARANTÍA DE TERMINADOR: Si capacidad > 0, el búfer destino siempre
 *   finaliza con el carácter nulo '\0'.
 * - CONTROL DE LÍMITES: Nunca se escribe fuera de [0, capacidad - 1].
 */

#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * @brief Mide la longitud de una cadena de texto de forma segura.
 *
 * Cuenta los caracteres útiles antes del terminador nulo '\0', examinando
 * como máximo la capacidad especificada para evitar lecturas fuera de límites.
 *
 * @param cadena de caracteres a evaluar.
 * @param capacidad máxima de bytes a examinar en memoria.
 * 
 * @pre Si `cadena` no es NULL y `capacidad > 0`, debe apuntar a un bloque
 *      de memoria válido de al menos `capacidad` bytes accesibles para lectura.
 * @post La cadena examinada permanece inalterada (`const`).
 * 
 * @return size_t Cantidad de caracteres útiles antes del '\0', o `capacidad`
 *                si no se encuentra el terminador nulo dentro del rango.
 *                Retorna 0 si `cadena` es NULL o si `capacidad` es 0.
 */

size_t cadena_longitud(const char cadena[], size_t capacidad);



 /**
 * @brief Copia de forma segura una cadena de texto en un búfer de destino.
 *
 * Copia el contenido de `origen` hacia `destino` respetando la capacidad máxima.
 * Garantiza que la cadena resultante en `destino` siempre finalice en '\0'
 * (si capacidad > 0) y evita desbordamientos de búfer.
 *
 * @param destino Búfer donde se copiará la cadena.
 * @param capacidad total en bytes para el búfer de destino.
 * @param origen Cadena de caracteres a copiar.
 * 
 * @pre Si `destino` no es NULL y `capacidad > 0`, debe apuntar a un bloque
 *      de memoria válido con espacio para escritura de al menos `capacidad` bytes.
 * @pre Si `origen` no es NULL, debe ser una cadena válida finalizada en '\0'.
 * @post `destino` queda finalizado en '\0' si `capacidad > 0`.
 * @post `origen` permanece inalterado (`const`)
 * 
 * @return true Si toda la cadena de origen (incluido su '\0') cupo dentro de destino
 *              sin sufrir truncamiento.
 *         false Si se produjo truncamiento por falta de espacio, o si alguno de los
 *               punteros es NULL, o si `capacidad` es 0.
 */

bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);



 /**
 * @brief Anexa una cadena al final de otra de forma segura.
 *
 * Concatena el contenido de `origen` al final del texto preexistente en `destino`,
 * respetando estrictamente la capacidad máxima del búfer para evitar desbordamientos.
 * Garantiza que la cadena resultante quede siempre finalizada en '\0' (si capacidad > 0).
 *
 * @param destino Búfer con el texto preexistente donde se anexará el origen.
 * @param capacidad Tamaño total asignado en bytes para el búfer de destino.
 * @param origen Cadena de caracteres a anexar.
 * 
 * @pre Si `destino` no es NULL y `capacidad > 0`, debe apuntar a un bloque de memoria
 *      válido que contenga una cadena válida finalizada en '\0' dentro del rango.
 * @pre Si `origen` no es NULL, debe ser una cadena válida finalizada en '\0'.
 * @post `destino` conserva su texto previo seguido por el contenido de `origen`
 *        (o hasta donde permita la capacidad) y finaliza en '\0'
 * @post `origen` permanece inalterado (`const`).
 * 
 * @return true Si toda la cadena de origen se concatenó sin truncamiento.
 *         false Si se produjo truncamiento por falta de espacio en destino, si no
 *               se encontró el '\0' inicial en destino, o si los parámetros son inválidos.
 */

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);



 /**
 * @brief Convierte en mayúsculas los caracteres minúsculas ASCII de una cadena.
 *
 * Modifica la cadena in-place transformando los caracteres en el rango ['a', 'z']
 * en sus equivalentes mayúsculas ('A' a 'Z'), respetando el límite de capacidad
 * y deteniéndose en el primer terminador nulo '\0'.
 *
 * @param cadena Cadena de caracteres a modificar in-place.
 * @param capacidad Límite máximo de bytes a examinar en memoria.
 * 
 * @pre Si `cadena` no es NULL y `capacidad > 0`, debe apuntar a un bloque
 *      de memoria válido con espacio de lectura y escritura de al menos `capacidad` bytes.
 * @post Los caracteres en el rango ['a', 'z'] dentro de la cadena son transformados a mayúsculas.
 * 
 * @return size_t Cantidad total de caracteres convertidos a mayúscula.
 *                Retorna 0 si `cadena` es NULL o si `capacidad` es 0.
 */

size_t cadena_a_mayusculas(char cadena[], size_t capacidad);





#endif 
