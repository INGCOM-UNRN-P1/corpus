

#ifndef EJERCICIO8_H
#define EJERCICIO8_H
/**
 * Función que calcula la suma de los divisores de un número
 * @param numero es el número
 * @return la suma de sus divisores
 * @pre numero > 0
 */
int suma_divisores_propios(int numero);

/**
 * Función que clasifica un número en perfecto, deficiente o abundante
 * dependiendo del resultado de la suma de sus divisores
 * @param numero es el número
 * @return 1 si es perfecto (suma == numero),
 * 0 si es deficiente (suma < numero),
 * 2 si es abundante (suma > numero)
 * @pre numero > 0
 */
int clasificar_numero(int numero);
#endif