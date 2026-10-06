#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**  
 * @brief obtiene los extremos de un arreglo y calcula el promedio 
 * mediante acumulación con aritmética de punteros pura.
 *
 * @param arreglo   arreglo a ser recorrido y calculado.
 * @param cantidad  define la cantidad de elementos de 'arreglo'.
 * @param minimo    puntero de salida que define el valor mínimo de
 *                  'arreglo'.
 * @param maximo    puntero de salida que define el valor máximo de
 *                  'arreglo'.
 * @param promedio puntero de salida que muestra el promedio de los 
 *                 elementos de 'arreglo'.
 * 
 * @pre Debe apoyarse en la función obtener_min_max(...) provista 
 * por libpunteros. Tampoco se debe utilizar Arreglos de Longitud 
 * Variable o memoria dinámica.
 *    
 * 
 * @return 'true si tuvo éxito', o false si algún puntero es NULL 
 *          o cantidad == 0.
 *
 * @post el resultado final es el promedio de todos los elementos
 * de 'arreglo' y la obtención de su máximo y mínimo.
 *
 * @invariant 'arreglo'.
*/
 bool calcular_estadisticas(const int *arreglo, size_t cantidad, 
 int *minimo, int *maximo, double *promedio);
 



 /** 
 * @brief Recorre el arreglo con aritmética de punteros contando 
 * cuántos elementos pertenecen al intervalo cerrado .
 *
 * @param arreglo   arreglo a ser recorrido y calculado.
 * @param cantidad  define la cantidad de elementos de 'arreglo'.
 * @param limite_inf define el límite inferior del intervalo cerrado.
 * @param limite_sup define el límite superior del intervalo cerrado.
 * @param coincidencias puntero de salida que cuenta cuantos elementos
 * coinciden dentro del intervalo cerrado.
 *
 *  @pre No está permitido utilizar Arreglos de Longitud Variable
 *       y/o memoria dinámica.
 * 
 * @return 'Retorna true si calculó el conteo, o false 
 *          si arreglo o coincidencias son NULL.
 *
 * @post el resultado es lo mismo que decir [limite_inf, limite_sup].
 *
 * @invariant 'arreglo'.
*/
  bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, 
  int limite_sup, size_t *coincidencias);

#endif 
