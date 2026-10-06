#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

 
/**
 * @brief Busca el puntero al elemento menor dentro de un rango.
 *
 * @param inicio El inicio del rango.
 * @param fin El fin del rango.
 * @pre Los punteros no deben ser nulos. Inicio debe ser menor a fin.
 * @post Busca el puntero menor isn modificar los valores del rango. 
 * @return Retorna un puntero al elemento mas chico dentro del rango o un puntero
 * nulo si los parametros son invalidos.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena los elementos de de forma ascendiente dentro de un arreglo de enteros
 * usando el algoritmo de seleccion.
 *
 * @param arreglo El arreglo que se ordenara.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @pre Arreglo no debe ser nulo y cantidad debe ser mayor a cero.
 * @post Se ordenara el arreglo respetando su cantidad de elementos.
 * @return Se retornara true si la funcion se completo con exito o false si arreglo
 * es nulo o cantidad es cero.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);
#endif 
