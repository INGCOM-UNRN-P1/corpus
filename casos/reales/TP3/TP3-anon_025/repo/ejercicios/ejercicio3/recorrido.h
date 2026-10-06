#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>



 /**
  * @brief Copia los elementos de un arregllo fuente a un arreglo destino.
  * 
  * @param puntero_origen Puntero de solo lectura al inicio del arreglo fuente.
  * @param puntero_detino Puntero al inicio del arreglo destino.
  * @param cantidad_elementos Cantidad de elementos a copiar.
  * 
  * @pre Los punteros no deben ser NULL, el destino debe tener capacidad suficiente.
  */
void copiar_arreglo(const int *puntero_origen, int *puntero_destino, size_t cantidad_elementos);

/**
 * @brief Invierte in-place un arreglo de enetos utilizado 
 * 
 * @param punteros_arreglo Puntero al inicio del arreglo a invertir.
 * @param cantidad_elementos Cantidad de elementos del arreglo.
 * 
 * @pre El pntero no debe ser nulo
 */
void invertir_arreglo(int *puntero_arreglo, size_t cantidad_elementos);

#endif 
