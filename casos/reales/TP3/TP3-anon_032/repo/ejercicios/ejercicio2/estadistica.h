#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**
 * @brief Calcula promedio minimo y maximo de un arreglo de enteros.
 * @param arreglo El arreglo del que se sacara el minimo y maximo.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @param minimo Un puntero a un int donde se guardara el elemento mas chico.
 * @param maximo Un puntero a un int donde se guardara el elemento mas grande.
 * @param promedio El promedio de los elementos dentro de arreglo.
 * @pre Ninguno de los punteros debe ser nulo y cantidad debe ser mayor a cero.
 * @post Se guardaran los resultados en las variables apuntadas por minimo, maximo y promedio
 * sin modificar arreglo. 
 * @returns Se retornara false si algun puntero es nulo o cantidad es cero y true si
 * se pudo completar la funcion con exito.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad,
    int *minimo, int *maximo, double *promedio);

/**
 * @brief Recorre el arreglo con aritmética de punteros contando cuántos elementos
 *    pertenecen al intervalo entre limite_inf y limite_sup.
 * @param arreglo El arreglo donde se contara el intervalo.
 * @param cantidad La cantidad de elementos que tiene el arreglo.
 * @param limite_inf El limite inferior del intervalo
 * @param limite_sup El limite superior del intervalo.
 * @param coincidencias La cantidad de elementos que pertenecen al intervalo.
 * @pre Ningun pointer debe ser nulo y cantidad no debe ser cero. limite_inf debe ser
 * superior a limite_sup.
 * @post Se respetara la cantidad de elementos contados dentro del arreglo al buscar
 * coincidencias.
 * @returns Retorna true si calculó el conteo, o false si arreglo o coincidencias son NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad,
    int limite_inf, int limite_sup, size_t *coincidencias);


#endif 
