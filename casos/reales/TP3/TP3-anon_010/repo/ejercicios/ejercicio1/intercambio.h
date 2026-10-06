#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



 /**
 * @brief Ordena un par de enteros de modo que el primero no sea mayor que el
 * segundo.
 *
 * @param[in, out] menor Puntero al primer entero. Al terminar contiene el
 * menor de los dos valores.
 * @param[in, out] mayor Puntero al segundo entero. Al terminar contiene el
 * mayor de los dos valores.
 *
 * @pre Si 'menor' y 'mayor' no son NULL, apuntan a enteros válidos y
 * modificables.
 * @pre 'menor' y 'mayor' pueden apuntar a la misma dirección.
 *
 * @post Si ambos punteros son no nulos, `*menor <= *mayor`.
 * @post Los valores finales son una permutación de los originales: no se
 * introducen valores nuevos ni se modifica otra posición de memoria.
 * @post Si alguno de los punteros es NULL, no se accede a memoria y no se
 * modifica nada.
 */
void ordenar_par(int *menor, int *mayor);


/**
 * @brief Ordena tres enteros de forma ascendente.
 *
 * @param[in, out] a Puntero al primer entero. Al terminar contiene el menor.
 * @param[in, out] b Puntero al segundo entero. Al terminar contiene el valor
 * intermedio.
 * @param[in, out] c Puntero al tercer entero. Al terminar contiene el mayor.
 *
 * @pre Si 'a', 'b' y 'c' no son NULL, apuntan a enteros válidos y
 * modificables.
 *
 * @post Si los tres punteros son no nulos, `*a <= *b <= *c`.
 * @post Los valores finales son una permutación de los originales: no se
 * introducen valores nuevos ni se modifica otra posición de memoria.
 * @post Si alguno de los tres punteros es NULL, no se accede a memoria y no
 * se modifica nada.
 */
void ordenar_tria(int *a, int *b, int *c);


/**
 * @brief Calcula la suma de los elementos de un arreglo de enteros.
 *
 * Recorre el arreglo exclusivamente con aritmética de punteros (sin `[]`).
 *
 * @param[in]  arreglo   Arreglo de enteros a sumar (solo lectura).
 * @param[in]  cantidad  Cantidad de elementos del arreglo a sumar.
 * @param[out] resultado Puntero donde se escribe la suma. Su valor inicial no
 * es relevante.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y legibles.
 * @pre Si 'resultado' no es NULL, apunta a un `long long` modificable.
 * @pre La suma de los elementos es representable en un `long long`.
 *
 * @post Si retorna true, `*resultado` es la suma de los primeros 'cantidad'
 * elementos de 'arreglo' (0 si 'cantidad' es 0).
 * @post Si retorna false, `*resultado` no se modifica.
 * @post El contenido de 'arreglo' no se modifica.
 *
 * @return true si guardó la suma en 'resultado'; false si 'arreglo' o
 * 'resultado' es NULL.
 */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);


#endif 
