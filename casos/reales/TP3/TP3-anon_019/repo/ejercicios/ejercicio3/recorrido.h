#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h" 

/**
 * @brief Copia elementos de un arreglo origen a un arreglo destino.
 * 
 * @pre Los punteros 'origen' y 'destino' no deben ser nulos.
 *      El arreglo 'destino' debe tener capacidad suficiente.
 * @post Los elementos de 'origen' se copian en 'destino'.
 *       Se utiliza estrictamente aritmética de punteros (*dst++ = *src++).
 * 
 * @param origen Puntero al arreglo de lectura.
 * @param destino Puntero al arreglo de escritura.
 * @param cantidad Número de elementos a copiar.
 * @return true si la copia fue exitosa.
 * @return false si algún puntero es nulo.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * @brief Invierte el orden de los elementos de un arreglo in-place.
 * 
 * @pre El puntero 'arreglo' no debe ser nulo.
 * @post El arreglo queda invertido sobre su propia memoria.
 *       Se utilizan dos punteros convergiendo (inicio++ y fin--).
 * 
 * @param arreglo Puntero al arreglo a invertir.
 * @param cantidad Número de elementos del arreglo.
 * @return true si la inversión fue exitosa.
 * @return false si el puntero es nulo.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 