#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * =========================================================================
 * Ejercicio 6: Ordenamiento por Selección con Aritmética de Punteros
 * =========================================================================
 * Busca la posición del valor minimo dentro de un rango de memoria.
 *
 * @param inicio del primer elemento del rango a evaluar.
 * @param fin del ultimo elemento (inclusive) del rango a evaluar.
 * @pre inicio y fin deben pertenecer al mismo bloque de memoria.
 * @post La memoria evaluada en el rango no sufre ninguna modificacion.
 * @returns Puntero constante al elemento con el valor minimo encontrado.
 *          Retorna NULL si inicio o fin son nulos, o si inicio apunta a
 *          una posicion posterior a fin.
*/
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * Ordena de forma ascendente los elementos de un arreglo mediante selección.
 *
 * @param arreglo puntero al primer elemento de la coleccion a ordenar.
 * @param cantidad de enteros presentes dentro del contenedor.
 * @pre El puntero arreglo debe apuntar a una secuencia valida de al menos
 *      'cantidad' de elementos.
 * @post El contenido de la coleccion queda totalmente reordenado en forma
 *       ascendente en su misma posicion de memoria (in-place).
*/
void ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
