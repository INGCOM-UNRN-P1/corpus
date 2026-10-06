#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca la primera aparicion de un valor en un arreglo retornando el puntero a dicho elemento.
 *
 * @pre arreglo apunta a una secuencia contigua de al menos cantidad enteros.
 * @post Retorna el puntero directo al primer elemento coincidente, o NULL si no existe o ante parametros invalidos.
 *
 * @param arreglo Puntero de solo lectura al inicio del arreglo.
 * @param cantidad Cantidad de elementos del arreglo a inspeccionar.
 * @param buscado Valor entero a localizar.
 *
 * @return const int* Puntero al elemento encontrado dentro del arreglo, o NULL si no se encontro.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado);

/**
 * @brief Calcula el indice relativo de un elemento respecto al inicio mediante resta de punteros.
 *
 * @pre inicio y elemento pertenecen al mismo bloque contiguo de memoria y elemento >= inicio.
 * @post Almacena la distancia en *distancia y retorna true; retorna false ante punteros nulos o elemento anterior a inicio.
 *
 * @param inicio Puntero de solo lectura a la direccion base.
 * @param elemento Puntero de solo lectura al elemento objetivo.
 * @param distancia Puntero de salida donde se guardara el desplazamiento (elemento - inicio).
 *
 * @return bool true si se pudo calcular la distancia, false en caso contrario.
 */
bool distancia_punteros(const int *inicio, const int *elemento, size_t *distancia);

#endif 
