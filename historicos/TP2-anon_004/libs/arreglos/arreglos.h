/**
 * @file arreglos.h
 * @brief Biblioteca de manipulación y procesamiento de arreglos de enteros (int).
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - Todo arreglo viene acompañado por su cantidad de elementos válidos (size_t cantidad).
 * - Arreglos de solo lectura (const int arreglo[]) para funciones que no modifican datos.
 * - Arreglos mutables (int arreglo[]) para funciones que modifican contenido in-place.
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>


long long arreglo_sumar(const int arreglo[], size_t cantidad);


int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


void arreglo_invertir(int arreglo[], size_t cantidad);


bool arreglo_ordenado(const int arreglo[], size_t cantidad);


size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);





#endif 
