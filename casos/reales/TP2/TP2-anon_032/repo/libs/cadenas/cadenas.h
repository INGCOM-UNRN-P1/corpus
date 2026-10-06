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
#include <ctype.h>

/**
 * @brief Calcula el largo de una cadena de forma segura.
 * @param cadena La cadena a calcular.  
 * @param capacidad La capacidad de cadena.
 * @pre Cadena no debe ser un arreglo nulo y capacidad debe ser mayor a 0;
 * @post Se devolvera un size_t que representa el largo de la cadena.
 * @returns El largo de la cadena.
 */
size_t cadena_longitud(const char cadena[], size_t capacidad);

/**
 * @brief Copia una cadena sobre otra de forma segura.
 * @param destino Donde se copiara la cadena.
 * @param capacidad La capacidad de destino.
 * @param origen La cadena a copiar.
 * @pre Las cadenas no deben ser arreglos nulos y capacidad debe ser mayor al 
 * largo de origen, de lo contrario se copiara una cadena truncada.
 * @post Se copiara la cadena de origan en destino con un caracter terminador.
 * @returns Retorna true si la operacion fue exitosa o false de lo contrario.
 */
bool cadena_copiar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Concatena dos cadenas de forma segura.
 * @param destino El arreglo al que se concatenara origen.
 * @param capacidad La capacidad de destino.
 * @param origen La cadena que se concatenara con destino.
 * @pre Las cadenas no deben ser arreglos nulos y capacidad debe ser mayor a la
 * suma de destino y origen, de lo contrario la concatenacion quedara truncada.
 * @post Las cadenas quedaran concatenadas en destino con un caracter terminador.
 * @returns Retorna true si la operacion fue exitosa o false de lo contrario.
 */
bool cadena_concatenar(char destino[], size_t capacidad, const char origen[]);

/**
 * @brief Normaliza los caracteres de una cadena a mayuscula.
 * @param cadena La cadena que se normalizara.
 * @param capacidad La capacidad de la cadena.
 * @pre Cadena no debe ser un arreglo nulo y capacidad debe ser mayor a cero.
 * @post Los caracteres alfabeticos en minuscula se pasaran a mayuscula sin tocar 
 * los digitos, simbolos no alfanumericos o los que ya eran mayuscula.
 * @returns La cantidad de caracteres que se pasaron a mayuscula.
 */
size_t cadena_a_mayusculas(char cadena[], size_t capacidad);

/**
 * @brief Extrae una porcion de origen a partir de inicio copiando cantidad caracteres
 * en destino.
 * @param destino El arreglo donde se copiara la porcion.
 * @param capacidad_destino La capacidad de destino.
 * @param origen La cadena de la que se copiara en destino.
 * @param capacidad_origen La capacidad de origen.
 * @param inicio La posicion a partir de donde se copiara.
 * @param cantidad La cantidad de caracteres que se copiaran.
 * @pre Ninguno de los arreglos debe ser nulo, inicio debe ser menor al largo 
 * de origen, capacidad_destino debe ser mayor a la suma de inicio mas cantidad. 
 * @post se escribira en destino la porcion extraida de origen, en caso de que la capacidad
 * sea insuficiente se escribira una porcion truncada o una cadena vacia si inicio es 
 * mayor al largo de origen.
 * @returns True si la operacion fue exitosa y la poricon se copio sin truncamientos, 
 * false en caso contrario.
 */
bool cadena_subcadena(char destino[], size_t capacidad_destino, 
                    const char origen[], size_t capacidad_origen, 
                    size_t inicio, size_t cantidad);

/**
 * @brief Transforma un numero entero con signo en una cadena.
 * @param destino La cadena donde se escribira el numero en forma de caracteres.
 * @param capacidad La capacidad de destino.
 * @param valor El numero que se escribira en destino.
 * @pre La capacidad de destino debe ser mayor a los digitos de valor y destino no
 * debe ser un arreglo nulo.
 * @post Se escribira valor en destino en forma de caracteres respetando el signo
 * y contemplando casos de cero y INT_MIN.
 * @returns True si la operacion fue exitosa y false en caso contrario.
 */
bool cadena_de_entero(char destino[], size_t capacidad, int valor);

#endif 
