#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Se copia origen en destino utilizando exclusivamente aritmética
 * de punteros.
 * @pre 'destino', 'origen' no pueden ser NULL. 'Capacidad' no puede ser 0.
 * @post devuelve true si al copia fue exitosa, sino false.
 * @param destino Es el arreglo en el que se copiara el arreglo origen.
 * @param capacidad Es la cantidad de elementos.
 * @param origen Es el arreglo que sera copiado.
 * @return devuelve true si al copia fue exitosa, sino false.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);
/**
 * @brief Se concatenan dos cadenas, de manera segura.
 * @pre 'destino', 'origen' no pueden ser NULL.
 * Y 'capacidad' no puede ser 0.
 * @post devuelve true si la concatenacion fue exitosa,
 * o false si fallo alguna de las precondiciones o la concatenacion fallo.
 * @param destino Es la cadena resultante de la combinacion.
 * @param capcidad Es el espacio en memoria de 'destino'.
 * @param origen Es la cadena original
 * @param puntero Es la cadena resultante de la combinacion de ambas.
 * @return devuelve true si la concatenacion fue exitosa,
 * o false si fallo alguna de las precondiciones o la concatenacion fallo.
 */
bool concatenar_con_punteros(char destino[], size_t capacidad,
     const char origen[]);
#endif 
