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
#include <limits.h>


/**
 * @brief se mide la longitud de una cadena.
 * @pre 'cadena' es NULL retorna 0.
 * @post Se mide la cantidad de bits de una cadena.
 * @param cadena Es la cadena de caracteres.
 * @param capacidad Es la cantidad de "espacio" que ocupa la cadena.
 * @return se devuelve el largo de la cadena.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);


/**
 * @brief Se copia la cadena.
 * @pre la cadena 'origen' no puede ser NULL.
 * @pre la cadena 'destino' no puede ser NULL.
 * @pre capacidad no puede ser 0.
 * @post se copia la cadena original.
 * @param destino es la copia de la cadena 'origen'.
 * @param origen es la cadena original / incial.
 * @param capacidad es la capacidad de memoria de la cadena.
 * @return devuelve true, si la cadena fue copiada con exito, o false sino.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief Se "encanchan" dos cadenas, la destino al final de la origen.
 * @pre la cadena 'origen' no puede ser NULL.
 * @pre la cadena 'destino' no puede ser NULL.
 * @pre capacidad no puede ser 0.
 * @post Las cadenas se pudieron concatenar con exito o no,
 * lo que devuelve un valor booleano.
 * @param destino es la copia de la cadena 'origen'.
 * @param origen es la cadena original / incial.
 * @param capacidad es la capacidad de memoria de la cadena.
 * @param largo_origen es el largo de la cadena origen.
 * @param largo_destino es el largo de la cadena destino.
 * @return devuelve true, si se pudo concatenar correctamente, o false sino.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);


/**
 * @brief See transforman, las letras minusculas de ela cadeena, a mayusculas,
 * mediantee el codigo ASCCI.
 * @pre 'cadena' no debe seer NULL.
 * @pre 'capacidad' no debe ser 0.
 * @post la cadena, si contenia letras een minuscula, son transformadas en
 * mayuscula, el resto de los elementos de la cadena no se tocan.
 * @param cadena es la cadena
 * @param capacidad es la cantidad de espacio en la memoria
 * disponible en la cadena.
 * @param transformados son la cantidad de letras que han sido
 * modificadas a mayuscula.
 * @return se devuelve la cantidad de caracteres convertidos.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);


/**
 * @brief se extrae un pedazo de la cadena origen,
 * y se copia en la cadena destino.
 * @pre 'destino' no debe ser NULL.
 * @pre 'origen' no debe ser NULL.
 * @pre 'capacidad' no debe ser 0.
 * @post se extrae un pedazo de la cadena original.
 * @param destino es la cadena nueva.
 * @param origen es la cadena original.
 * @param capacidad cantidad de espacio de memoria disponible en la cadena.
 * @return si al extraccion fue exitosa devuelve true, sino false.
 */
bool cadena_subcadena(char destino[], size_t capacidad, const char origen[],
     size_t inicio, size_t cantidad);


/**
 * @brief Se transforma el valor a cadenas,
 * de numeros de tipo entero, incluyendo 0 y negativos.
 * @pre 'destino' no debe ser NULL.
 * @pre 'capacidad' no debe ser menor a 2.
 * @pre 'valor'si es 0 devuelve 0, sino se procesa el numero.
 * @post si el numero es negativo se hace el complemento A2,
 * sino se pasa tal cual, como cadena.
 * @param destino es la cadena donde se almacenara la cadena resulatnte.
 * @param capacidad es el espacio en la memoria disponible en 'destino'.
 * @param valor es el valor numerico, que se extraera.
 * @param numero es valor.
 * @return devuelve verdadero si se logro hacer la
 * conversion correctamente, sino false.
 */
bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 
