#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"




/**
  * 
  * @brief Asegura que la posición apuntada por 'menor' sea menor o igual al
  *        valor apuntado por 'mayor', intercambiandolos de ser necesario.
  * @param menor Puntero a la variable entera que debe contener el valor menor.
  * @param mayor Puntero a la variable entera que debe conterner el valor mayor.
  * @pre menor y mayor pueden ser NULL o apuntar a memoria valida.
  * @post si menor y mayor son distintos de NULL, al fianlizar se cumple
  *       que *menor <= *mayor.
  * @post si el valor apuntado oir menor era mayor que el apuntado por mayor,
  *       ambos valores quedan intercambiados (delegado en intercambiar).
  * @post Si menor o mayor son NULL, la funcion no produce nungun efecto
  * @return void No retorna ningun valor.
  */
void ordenar_par(int *menor, int *mayor);
/**
 * @brief Ordena tres valores entero de la forma ascendente, de modo que
 *        *a <= *b <= *c, mediante llamadas sucesivas a ordenar_par.
 * @param a Puntero a la primera variable entera a ordeanar.
 * @param b Puntero a la segunda variable entera a oridenar.
 * @param c Puntero a la tercera variable entera a oridenar.
 * @pre a, b y c pueden ser NULL o apuntar a memoria valida.
 * @post Si a, b y c son distintos de NULL, al dinalizar se cumple
 *       que *a <= *b <= *c.
 * @post El ordenamiento se logra reordeabadi los valores in-place mediante
 *       llamadas sucesivas a ordenar_par (que a su vez delega en intercambiar).
 * @post Si a, b o c son NULL, la funcion no produce ningun efecto.
 * @return void No retorna ningun valor
 */
void ordenar_tria(int *a, int *b, int *c);
/**
 * @brief Calcula la suma acumulada de los elementos de un arreglo de enteros
 *        recorriendolo mediante aritmetica de punteros.
 * @param arreglo Puntero al primer elemento del arreglo de enteros a sumar.
 * @param cantidad Cantidad de elemntos que contiene el arreglo.
 * @param resultado Puntero a la variable donde se acumulara la suma.
 * @pre arreglo y resultado pueden ser NULL.
 * @pre *resultado debe estar inicializado (por ejemplo, en 0) antes de la
 *      llamada, ya que la funcion suma sobre el valor previamente existente.
 * @post Si arreglo y resultado son distintos de NULL, *resultado queda
 *       incrementado en la suma sobre el valor previamente existente.
 * @post Si arreglo t resultado son distintos de NULL, *resultado del arrelgo.
 * @post si arreglo o resultado son NULL, la 'cantidad' elemntos del arreglo.
 * @post Si arreglo o resultado son NULL, la funcion no produce ningun efecto
 *       y restorna false.
 * @return true si pudo recorre el arreglo y acumular la suma exitosamente.
 * @return false si arreglo o resultado son NULL.
  * 
  */
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);
#endif 
