#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Copia todos los elementos de un arreglo origen a otro arreglo destino 
 * de igual o mayor tamaño.
 *
 * @param destino El arreglo donde se copiara origen.
 * @param capacidad_destino La capacidad de destino.
 * @param origen El arreglo que se copiara en destino.
 * @param cantidad_origen La cantidad de elementos en origen.
 * @pre Los punteros no deben ser nulos y los parametros de cantidad no deben ser cero.
 * @post Copia un arreglo respetando la cantidad de destino.
 * @return Si alguno de los punteros es nulo o la capacidad de los arreglos es cero
 * se retorna false, si la funcion se completo con exito se retorna true.
 */
bool copiar_arreglo(int *destino, size_t cantidad_destino,
                    int *origen, size_t cantidad_origen);

/**
 * @brief Invierte un arreglo de enteros.
 *
 * @param arreglo El arreglo a invertir.
 * @param cantidad La cantidad de elementos que contiene el arreglo
 * @pre arreglo no debe ser nulo y cantidad no debe ser cero.
 * @post Invierte el arreglo in-place modificando sus elementos.
 * @return Retorna false si arreglo es nulo o cantidad es cero, true si la funcion
 * se completo con exito.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);
#endif 
