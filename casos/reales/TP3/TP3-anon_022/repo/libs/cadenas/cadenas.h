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
 * @brief Cuenta la cantidad de caracteres de una cadena antes del terminador 
 *        nulo '\0', inspeccionando como máximo la capacidad indicada.
 *
 * @param cadena cuyos caracteres se desean contar.
 * @param capacidad Cantidad máxima de bytes que se pueden inspeccionar.
 *
 * @return Cantidad de caracteres de la cadena antes del terminador nulo.
 *         Retorna 'capacidad' si no se encuentra '\0' dentro del rango.
 *         Retorna 0 si la cadena es nula o la capacidad es 0.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);



/**
 * @brief Copia una cadena de origen en un búfer destino de capacidad limitada.
 *
 * @param destino Búfer donde se copiará la cadena de origen.
 * @param capacidad Cantidad máxima de bytes disponibles en el búfer destino.
 * @param origen Cadena que se desea copiar.
 *
 * @return true si la cadena de origen se copia completamente, incluyendo '\0'.
 *         false si la cadena no cabe completamente y es truncada, o si destino
           es nulo, origen es nulo o capacidad es 0.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);



/**
 * @brief Anexa el contenido de origen a continuación del texto existente en
          destino, respetando la capacidad disponible y asegurando el terminador
          nulo.
 *
 * @param destino Búfer que contiene el texto existente y donde se anexará 
                  el contenido de origen.
 * @param capacidad Cantidad máxima de bytes disponibles en el búfer destino.
 * @param origen Cadena que se desea anexar.
 *
 * @return true si todo el texto de origen se concatenó sin truncamiento.
 *         false si hubo truncamiento o alguno de los argumentos es inválido.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);



/**
 * @brief Convierte a mayúsculas todos los caracteres ASCII en minúscula de una 
          cadena, respetando el límite de capacidad y deteniéndose en '\0'.
 *
 * @param cadena cuyos caracteres se desean convertir.
 * @param capacidad Cantidad máxima de bytes que se pueden inspeccionar.
 *
 * @return Número total de conversiones efectuadas.
 *         Retorna 0 si la cadena es nula o la capacidad es 0
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);



/**
 * @brief Extrae una subcadena de una cadena origen en un búfer destino seguro.
 *
 * @pre 'destino' y 'origen' deben apuntar a espacios de memoria válidos.
 *      'capacidad' debe ser mayor que 0 para almacenar el resultado.
 *
 * @post Si 'inicio' supera la longitud de 'origen', 'destino' queda vacío.
 *       Si 'capacidad' es mayor que 0 y los argumentos son válidos,
 *       'destino' queda terminado en '\0'.
 *       Se copian como máximo 'cantidad' caracteres y 'capacidad - 1'
 *       caracteres útiles.
 *
 * @param destino Búfer donde se almacenará la subcadena extraída.
 * @param capacidad Cantidad máxima de bytes disponibles en 'destino',
 *                  incluido el terminador '\0'.
 * @param origen Cadena de la que se extraerá la subcadena.
 * @param inicio Posición inicial desde la que comenzará la extracción.
 * @param cantidad Número máximo de caracteres que se intentarán copiar.
 *
 * @return true si la subcadena se extrajo completamente o si 'inicio'
 *         supera la longitud de 'origen'.
 *         false si algún argumento es inválido o no hay capacidad suficiente
 *         para almacenar todos los caracteres solicitados.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);



#endif 
