#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>


/** 
 * @brief copia 'cantidad' elementos enteros desde un arreglo origen
 *    hacia un arreglo destino utilizando aritmética de punteros 
 * (punteros origen y destino avanzando con ++).
 *
 * @param origen   arreglo a ser recorrido y copiado.
 * @param cantidad  define la cantidad de elementos de 'arreglo'.
 * @param destino   arreglo destino en donde va a ser destinada dicha
 * copia de elementos desde 'arreglo'.
 *
 * @pre No está permitido utilizar Arreglos de Longitud Variable
 *       y/o memoria dinámica.
 * 
 * @return "true" si hubo éxito o "false" si '*origen' es nulo,
 *  'destino' es nulo o 'cantidad' igual a 0.
 * 
 * @post el resultado es lo mismo que decir 'origen' = 'destino'.
 *
 * @invariant 'arreglo'.
*/
bool copiar_arreglo(const int *origen, size_t cantidad, int *destino);





 /** 
 * @brief invertir_arreglo: invierte in-place un arreglo de enteros 
 * utilizando dos punteros: uno al inicio y otro al final, 
 * convergiendo con inicio++ y fin--.
 *    
 * @param arreglo  arreglo a ser recorrido y calculado.
 * @param cantidad define la cantidad de elementos de 'arreglo'.
 * @param inicio define el 
 * @param fin define el 
 *
 *  @pre utilizar la función de 'intercambio' mediante punteros.
 * 
 * @return "true" si hubo éxito o "false" si 'arreglo' es nulo o
 * 'cantidad' es igual a cero.
 *
 * @post debe retornar 'arreglo' invertido.
 *
 * @invariant 'arreglo'.
*/
bool invertir_arreglo(int *arreglo, size_t cantidad, 
int *inicio, int *fin);
 



#endif 
