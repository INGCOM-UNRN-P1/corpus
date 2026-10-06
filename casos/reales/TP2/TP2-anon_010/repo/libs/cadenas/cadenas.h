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
 * @brief Calcula la longitud de una cadena, sin exceder su capacidad física.
 *
 * @param cadena Cadena de solo lectura a medir. Puede ser NULL.
 * @param capacidad Capacidad total del búfer `cadena` (cantidad máxima de
 *                  bytes a inspeccionar, incluyendo el lugar del '\0').
 *
 * @pre Ninguna; la función es segura ante `cadena == NULL`.
 * @post La cadena no es modificada.
 *
 * @return La cantidad de caracteres antes del primer '\0' encontrado dentro
 *         de los primeros `capacidad` bytes. Retorna `capacidad` si no se
 *         encuentra ningún '\0' en ese rango, o si `cadena` es NULL.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);


/**
 * @brief Copia una cadena de origen a un búfer destino, sin desbordar su
 *        capacidad, garantizando terminación nula.
 *
 * @param destino Búfer mutable donde se copia el resultado. Puede ser NULL.
 * @param capacidad Capacidad total de `destino` en bytes (incluyendo el
 *                  lugar del '\0').
 * @param origen Cadena de solo lectura a copiar. Puede ser NULL.
 *
 * @pre `origen` debe estar correctamente terminada en '\0' dentro de un
 *      rango razonable de memoria.
 * @post `destino` queda terminado en '\0' dentro de sus límites válidos,
 *       conteniendo como máximo `capacidad - 1` caracteres de `origen`.
 *
 * @return true si `origen` se copió completo. Retorna false si el texto se
 *         truncó por falta de capacidad, o si `destino` es NULL, `origen` es
 *         NULL, o `capacidad` es 0.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Concatena una cadena de origen al final del texto ya existente en
 *        un búfer destino, sin desbordar su capacidad.
 *
 * @param destino Búfer mutable que ya contiene una cadena segura, al cual
 *                se le anexa `origen`. Puede ser NULL.
 * @param capacidad Capacidad total de `destino` en bytes (incluyendo el
 *                  lugar del '\0').
 * @param origen Cadena de solo lectura a anexar. Puede ser NULL.
 *
 * @pre `destino` debe estar correctamente terminado en '\0' dentro de
 *      `capacidad` (invariante de cadena segura). `origen` debe estar
 *      correctamente terminada en '\0'.
 * @post `destino` queda terminado en '\0' dentro de sus límites válidos,
 *       con tanto de `origen` anexado como haya entrado sin exceder
 *       `capacidad - 1` caracteres totales.
 *
 * @return true si `origen` se anexó completo. Retorna false si el texto se
 *         truncó por falta de capacidad, o si `destino` es NULL, `origen` es
 *         NULL, o `capacidad` es 0.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Convierte in-place los caracteres en minúscula de una cadena a
 *        su equivalente en mayúscula.
 *
 * @param cadena Búfer mutable a normalizar. Puede ser NULL.
 * @param capacidad Capacidad total de `cadena` en bytes.
 *
 * @pre Ninguna; la función es segura ante `cadena == NULL`.
 * @post Los caracteres en el rango ['a', 'z'] dentro de los primeros
 *       `capacidad` bytes (hasta el primer '\0') quedan convertidos a su
 *       equivalente en mayúscula. El resto de los caracteres permanece
 *       sin cambios.
 *
 * @return La cantidad de caracteres efectivamente convertidos. Retorna 0
 *         si `cadena` es NULL.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);


/**
 * @brief Extrae una porción de una cadena de origen en un búfer destino
 *        seguro, a partir de una posición y una cantidad dadas.
 *
 * @param destino Búfer mutable donde se copia la porción extraída. Puede
 *                ser NULL.
 * @param capacidad Capacidad total de `destino` en bytes (incluyendo el
 *                  lugar del '\0').
 * @param origen Cadena de solo lectura desde la cual extraer. Puede ser NULL.
 * @param capacidad_origen Capacidad total de `origen` en bytes, usada para
 *                          determinar de forma segura su longitud real.
 * @param inicio Posición (base cero) de `origen` desde donde comienza la
 *               porción a extraer.
 * @param cantidad Cantidad máxima de caracteres a copiar desde `inicio`.
 *
 * @pre Ninguna; la función es segura ante `origen == NULL`, `inicio` fuera
 *      de rango, o `cantidad` mayor a lo disponible en `origen`.
 * @post `destino` queda terminado en '\0' dentro de sus límites válidos,
 *       conteniendo como máximo `cantidad` caracteres de `origen` a partir
 *       de `inicio`, sin exceder `capacidad - 1` caracteres.
 *
 * @return true si se copiaron exactamente los `cantidad` caracteres
 *         pedidos. Retorna false si hubo truncamiento (por falta de
 *         capacidad en `destino` o por quedarse sin texto en `origen` antes
 *         de completar `cantidad`), o si `destino` es NULL, `origen` es
 *         NULL, o `capacidad` es 0.
 */
bool subcadena_segura(char destino[], size_t capacidad, const char origen[], size_t capacidad_origen, size_t inicio, size_t cantidad);


/**
 * @brief Convierte un valor entero a su representación en caracteres ASCII
 *        decimales dentro de un búfer seguro.
 *
 * @param destino Búfer mutable donde se escribe la representación decimal
 *                de `valor`. Puede ser NULL.
 * @param capacidad Capacidad total de `destino` en bytes (incluyendo el
 *                  lugar del '\0' y, si corresponde, el signo '-').
 * @param valor Valor entero a convertir. Puede ser positivo, negativo o
 *              cero, incluyendo INT_MIN.
 *
 * @pre Ninguna; la función maneja de forma segura todo el rango de `int`,
 *      incluyendo INT_MIN.
 * @post `destino` queda terminado en '\0' dentro de sus límites válidos,
 *       conteniendo la representación decimal de `valor` (con el signo '-'
 *       si es negativo), truncada si no entra completa en `capacidad`.
 *
 * @return true si la representación completa de `valor` (signo incluido)
 *         entró en `destino`. Retorna false si se truncó por falta de
 *         capacidad, o si `destino` es NULL o `capacidad` es 0.
 */
bool cadena_entero(char destino[], size_t capacidad, int valor);

#endif 
