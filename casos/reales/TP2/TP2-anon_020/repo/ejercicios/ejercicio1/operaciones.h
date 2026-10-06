#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula el promedio aritmético de los elementos de un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo de enteros; puede
 *                ser NULL si no hay datos.
 * @param cantidad Número de elementos válidos en `arreglo`.
 * @return Retorna el promedio como `double`. Si `arreglo` es NULL o
 *         `cantidad` es 0, retorna 0.0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Indica si un valor entero aparece en un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo de enteros; puede
 *                ser NULL.
 * @param cantidad Número de elementos válidos en `arreglo`.
 * @param valor Entero que se desea buscar en el arreglo.
 * @return `true` si `valor` está presente en el arreglo; `false` si no está
 *         presente o si `arreglo` es NULL o `cantidad` es 0.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
