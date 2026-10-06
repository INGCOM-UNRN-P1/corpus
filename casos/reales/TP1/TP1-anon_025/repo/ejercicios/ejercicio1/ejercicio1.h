

#ifndef EJERCICIO1_H
#define EJERCICIO1_H

/**
*Verifica si un numero entero es primo.
*
*@param numero El numero entero que tiene que evaluar
*
*@return 1 si es par y 0 si es impar
*/

int es_primo(int numero);

/**
*Busca y retorna el numero menor primo.
*
*@param numero_base El numero donde comienza la busqueda
*
*@return El sigueinte numero primo que se encontro
*/

int proximo_primo(int numero_base);

/**
*Calcula y cuenta la cantidad de divisores que tiene un numero entero
*
*@param numero El numero entero a evaluar
*
*@return La cantidad total de divisores
*/

int cantidad_divisores(int numero);

#endif

