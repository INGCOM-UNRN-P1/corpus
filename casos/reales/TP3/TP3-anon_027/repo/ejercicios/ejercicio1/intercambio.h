#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


 


 
 /** 
 * @brief recibe dos punteros a entero y asegura que la posición 
 *        apuntada por 'menor' contenga un valor menor o
 *        igual que la apuntada por 'mayor'.
 *
 * @param menor puntero que contiene un valor menor a 'mayor'
 * @param mayor puntero que contiene un valor mayor a 'menor'
 * 
 * @pre Debe apoyarse obligatoriamente en la función intercambiar(..) 
 * de libpunteros.
 * 
 * @return --------------------------
 *
 * @post el resultado tiene que ser lo mismo que decir *menor <= *mayor
 *
 * @invariant -----------------------
*/
void ordenar_par(int *menor, int *mayor);







 /** 
 * @brief Recibe tres punteros a entero y ordena los tres valores
 *  de modo que queden ordenados ascendentemente.
 *
 * @param a primer puntero a ordenar.
 * @param b segundo puntero a ordenar.
 * @param c tercer puntero a ordenar.
 * 
 * @pre  Debe resolverse mediante llamadas sucesivas a ordenar_par 
 *       e intercambiar. Si alguno de los tres punteros es NULL, 
 *       no produce efecto.
 * 
 * @return ------------------------------
 *
 * @post el resultado tiene que ser lo mismo que: *a <= *b <= *c
 *
 * @invariant ---------------------------
*/
void ordenar_tria(int *a, int *b, int *c);





 /** 
 * @brief recibe un arreglo de enteros y un puntero de salida.  
 *        Calcula la suma acumulada de los elementos recorriéndolos 
 *        estrictamente con aritmética de punteros y almacena el total 
 *        en la dirección apuntada por 'resultado'.
 *
 * @param arreglo   arreglo a ser recorrido y calculado.
 * @param cantidad  define la cantidad de elementos de 'arreglo'.
 * @param resultado puntero que guarda la sumatoria de elementos 
 *                  de 'arreglo'.
 * 
 * @pre La función no debe producir ningún efecto ni intentar 
 *      desreferenciar memoria si alguno de los punteros es NULL. 
 *      el valor debe preservarse intacto si ambos punteros apuntan 
 *      a la misma dirección de memoria. 
 * 
 * @return 'true' si pudo efectuar el cálculo o 'false' si 'arreglo' 
 * o 'resultado' son NULL.
 *
 * @post el resultado es lo mismo que decir 
 *
 * @invariant 'arreglo'
*/
bool sumar_acumulado(const int *arreglo, size_t cantidad, 
                    long long *resultado);

 #endif 
