#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * Invierte la secuencia de elementos de un arreglo en su misma memoria
 * (in-place).
 *
 * @param arreglo puntero al primer elemento de la secuencia a reordenar.
 * @param cantidad de elementos presentes dentro del contenedor.
 * @pre El puntero arreglo debe apuntar a un bloque de memoria valido de al
 *      menos cantidad elementos si cantidad > 0.
 * @post Si la funcion retorna true, la secuencia de elementos dentro de
 *       arreglo queda completamente dada vuelta (in-place).
 * @returns true si el arreglo fue invertido correctamente o si la dimension
 *          es <= 1. Retorna false si el parametro arreglo es nulo.
*/
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
