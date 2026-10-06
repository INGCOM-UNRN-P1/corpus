

#ifndef EJERCICIO2_H
#define EJERCICIO2_H

/**
 * Calcula el valor de n de la sucesion de fibonacci.
 * utiliza un enfoque en donde los casos base son f(0)=0 y f(1)=1
 * 
 * @param n el indice del termino que tiene que calcular
 * 
 * @return el valor de la posicion n, o -1 si ingresaron un numero negativo
 */

int fibonacci(int n);

/**
 * Calcula la suma de todos los terminos de fibonacci.
 * desde 0 hasta la posicion n
 * 
 * @param n El indice del termino limite hasta donde se realiza la suma
 * 
 * @return la suma total acumulada o -1 si ingresaron un numero negativo
 */

int suma_fibonacci(int n);

#endif