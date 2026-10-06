

#ifndef EJERCICIO5_H
#define EJERCICIO5_H

/**
* Retorna la cantidad de digitos decimales de un numero
* El numero 0 tinee 1 digito
*
* @param numero EL numero entero a evaluar
*
* @return La cantidad de digitos
 */
 int contar_digitos(int numero);

 /**
 * Retorna la suma de los valores absolutos
 * 
 * @param numero El numero entero a evaluar
 *
  @return La suma de los digitos
*/
int sumar_digitos(int numero);

/**
* Invierte el orden de los digitos
*
* @param numero El numero que invierte
*
* @return El numero con sus digitos invertidos
*/
int invertir_numero(int numero);

/**
* Retorna 1 si el numero se lee igual de derecha a ezquierda
* y de izquierda a derecha 
*
* @param numero EL numero entero a evaluar
*
* @return 1 si es capicua, 0 si no es
*/
int es_capicua(int numero);

#endif 