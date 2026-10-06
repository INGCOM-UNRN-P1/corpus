#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Ordena dos variables enteras de forma ascendente por referencia delegando en intercambiar.
 *
 * @pre menor y mayor deben ser punteros validos a variables enteras.
 * @post Garantiza que *menor <= *mayor intercambiando sus contenidos si fuera necesario; si alguno es NULL, no produce efecto.
 *
 * @param menor Puntero a la variable que contendra el menor valor.
 * @param mayor Puntero a la variable que contendra el mayor valor.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres variables enteras ascendentemente apoyandose en ordenar_par e intercambiar.
 *
 * @pre primero, segundo y tercero deben ser punteros validos a variables enteras.
 * @post Garantiza *primero <= *segundo <= *tercero; no produce efecto si algun puntero es NULL.
 *
 * @param primero Puntero a la primera variable entera.
 * @param segundo Puntero a la segunda variable entera.
 * @param tercero Puntero a la tercera variable entera.
 */
void ordenar_tria(int *primero, int *segundo, int *tercero);

/**
 * @brief Calcula la suma acumulada de un arreglo recorriendolo estrictamente con punteros.
 *
 * @pre arreglo apunta a una secuencia contigua de al menos cantidad enteros y resultado es puntero valido.
 * @post Escribe la sumatoria total en *resultado y retorna true; retorna false si arreglo o resultado son NULL.
 *
 * @param arreglo   Puntero de solo lectura al inicio de la secuencia de enteros.
 * @param cantidad  Cantidad de enteros en la secuencia.
 * @param resultado Puntero de salida donde se guardara la suma acumulada.
 *
 * @return bool true si se calculo la suma exitosamente, false ante punteros invalidos.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
