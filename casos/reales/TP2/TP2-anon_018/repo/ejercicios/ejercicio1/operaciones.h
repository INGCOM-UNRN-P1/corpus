#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * @brief Calcula el promedio de los elementos de un arreglo.
 * 
 * @param arreglo  Arreglo de enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @return El promedio de los elementos, o 0.0 si arreglo 
 *         es NULL o cantidad es 0.
 *
 */

double calcular_promedio(const int arreglo[], size_t cantidad);



 /**
 * @brief Indica si un valor está en el arreglo.
 *
 * @param arreglo  Arreglo de enteros donde se busca.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param valor Valor a buscar.
 *
 * @return true si el valor está en el arreglo.
 * @return false si no está.
 */
 
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
