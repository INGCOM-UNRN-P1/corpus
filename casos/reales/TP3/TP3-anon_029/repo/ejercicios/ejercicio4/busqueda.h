#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Se calcula la distacia relativa entre los punteros o indice.
 * @pre 'incio', 'puntero' no pueden ser NULL.
 * Y puntero no puede ser menor a inicio.
 * @post devuelve el indice entre ambos.
 * @param inicio Es el arreglo original.
 * @param puntero Es el otro arreglo.
 * @return se devulve el indice entre ambos.
 */
int distancia_punteros(const int *inicio, const int *puntero);
/**
 * @brief Se busca la primera aparicion del elemento buscado.
 * @pre 'inicio', 'puntero' no deben ser NULL.
 * @post Devuelve la direccion de memoria del elemento encontrado.
 * @param arreglo es el arreglo.
 * @param capacidad Es el tamanio del arreglo.
 * @param valor_buscado Es el valor buscado en el arreglo.
 * @return Devuelve la direccion de memoria del elemento encontrado.
 */
const int *buscar_primero(const int *arreglo, size_t capacidad, int valor_buscado);
#endif 
