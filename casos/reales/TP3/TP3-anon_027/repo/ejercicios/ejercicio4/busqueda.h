#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

   
 /** 
 * @brief busca la primera aparición de un valor en un arreglo de enteros
     recorriéndolo con aritmética de punteros.
 *
 * @param arreglo  arreglo a ser buscado.
 * @param capacidad define la capacidad del arreglo.  
 * @param valor valor a ser buscado en 'arreglo'.
 *
 *  @pre No está permitido utilizar Arreglos de Longitud Variable
 *       y/o memoria dinámica.
 * 
 * @return un puntero constante a la posición exacta en memoria
   donde se encuentra el elemento; o NULL si no existe o ante 
   parámetros inválidos.
 *
 * @post el resultado debe ser la obtencion del valor buscado dentro
 * de 'arreglo'.
 *
 * @invariant 'arreglo'.
*/
const int *buscar_primero(const int *arreglo,size_t capacidad, int valor);
  
 
  
 
/** 
 * @brief función utilitaria que recibe el puntero al inicio del
 * arreglo y un puntero a un elemento interno (obtenido por ejemplo 
 * mediante buscar_primero), y calcula su índice o distancia 
 * relativa mediante la resta de punteros (p - inicio). 
 *
 * @param p puntero que indica donde se encuentra 'valor' en el 
 * arreglo de la funcion 'buscar_primero'.
 * @param inicio puntero que indica el comienzo de 'arreglo'.
 *
 *  @pre No está permitido utilizar Arreglos de Longitud Variable
 *       y/o memoria dinámica.
 * 
 * @return -1 Si alguno es NULL o el elemento está antes del inicio.
 *
 * @post el resultado es la resta de punteros (p - inicio).
 *
 * @invariant 'arreglo'.
*/
int distancia_punteros(const int *p,const int *inicio);

#endif 
