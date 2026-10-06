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
#include <limits.h>//para INT_MAX y INT_MIN del ejercicio 6


/**
 * @brief Cuenta la cantidad de caracteres útiles de una cadena de forma segura.
 * 
 * Revisa como máximo 'capacidad' bytes en memoria para prevenir lecturas fuera
 * de límites si la cadena careciese de '\0'.
 * 
 * @pre 'cadena' es un puntero válido o NULL. 'capacidad' > 0.
 * @post Retorna la longitud real de la cadena o 'capacidad' si no encuentra '\0'.
 * 
 * @param cadena Puntero al búfer de caracteres a evaluar.
 * @param capacidad Tamaño máximo en bytes a examinar en memoria.
 * @return size_t Cantidad de caracteres útiles encontrados antes del '\0' o capacidad.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);

/**
 * @brief Copia una cadena de origen a un búfer destino de forma segura.
 * 
 * Si origen cabe completo (incluyendo '\0'), lo copia y retorna true. Si no
 * cabe completo, copia los primeros capacidad - 1 caracteres, coloca '\0'
 * al final y retorna false para advertir el truncamiento.
 * 
 * @pre 'destino' y 'origen' son punteros válidos (no NULL si capacidad > 0).
 * @post El búfer destino termina en '\0' si capacidad > 0.
 * 
 * @param destino Puntero al búfer donde se copiará el texto.
 * @param capacidad Tamaño total físico del búfer destino en bytes.
 * @param origen Puntero a la cadena de texto fuente a copiar.
 * @return true Si la copia se completó íntegramente sin truncar.
 * @return false Si hubo truncamiento por falta de espacio o argumentos inválidos.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Concatena una cadena origen al final de otra destino de forma segura.
 * 
 * Anexa el contenido de origen al final del texto preexistente en destino,
 * respetando estrictamente la capacidad total del búfer y garantizando el terminador.
 * 
 * @pre 'destino' y 'origen' son punteros válidos a cadenas terminadas en '\0'.
 * @post El búfer destino mantiene su contenido previo seguido de la unión y '\0'.
 * 
 * @param destino Puntero al búfer destino con el texto base.
 * @param capacidad Tamaño total físico del búfer destino en bytes.
 * @param origen Puntero a la cadena que se desea anexar.
 * @return true Si todo el texto de origen se concatenó sin truncamiento.
 * @return false Si hubo truncamiento por falta de espacio o argumentos inválidos.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Convierte in-place los caracteres minúsculas de una cadena a mayúsculas.
 * 
 * Analiza los caracteres ASCII ('a'-'z') presentes en la cadena, transformándolos
 * a mayúsculas sin sobrepasar el límite de capacidad y deteniéndose en el '\0'.
 * 
 * @pre 'cadena' es un búfer modificable válido.
 * @post Los caracteres alfabéticos minúsculas se modifican a sus equivalentes mayúsculas.
 * 
 * @param cadena Puntero al búfer de caracteres a normalizar.
 * @param capacidad Tamaño máximo del búfer a recorrer.
 * @return size_t Cantidad total de caracteres convertidos con éxito.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);

/**
 * @brief Extrae una porción específica de una cadena de origen de forma segura.
 * 
 * Copia a lo sumo 'cantidad' caracteres de origen a partir de una posición 'inicio'
 * dentro de un búfer destino acotado por 'capacidad'. Si el índice 'inicio' supera
 * la longitud del origen, el destino queda como una cadena vacía ("").
 * 
 * @pre 'destino' y 'origen' son punteros válidos.
 * @post El búfer destino queda terminado en '\0' si capacidad > 0.
 * 
 * @param destino Puntero al búfer donde se guardará la subcadena extraída.
 * @param capacidad Tamaño total físico del búfer destino en bytes.
 * @param origen Puntero a la cadena fuente de la cual extraer.
 * @param inicio Índice numérico del carácter inicial de extracción.
 * @param cantidad Cantidad máxima de caracteres a extraer.
 * @return true Si la extracción se completó correctamente.
 * @return false Si hubo argumentos inválidos o truncamiento estricto.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);

/**
 * @brief Convierte un número entero con signo a su representación textual en base 10.
 * 
 * Transforma un 'valor' (positivo, negativo o cero, incluyendo el caso extremo INT_MIN)
 * en caracteres ASCII decimales dentro de un búfer seguro acotado por 'capacidad'.
 * 
 * @pre 'destino' es un búfer de memoria válido de al menos 'capacidad' bytes.
 * @post Si la capacidad es insuficiente, coloca '\0' (si capacidad >= 1) y retorna false.
 * 
 * @param destino Puntero al búfer destino donde se escribirá la representación textual.
 * @param capacidad Tamaño total físico del búfer destino en bytes.
 * @param valor Número entero con signo a convertir.
 * @return true Si la conversión e impresión numérica se completaron sin desbordamiento.
 * @return false Si la capacidad fue insuficiente o el destino fue nulo.
 */

 bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 
