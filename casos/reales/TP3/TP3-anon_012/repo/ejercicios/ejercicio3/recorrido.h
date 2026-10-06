#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>



 /** 
* @brief Copia los elementos de un arreglo origen hacia un arreglo destino con aritmética de punteros. 
* Transfiere 'cantidad' enteros elemento a elemento incrementando directamente los punteros 
* origen y destino. Si 'destino' u 'origen' son NULL, no realiza ninguna copia y retorna false. 
* 
* @param destino Puntero al bloque de memoria donde se escribirán los datos (salida). 
* @param origen Puntero al arreglo fuente desde el cual se leerán los datos (lectura exclusivamente). 
* @param cantidad Cantidad de elementos enteros a copiar. 
* 
* @pre Si 'cantidad' > 0, tanto 'destino' como 'origen' deben apuntar a bloques válidos de memoria. 
* @post 'destino' contendrá una copia exacta de los primeros 'cantidad' elementos de 'origen'. 
* 
* @return true si la copia se completó con éxito, * false si 'destino' u 'origen' son NULL. 
*/ 
bool copiar_arreglo(int *destino, const int *origen, size_t cantidad);

/** 
* @brief Invierte in-place el orden de los elementos de un arreglo de enteros. 
* El intercambio de elementos se realiza en la función 'intercambiar' de libpunteros. 
* 
* @param arreglo Puntero al primer elemento del arreglo a invertir (lectura y escritura). 
* @param cantidad Cantidad de elementos del arreglo. 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a memoria válida. 
* @post Los elementos del arreglo quedan ordenados en sentido inverso respecto a su estado original. 
* 
* @return true si la operación se ejecutó (o si cantidad <= 1), 
* false si 'arreglo' es NULL. */

bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
