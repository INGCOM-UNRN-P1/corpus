#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula el promedio aritmético de los elementos de un arreglo de
 *        enteros, reutilizando arreglo_sumar de libarreglos.
 *
 * @param arreglo Arreglo de enteros de solo lectura. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en `arreglo`.
 *
 * @pre Ninguna; la función es segura ante `arreglo == NULL`.
 * @post El arreglo no es modificado.
 *
 * @return El promedio de los elementos como double. Retorna 0.0 si
 *         `arreglo` es NULL o si `cantidad` es 0.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);

/**
 * @brief Determina si un valor pertenece a un arreglo de enteros,
 *        reutilizando arreglo_buscar de libarreglos.
 *
 * @param arreglo Arreglo de enteros de solo lectura. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en `arreglo`.
 * @param valor Valor entero a buscar dentro de `arreglo`.
 *
 * @pre Ninguna; la función es segura ante `arreglo == NULL`.
 * @post El arreglo no es modificado.
 *
 * @return true si `valor` se encuentra en `arreglo`. Retorna false si no
 *         se encuentra, si `arreglo` es NULL, o si `cantidad` es 0.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
