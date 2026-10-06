#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * @brief Calcula el promedio de todos los elementos de un arreglo de enteros.
 *
 * Hace uso de la función `arreglo_sumar` de la biblioteca libarreglos. Si el
 * arreglo es nulo o la cantidad de elementos es cero, retorna 0.0.
 *
 * @param arreglo de enteros a evaluar.
 * @param cantidad de elementos en el arreglo.
 * @return double Promedio de los elementos o 0.0 si el arreglo es nulo/vacío.
 */

double calcular_promedio(const int arreglo[], size_t cantidad);





 /**
 * @brief Determina si un número entero pertenece a un arreglo.
 *
 * Hace uso de la función `arreglo_buscar` de la biblioteca libarreglos.
 *
 * @param arreglo de enteros donde buscar.
 * @param cantidad de elementos en el arreglo.
 * @param valor entero que se desea buscar.
 * @return true Si el valor se encuentra en el arreglo.
 * @return false Si el valor no pertenece al arreglo, el arreglo es nulo o está vacío.
*/

bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
