#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"




 /**
 * @brief Calcula el mínimo, el máximo y el promedio de un arreglo de enteros.
 *
 * Se apoya en 'obtener_min_max' de libpunteros para los extremos, y calcula
 * el promedio acumulando con aritmética de punteros (sin `[]`).
 *
 * @param[in]  arreglo  Arreglo de enteros a analizar (solo lectura).
 * @param[in]  cantidad Cantidad de elementos del arreglo a considerar.
 * @param[out] minimo   Puntero donde se escribe el valor mínimo. Su valor
 * inicial no es relevante.
 * @param[out] maximo   Puntero donde se escribe el valor máximo. Su valor
 * inicial no es relevante.
 * @param[out] promedio Puntero donde se escribe el promedio. Su valor inicial
 * no es relevante.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y legibles.
 * @pre Si 'minimo', 'maximo' y 'promedio' no son NULL, apuntan a variables
 * modificables y distintas entre sí.
 *
 * @post Si retorna true, `*minimo` es el menor, `*maximo` el mayor y
 * `*promedio` la media aritmética de los primeros 'cantidad' elementos de
 * 'arreglo'.
 * @post Si retorna false, `*minimo`, `*maximo` y `*promedio` no se modifican.
 * @post El contenido de 'arreglo' no se modifica.
 *
 * @return true si pudo calcular las tres estadísticas; false si 'arreglo' es
 * NULL, 'cantidad' es 0, o 'minimo', 'maximo' o 'promedio' es NULL.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);


/**
 * @brief Cuenta cuántos elementos de un arreglo pertenecen a un intervalo
 * cerrado.
 *
 * Recorre el arreglo exclusivamente con aritmética de punteros (sin `[]`).
 *
 * @param[in]  arreglo       Arreglo de enteros a analizar (solo lectura).
 * @param[in]  cantidad      Cantidad de elementos del arreglo a considerar.
 * @param[in]  limite_inf    Extremo inferior del intervalo (incluido).
 * @param[in]  limite_sup    Extremo superior del intervalo (incluido).
 * @param[out] coincidencias Puntero donde se escribe la cantidad de elementos
 * dentro del intervalo. Su valor inicial no es relevante.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y legibles.
 * @pre Si 'coincidencias' no es NULL, apunta a un `size_t` modificable.
 *
 * @post Si retorna true, `*coincidencias` es la cantidad de elementos 'x' de
 * los primeros 'cantidad' de 'arreglo' tales que
 * `limite_inf <= x <= limite_sup`.
 * @post Si 'limite_inf' es mayor que 'limite_sup', el intervalo es vacío y
 * `*coincidencias` es 0.
 * @post Si 'cantidad' es 0, `*coincidencias` es 0.
 * @post Si retorna false, `*coincidencias` no se modifica.
 * @post El contenido de 'arreglo' no se modifica.
 *
 * @return true si pudo contar; false si 'arreglo' o 'coincidencias' es NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
