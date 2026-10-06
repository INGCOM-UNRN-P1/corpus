#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "vector.h"
#include "cadenas.h"


/**
 * @brief Crea una lista de cadenas.
 * @return Devuelve un puntero nulo.
 */
char **lista_cadenas_crear(void);

/**
 * @brief Agrega una cadena a una lista de cadenas.
 *
 * @param lista La lista donde se agregara la cadena.
 * @param cantidad La cantidad de cadenas en la lista.
 * @param cadena La cadena a agregar.
 * @param capacidad La capacidad de la cadena.
 * @pre Ninguno de los punteros debe ser nulo. Cantidad debe ser una variable 
 * reservada para la cantidad de cadenas en la lista ya que se modificara.
 * @post Se creara un bloque nuevo en el heap y su puntero se agregara a la lista
 * sin modificar la cadena original. Cantidad se modificara para reflejar la
 * cantidad de cadenas en la lista.
 * @return Devuelve true si la operacion se completo con exito o false en caso de
 * error.
 */
bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena, size_t capacidad);

/**
 * @brief Destruye una lista de cadenas de forma segura.
 *
 * @param lista La lista a destruir.
 * @param cantidad La cantidad de cadenas que contiene la lista.
 * @pre lista no debe ser nulo.
 * @post Se destruira la lista de cadenas y sus cadenas de forma segura sin
 * provocar fugas de memoria ni dejar punteros colgantes.
 */
void lista_cadenas_destruir(char **lista, size_t cantidad);



#endif
