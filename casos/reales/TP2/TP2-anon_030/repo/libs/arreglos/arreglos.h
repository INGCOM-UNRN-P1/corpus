/**
 * @file arreglos.h
 * @brief Biblioteca de manipulacion y procesamiento de arreglos de enteros.
 *
 * Trabajo Practico 2 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Suma todos los elementos de un arreglo.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post El arreglo no es modificado.
 *
 * @return La suma de todos los elementos.
 * @return 0 si el arreglo es NULL o cantidad es 0.
 */
long long arreglo_sumar(
    const int arreglo[],
    size_t cantidad
);




/**
 * @brief Busca la primera aparicion de un numero en el arreglo.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param buscado Numero que se desea buscar.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post El arreglo no es modificado.
 *
 * @return La posicion de la primera aparicion del numero.
 * @return -1 si no se encuentra, el arreglo es NULL o cantidad es 0.
 */
int arreglo_buscar(
    const int arreglo[],
    size_t cantidad,
    int buscado
);




/**
 * @brief Invierte el orden de los elementos de un arreglo.
 *
 * @param arreglo Arreglo que se desea invertir.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post Los elementos quedan almacenados en orden inverso.
 *
 * Si el arreglo es NULL o cantidad es menor o igual a 1,
 * no realiza modificaciones.
 */
void arreglo_invertir(
    int arreglo[],
    size_t cantidad
);




/**
 * @brief Verifica si un arreglo esta ordenado ascendentemente.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post El arreglo no es modificado.
 *
 * @return true si el arreglo esta ordenado.
 * @return true si cantidad es menor o igual a 1.
 * @return false si esta desordenado o el arreglo es NULL.
 */
bool arreglo_ordenado(
    const int arreglo[],
    size_t cantidad
);




/**
 * @brief Cuenta cuantas veces aparece un numero en un arreglo.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param buscado Numero que se desea contar.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post El arreglo no es modificado.
 *
 * @return Cantidad de veces que aparece el numero.
 * @return 0 si el arreglo es NULL o cantidad es 0.
 */
size_t arreglo_contar(
    const int arreglo[],
    size_t cantidad,
    int buscado
);




/**
 * @brief Elimina todas las apariciones de un valor del arreglo.
 *
 * Los elementos restantes se desplazan hacia el inicio
 * manteniendo su orden original.
 *
 * @param arreglo Arreglo de numeros enteros.
 * @param cantidad Cantidad de elementos validos.
 * @param valor Numero que se desea eliminar.
 *
 * @pre El arreglo debe contener la cantidad de elementos indicada.
 * @post Los elementos distintos de valor quedan compactados al inicio.
 *
 * @return La nueva cantidad de elementos validos.
 * @return 0 si el arreglo es NULL o cantidad es 0.
 */
size_t arreglo_compactar(
    int arreglo[],
    size_t cantidad,
    int valor
);

#endif 