#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula el promedio de los elementos de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros cuyos elementos se promedian.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre Si 'cantidad' es mayor que 0, 'arreglo' debe apuntar a un arreglo
 *      válido de al menos 'cantidad' elementos.
 * @returns El promedio de los elementos del arreglo como un número real.
 *          Retorna 0.0 si 'arreglo' es NULL o 'cantidad' es 0.
 * @post Si 'arreglo' es NULL o 'cantidad' es 0, retorna 0.0.
 *       En otro caso, retorna la suma de los elementos dividida por
 *       'cantidad'.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Determina si un valor pertenece a un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros donde se busca el valor.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Valor entero que se desea buscar.
 *
 * @pre Si 'cantidad' es mayor que 0, 'arreglo' debe apuntar a un arreglo
 *      válido de al menos 'cantidad' elementos.
 * @returns true si 'valor' pertenece al arreglo; false en caso contrario.
 * @post El arreglo no es modificado.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
