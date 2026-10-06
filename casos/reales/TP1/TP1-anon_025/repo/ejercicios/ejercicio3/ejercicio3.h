

#ifndef EJERCICIO3_H
#define EJERCICIO3_H

/**
*Calcula el factorial de un numero entero
*Para 0, el factorial es 1
*
* @param numero El numero entero a calcular.
*
* @return El factorial del numero o -1 si el numero es negativo
*/

long long factorial(int numero);

/**
* Calcual la cantidad de vombinaciones posibles
*
* @param cantidad_elementos EL numero total de elementos disponibles
*
* @param elementos_por_grupo EL tamaño de los grupos a formar
*
* @return El numero combinatorio, o -1 si es invalido
*/

long long combinatorio(int cantidad_elementos, int elementos_grupos);

#endif