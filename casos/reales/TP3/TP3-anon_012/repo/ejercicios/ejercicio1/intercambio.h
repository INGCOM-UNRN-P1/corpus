#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



 /** 
* @brief Ordena dos valores enteros por referencia en orden ascendente (*menor <= *mayor). Compara los valores almacenados en 'menor' y 'mayor'. Si el valor en 'menor' 
* es estrictamente mayor que el valor en 'mayor', los intercambia apoyándose 
* obligatoriamente en la función 'intercambiar' de libpunteros. 
* 
* @param menor Puntero a la variable que almacenará el valor menor o igual (lectura/escritura). 
* @param mayor Puntero a la variable que almacenará el valor mayor o igual (lectura/escritura). 
* 
* @pre Si 'menor' != NULL y 'mayor' != NULL, ambos deben apuntar a memoria válida. 
* @post La posición apuntada por 'menor' contendrá un valor menor o igual que la apuntada por 'mayor'. 
*/ 
void ordenar_par(int *menor, int *mayor);

/**
* @brief Ordena tres valores enteros por referencia en orden ascendente (*a <= *b <= *c).
* Si alguno de los tres punteros es NULL, no produce ningún efecto ni modifica memoria.
*
* @param a Puntero a la primera variable entera (lectura/escritura).
* @param b Puntero a la segunda variable entera (lectura/escritura).
* @param c Puntero a la tercera variable entera (lectura/escritura). 
*
* @pre Si 'a', 'b' y 'c' son distintos de NULL, deben apuntar a bloques de memoria válidos. 
* @post Se garantiza que *a <= *b <= *c. 
*/ 
void ordenar_tria(int *a, int *b, int *c);

/** 
* @brief Calcula la suma acumulada de los elementos de un arreglo usando aritmética de punteros. 
* 
* @param arreglo Puntero al primer elemento del arreglo de enteros (lectura exclusivamente). 
* @param cantidad Cantidad de elementos válidos a sumar. 
* @param resultado Puntero a la variable long long donde se escribirá el total (salida). 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a memoria válida. 
* @post Si retorna true, *resultado contendrá la suma total de los elementos.
*
* @return true si se pudo realizar el cálculo con éxito,* false si 'arreglo' o 'resultado' son NULL.
*/ 

/** 
* @brief Calcula la suma acumulada de los elementos de un arreglo usando aritmética de punteros. 
* 
* @param arreglo Puntero al primer elemento del arreglo de enteros (lectura exclusivamente). 
* @param cantidad Cantidad de elementos válidos a sumar. 
* @param resultado Puntero a la variable long long donde se escribirá el total (salida). 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a memoria válida. 
* @post Si retorna true, *resultado contendrá la suma total de los elementos.
*
* @return true si se pudo realizar el cálculo con éxito,* false si 'arreglo' o 'resultado' son NULL.
*/ 
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);
#endif 
