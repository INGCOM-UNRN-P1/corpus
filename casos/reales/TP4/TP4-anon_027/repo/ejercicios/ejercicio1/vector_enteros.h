#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"


/**
 * @brief recibe const int *origen y size_t cantidad.
 * Reserva memoria dinámica en el heap mediante malloc/calloc y copia 
 * los elementos de 'origen'.
 *
 * @param origen puntero que hace referencia a un arreglo entero
 * a ser copiado en otra memoria dinámica.
 * 
 * @param cantidad asigna una cantidad de elementos a 'origen'
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free`.
 * 
 * @return el nuevo puntero int*, o NULL si 'origen' es
 *    NULL, 'cantidad' es 0 o falla la memoria.
 *
 * @post el resultado debe ser una nueva memoria dinámica con el
 * contenido copiado de 'origen'.
 *
 * @invariant 'origen'
*/
 int *clonar_arreglo_enteros(const int *origen, size_t cantidad);
  




 /** 
 * @brief recibe const int *origen, size_t cantidad_origen,
 * y un puntero de salida size_t *cantidad_pares.
 * Cuenta cuántos números pares existen, reserva en el heap 
 * la cantidad exacta necesaria de enteros, copia los pares y 
 * actualiza *cantidad_pares.
 *
 * @param origen puntero que apunta a un arreglo a ser examinado.
 * @param cantidad_origen define la capacidad máxima de 'origen'
 * @param cantidad_pares puntero que apunta a una memoria que 
 * reserva la cantidad de numeros pares de 'origen'.
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free`.
 * 
 * @return el puntero al nuevo bloque en heap, o NULL si no 
 * hay pares o ante error.
 *
 * @post debe retornar la cantidad de pares hallados en 'origen'
 * (si es que los hay).
 *
 * @invariant 'origen'
*/
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
