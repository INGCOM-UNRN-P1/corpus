#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia una cadena segura a un bufer acotado recorriendo exclusivamente con punteros.
 *
 * @pre destino apunta a un bufer con espacio de al menos capacidad bytes, origen es cadena terminada en '\0'.
 * @post Copia caracteres asegurando '\0' final si capacidad > 0; retorna true si copio completa, false ante truncamiento o error.
 *
 * @param destino Puntero al bufer receptor de los caracteres.
 * @param capacidad Capacidad fisica total del bufer destino en bytes.
 * @param origen Puntero de solo lectura a la cadena origen terminada en nulo.
 *
 * @return bool true si se copio sin truncamiento, false si se trunco o ante parametros invalidos.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena una cadena al final de otra en un bufer acotado usando exclusivamente punteros.
 *
 * @pre destino contiene una cadena valida con espacio total de capacidad bytes, origen es terminada en '\0'.
 * @post Concatena origen garantizando '\0'; retorna true si entro completa, false si hubo truncamiento o error.
 *
 * @param destino Puntero al bufer donde se anexaran los caracteres.
 * @param capacidad Capacidad fisica total del bufer destino en bytes.
 * @param origen Puntero de solo lectura a la cadena a anexar.
 *
 * @return bool true si se anexo sin truncamiento, false si se trunco o ante parametros invalidos.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
