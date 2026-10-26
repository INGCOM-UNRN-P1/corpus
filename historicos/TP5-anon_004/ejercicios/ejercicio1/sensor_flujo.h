#ifndef SENSOR_FLUJO_H
#define SENSOR_FLUJO_H

#include <stdbool.h>
#include <stddef.h>
#include "dinamicos.h"

bool cargar_muestras(arreglo_dinamico_t *muestras, const int *valores, size_t n);
double calcular_promedio(const arreglo_dinamico_t *muestras);
size_t depurar_lecturas_erroneas(arreglo_dinamico_t *muestras, int codigo_error);
bool extraer_eventos_pares(const arreglo_dinamico_t *muestras, arreglo_dinamico_t *eventos);

#endif 
