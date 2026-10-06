

#ifndef EJERCICIO2_H
#define EJERCICIO2_H

/**
 * Función que calcula un término de la serie de fibonacci
 * @param posicion es el numero del término de la serie
 * @return el término
 * @pre posicion >= 0
 */
 int fibonacci(int posicion);

 /**
 * Función que calcula la suma acumulada de los términos de la serie
 * de Fibonacci hasta una posición dada
 * @param hasta_posicion es el numero del término de la serie
 * @return la suma de los términos hasta ese número
 * @pre hasta_posicion >= 0
 */
 int suma_fibonacci(int hasta_posicion);
#endif
