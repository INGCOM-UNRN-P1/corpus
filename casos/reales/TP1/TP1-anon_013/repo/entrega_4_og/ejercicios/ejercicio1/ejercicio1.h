

#ifndef EJERCICIO1_H
#define EJERCICIO1_H
/**
 * Función que determina si un número dado es primo
 * @param numero es el número a determinar si es primo
 * @return 1 si es primo, 0 si no es primo
 */
int es_primo(int numero);

/**
 * Función que determina el próximo primo de un número
 * @param numero es el número a partir del cual se determina el próximo primo
 * @return el próximo número primo
 */
int proximo_primo(int numero_base);

/**
 * Función que determina la cantidad de divisores positivos de un número dado
 * @param numero es al que se le determinan la cantidad de divisores
 * @return la cantidad de divisores
 */
int cantidad_divisores(int numero);
#endif