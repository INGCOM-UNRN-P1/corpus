#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



void ordenar_par(int *menor, int *mayor);


void ordenar_tria(int *valor_menor, int *valor_medio, int *valor_mayor);


bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);
#endif 
