#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca la primera aparicion de un valor en un arreglo.
 * 
 * @param arreglo_fuente Puntero de solo lectura al inicio del arreglo
 * @param cantidad_elementos Cantidad de elementos del arreglo
 * @param valor_buscado El numero que deseamos encontrar
 * 
 * @return const int* Puntero a la posicion exacta en memoria, o NULL si no existe
 */
const int* buscar_primero(const int *arreglo_fuente, size_t cantidad_elementos, int valos_buscado);

/**
 * @brief Calcula el indice o distancia relativa entre un elemento y el inicio del arreglo.
 * 
 * @param puntero_inicio Puntero de solo lectura al inicio del arreglo.
 * @param puntero_elemento Puntero de solo lectura al elemento interno.
 * 
 * @return ptrdiff_t Distancia relativa o -1 si alguno es NULL.
 */
ptrdiff_t distancia_punteros(const int *puntero_inicio, const int *puntero_elemento);

#endif 
