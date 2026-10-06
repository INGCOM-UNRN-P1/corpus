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
 * =========================================================================
 * Ejercicio 1: Medición Segura de Longitud
 * =========================================================================
 * @brief Calcula la longitud lógica de una cadena sin sobrepasar "capacidad".
 *
 * @param cadena Puntero a la cadena de caracteres a medir. Puede ser NULL.
 * @param capacidad Número máximo de bytes a inspeccionar en memoria.
 *
 * @pre Si "cadena" != NULL, debe apuntar a un bloque válido de al menos
 *      "capacidad" bytes cuando se invoque la función.
 * @post No modifica la cadena de entrada.
 *
 * @return Número de caracteres previos al terminador '\0' si este se encuentra
 *         dentro de "capacidad". Si no se encuentra '\0' dentro de ese
 *         límite, retorna "capacidad". Retorna 0 si "cadena" == NULL o
 *         "capacidad" == 0.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);

/**
 * =========================================================================
 * Ejercicio 2: Copia Segura con Control de Búfer
 * =========================================================================
 * @brief Copia la cadena "origen" en "destino" respetando la "capacidad".
 *
 * @param destino Búfer donde se realizará la copia. Debe tener al menos
 *                "capacidad" bytes cuando "capacidad" > 0.
 * @param capacidad Tamaño total del búfer "destino" en bytes (incluye '\0').
 * @param origen Cadena fuente que se desea copiar. Puede ser NULL.
 *
 * @pre Si "destino" == NULL o "capacidad" == 0 no se realiza copia y la
 *      función retorna false. Si "origen" == NULL se tratará como cadena
 *      vacía.
 * @post Si "capacidad" > 0, "destino" queda siempre terminado con '\0'.
 *
 * @return "true" si "origen" se copió completo (incluyendo terminador),
 *         "false" si hubo truncamiento o argumentos inválidos.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);

/**
 * =========================================================================
 * Ejercicio 3: Concatenación Segura con Control de Búfer
 * =========================================================================
 * @brief Anexa "origen" al final de "destino" sin exceder "capacidad".
 *
 * @param destino Búfer destino que contiene ya una cadena válida o vacía.
 * @param capacidad Tamaño total del búfer "destino" en bytes.
 * @param origen Cadena a anexar. Puede ser NULL para indicar nada a anexar.
 *
 * @pre Si "destino" == NULL o "capacidad" == 0 no hay efecto y se retorna
 *      false. Si "origen" == NULL no se anexa nada y se retorna true si
 *      "destino" ya es una cadena válida.
 * @post Si "capacidad" > 0, "destino" quedará siempre terminado en '\0'.
 *
 * @return "true" si "origen" se anexó completamente. "false" si hubo
 *         truncamiento o argumentos inválidos.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/**
 * =========================================================================
 * Ejercicio 4: Normalización a Mayúsculas Segura
 * =========================================================================
 * @brief Convierte in-place caracteres ASCII minúsculas a mayúsculas en la
 *        cadena "cadena", respetando "capacidad".
 *
 * @param cadena Búfer con la cadena a convertir. Puede ser NULL.
 * @param capacidad Tamaño total del búfer "cadena" en bytes.
 *
 * @pre Si "cadena" != NULL, debe apuntar a al menos "capacidad" bytes.
 * @post La cadena queda terminada en '\0' si "capacidad" > 0 y sólo se
 *       modifican los caracteres 'a'..'z'.
 *
 * @return Cantidad de caracteres que fueron modificados a mayúscula. Retorna
 *         0 si "cadena" == NULL o "capacidad" == 0.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);

/**
 * =========================================================================
 * Ejercicio 5: Extracción de Subcadena Segura
 * =========================================================================
 * @brief Extrae una subcadena de "origen" comenzando en "inicio" con hasta
 *        "cantidad" caracteres y la copia en "destino" sin exceder
 *        "capacidad".
 *
 * @param destino Búfer donde se almacenará la subcadena. Debe tener al menos
 *                "capacidad" bytes cuando "capacidad" > 0.
 * @param capacidad Tamaño total del búfer "destino".
 * @param origen Cadena fuente de la cual extraer la subcadena. Puede ser
 *               NULL.
 * @param inicio Posición inicial (base 0) en "origen" desde donde empezar.
 * @param cantidad Máxima cantidad de caracteres a copiar desde "origen".
 *
 * @pre Si "origen" != NULL debe apuntar a una cadena válida con terminador
 *      dentro de su memoria accesible. Si "inicio" supera la longitud de
 *      "origen" la función dejará "destino" como cadena vacía (siempre que
 *      "capacidad" > 0).
 * @post Si "capacidad" > 0, "destino" queda terminado en '\0'.
 *
 * @return "true" si se copió la porción solicitada completa sin truncamiento,
 *         "false" si hubo truncamiento o argumentos inválidos.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);

/**
 * =========================================================================
 * Ejercicio 6: Entero a Cadena Decimal Segura
 * =========================================================================
 * @brief Convierte el entero "valor" a su representación decimal ASCII y la
 *        escribe en "destino" respetando "capacidad" (sin desbordar).
 *
 * @param destino Búfer donde se escribirá la representación decimal.
 * @param capacidad Tamaño total del búfer "destino" en bytes.
 * @param valor Entero con signo que se convertirá a texto decimal.
 *
 * @pre Si "destino" == NULL o "capacidad" == 0 la función retorna false.
 * @post Si "capacidad" > 0, "destino" queda terminado en '\0'. En caso de
 *       truncamiento se garantiza que no habrá desbordamiento de búfer.
 *
 * @return "true" si la conversión cabía completa en "destino", "false"
 *         si hubo truncamiento o argumentos inválidos.
 */
bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 
