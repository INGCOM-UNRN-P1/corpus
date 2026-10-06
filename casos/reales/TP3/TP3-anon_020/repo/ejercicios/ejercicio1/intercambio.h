#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Ordena dos enteros de forma ascendente.
 *
 * @param menor Puntero al primer valor. Si es NULL, no se realiza ninguna acción.
 * @param mayor Puntero al segundo valor. Si es NULL, no se realiza ninguna acción.
 *
 * @note La función usa la operación de intercambio disponible en la librería
 *       de punteros para mantener la lógica centralizada.
 */
void ordenar_par(int *menor, int *mayor);

/**
 * @brief Ordena tres valores enteros en forma ascendente.
 *
 * @param a Puntero al primer valor.
 * @param b Puntero al segundo valor.
 * @param c Puntero al tercer valor.
 *
 * @note Si cualquiera de los punteros es NULL, la función termina sin efectuar
 *       cambios sobre los valores apuntados.
 */
void ordenar_tria(int *a, int *b, int *c);

/**
 * @brief Calcula la suma total de un arreglo de enteros.
 *
 * @param arreglo Arreglo de entrada; debe apuntar a elementos válidos.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param resultado Puntero de salida donde se almacena el total acumulado.
 *
 * @return true si el cálculo se realizó correctamente; false si arreglo o
 *         resultado son NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

#endif 
