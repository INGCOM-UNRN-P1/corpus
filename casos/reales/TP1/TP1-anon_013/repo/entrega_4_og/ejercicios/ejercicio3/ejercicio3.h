

#ifndef EJERCICIO3_H
#define EJERCICIO3_H

/**
 * Calcula el factorial de un número entero de forma iterativa
 * @param numero al cual se le calcula el factorial
 * @return el resultado del cálculo
 * @pre numero >= 0
 */
long long factorial(int numero);

/**
 * Calcula las combinaciones de un grupo tomado
 * de a cierta cantidad de elementos
 * @param cantidad_elementos es el numero de elementos del conjunto
 * @param elementos_por_grupo es el subconjunto de elementos
 * @return la cantidad de combinaciones posibles
 * @pre elementos_por_grupo >= 0, cantidad_elementos >= 0, elementos_por_grupo < cantidad_elementos
 */
long long combinatorio(int cantidad_elementos, int elementos_por_grupo);
#endif
