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
 * @brief Mide la longitud de una cadena sin pasarse su capacidad.
 *
 * @param cadena Cadena a medir.
 * @param capacidad Cantidad máxima de bytes a examinar.
 *
 * @return La cantidad de caracteres antes del '\0' dentro del rango, y 0 si
 *         la cadena es NULL o capacidad es 0.
 *
 * @pre Si cadena no es NULL, debe tener al menos 'capacidad' bytes legibles,
 *      o un '\0' antes de agotarlos.
 * @post La cadena no se modifica.
 * @post El resultado es siempre menor o igual que 'capacidad'.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);



/**
 * @brief Copia una cadena de origen en un búfer de destino de forma segura.
 *
 *
 * @param destino   Búfer donde se guarda la copia.
 * @param capacidad Tamaño total del búfer destino en bytes, incluyendo el lugar para el '\0'.
 * @param origen    Cadena terminada en '\0' a copiar. No se modifica.
 *
 * @return true  si todo el contenido de origen se copió (sin truncamiento).
 * @return false si hubo truncamiento, o ante argumentos inválidos:
 *               - destino es NULL o capacidad es 0 (no se escribe nada),
 *               - origen es NULL (destino queda como cadena vacía "").
 *
 * @pre   origen, si no es NULL, es una cadena válida terminada en '\0'.
 * @pre   destino, si no es NULL, apunta a un búfer de al menos
 *        capacidad bytes.
 * @pre  Los búferes  destino y  origen no deben solaparse.
 * @post Si capacidad > 0 y destino != NULL, destino queda terminado en '\0'.
 * @post Nunca se escribe fuera de destino[0 .. capacidad - 1].
 * @post Si hubo truncamiento, destino contiene los primeros capacidad - 1
 *       caracteres de  origen.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);



/**
 * @brief Concatena origen al final de destino sin exceder la capacidad.
 *
 * Copia caracteres de origen a continuación del texto de destino hasta
 * terminar origen o hasta que quede lugar solo para el '\0'. El resultado
 * queda siempre terminado en '\0'.
 *
 * @param[in,out] destino   Búfer con una cadena válida terminada en '\0'.
 * @param[in]     capacidad Tamaño total de destino en bytes (incluye el '\0').
 * @param[in]     origen    Cadena terminada en '\0' a anexar. No se modifica.
 *
 * @return true  si se concatenó todo origen (sin truncamiento).
 * @return false si hubo truncamiento, si destino u origen son NULL,
 *               si capacidad es 0, o si destino no tiene '\0' dentro
 *               de capacidad bytes (se fuerza destino[capacidad - 1] = '\0').
 *
 * @pre  Destino y origen no deben solaparse.
 * @post Nunca se escribe fuera de destino[0 .. capacidad - 1].
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);



/**
 * @brief Convierte los caracteres en minúscula de una cadena a mayúsculas.
 *
 * @param cadena Puntero al arreglo de caracteres que se desea convertir.
 *                          La función modifica directamente este arreglo.
 * @param capacidad Tamaño máximo del búfer en bytes/caracteres para evitar
 *                          desbordamientos de memoria (*buffer overflow*).
 *
 * @return size_t Cantidad de caracteres que fueron efectivamente convertidos
 *                de minúscula a mayúscula.
 *
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);




 /**
 * @brief Extrae una subcadena de una cadena de origen y la copia en un búfer de destino.
 *
 *
 * @param destino Búfer donde se almacenará la subcadena extraída.
 * @param capacidad Tamaño total del búfer de destino (incluyendo el espacio para '\0').
 * @param origen Cadena fuente desde la cual se extraerá la subcadena.
 * @param inicio Índice basado en cero (0) desde donde comenzará la extracción.
 * @param cantidad  Número de caracteres que se intentarán copiar.
 *
 * @return `true`  Si la subcadena se extrajo y copió completamente según lo solicitado.
 * @return `false` Si los parámetros son inválidos (punteros NULL, capacidad 0),
 *                 si el índice `inicio` está fuera del rango de la cadena de origen,
 *                 o si el búfer de destino no tuvo espacio suficiente para alojar la
 *                 cantidad solicitada de caracteres.
 *
 * @note Si la función falla, el parámetro `destino` queda garantizado como una cadena
 *       vacía (`""`), siempre que `destino` no sea NULL y `capacidad > 0`.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);




/**
 * @brief Convierte un número entero en su representación equivalente como cadena de texto.
 *
 * @param destino Búfer donde se almacenará la cadena formateada.
 * @param capacidad Tamaño total del búfer de destino en bytes/caracteres.
 * @param valor Número entero que se desea convertir a texto.
 *
 * @return `true`  Si el entero fue convertido y almacenado completamente en la cadena.
 * @return `false` Si `destino` es NULL, si `capacidad` es 0, o si el espacio disponible
 *                 en `capacidad` es insuficiente para alojar la representación del número
 *                 junto con el carácter nulo final (`'\0'`).
 *
 * @note Si la capacidad es insuficiente, la función asigna `destino[0] = '\0'` (cadena vacía)
 *       siempre que `destino` no sea NULL y `capacidad > 0`.
 * @note La implementación maneja de forma segura el valor `0` y números negativos.
 */
bool cadenas_de_entero(char destino [], size_t, int valor);

#endif 
