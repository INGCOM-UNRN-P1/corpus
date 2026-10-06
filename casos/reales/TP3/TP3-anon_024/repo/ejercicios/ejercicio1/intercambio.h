#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * =========================================================================
 * Ejercicio 1: Ordenamiento de Pares, Tríos y Acumulación por Referencia
 * =========================================================================
 * Ordena dos enteros recibidos por referencia en orden ascendente.
 *
 * @param menor puntero al primer entero que almacenara el menor valor.
 * @param mayor puntero al segundo entero que almacenara el mayor valor.
 * @pre Ambos punteros deben apuntar a direcciones de memoria validas (no nulas)
 *      para realizar el ordenamiento.
 * @post Si ambos punteros son validos, la dirección menor contendra un valor
 *       <= a mayor. Si alguno es NULL, no produce efectos.
*/
void ordenar_par(int *menor, int *mayor);

/**
 * Ordena tres enteros recibidos por referencia en orden ascendente.
 *
 * @param ptr_a puntero al primer entero a ordenar.
 * @param ptr_b puntero al segundo entero a ordenar.
 * @param ptr_c puntero al tercer entero a ordenar.
 * @pre Todos los punteros deben ser no nulos para garantizar el ordenamiento.
 * @post Si los tres punteros son validos, las posiciones apuntadas quedan
 *       ordenadas de forma ascendente (*ptr_a <= *ptr_b <= *ptr_c). Si alguno
 *       es NULL, no se modifica ninguna posicion de memoria.
*/
void ordernar_tria(int *ptr_a, int *ptr_b, int *ptr_c);

/**
 * Calcula la suma acumulada de los elementos de un arreglo.
 *
 * @param arreglo puntero al primer elemento de la secuencia a procesar.
 * @param cantidad de elementos presentes dentro del contenedor.
 * @param resultado puntero de salida donde se almacenara el total de la suma.
 * @pre El puntero arreglo debe apuntar a un contenedor valido con al menos
 *      cantidad elementos si cantidad > 0.
 * @post El contenido de la secuencia procesada permanece inalterado. Si la
 *       función retorna true, la variable apuntada por resultado almacena
 *       la suma de la secuencia.
 * @returns true si se hizo efectivo el calculo de forma exitosa.
 *          Retorna false si arreglo es nulo o si resultado es nulo.
*/
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
