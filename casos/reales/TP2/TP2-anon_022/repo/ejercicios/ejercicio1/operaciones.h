#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Calcula el promedio aritmético de los elementos de un arreglo.
 *
 * @param arreglo Contiene los elementos cuyos valores se desean promediar.
 * @param cantidad Indica la cantidad de elementos.
 *
 * @return El promedio aritmético de los elementos como un valor double.
 *         Retorna 0.0 si el arreglo es nulo o la cantidad es 0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);



/**
 * @brief Comprueba si un valor entero se encuentra dentro de un arreglo.
 *
 * @param arreglo Contiene los elementos donde se buscará el valor.
 * @param cantidad Indica la cantidad de elementos.
 * @param valor Indica el valor cuya presencia se desea comprobar.
 *
 * @return true si el valor se encuentra en el arreglo;
 *         false si no se encuentra, si el arreglo es nulo, o 'cantidad' es 0.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
