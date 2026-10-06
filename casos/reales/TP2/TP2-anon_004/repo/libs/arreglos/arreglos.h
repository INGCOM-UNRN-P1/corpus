/**
 * @file arreglos.h
 * @brief Biblioteca de manipulación y procesamiento de arreglos de enteros (int).
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - Todo arreglo viene acompañado por su cantidad de elementos válidos (size_t cantidad).
 * - Arreglos de solo lectura (const int arreglo[]) para funciones que no modifican datos.
 * - Arreglos mutables (int arreglo[]) para funciones que modifican contenido in-place.
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>



 /**
  * @brief  Calcula la suma algebraica de los elementos de un arreglo de enteros.
  * 
  * @pre arreglo contiene al menos la misma cantidad elementos que el valor de cantidad (o es NULL si cantidad es 0).
  * @post Retorna la suma de todos los elementos de arreglo. Si arreglo == NULL o cantidad == 0 se retorna 0
  * 
  * @param arreglo Arreglo de enteros de solo lectura a procesar.
  * @param cantidad Cantidad de elementos validos en el arreglo.
  * 
  * @return long long Suma total de los elementos, o 0LL si el arreglo es nulo o vacio.
  */
long long arreglo_sumar(const int arreglo[], size_t cantidad);



 /**
  * @brief Localiza la posicion de la primera aparicion de un numero entero dentro de un arreglo.
  *
  * @pre arreglo contiene al menos la misma cantidad de elementos que el valor de cantidad (o es NULL si cantidad es 0).
  * @post Retorna el indice de la primera aparicion de buscado en el arreglo, o -1 si no existe, si el arreglo es nulo o si la cantidad es 0.
  *
  * @param arreglo Arreglo de enteros de solo lectura a inspeccionar.
  * @param cantidad Cantidad de elementos validos a procesar en el arreglo.
  * @param buscado Valor entero que se desea localizar dentro del arreglo.
  * @return int Indice en base cero de la primera aparicion de buscado, o -1 si no se encuentra, si el arreglo es NULL o si cantidad es 0.
  */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);



 /**
 * @brief Invierte el orden de los elementos de un arreglo utilizando su misma ubicación en memoria.
 * 
 * @pre arreglo contiene al menos la misma cantidad de elementos que el valor de cantidad (o es NULL si cantidad es 0).
 * @post Se obtiene el orden invertido de los elementos contenidos en el arreglo. Si el arreglo es nulo o la cantidad es menor o igual a 1 no se efectuara ninguna modificacion.
 * 
 * @param arreglo Arreglo de enteros a modificar directamente en memoria (in-place).
 * @param cantidad Cantidad de elementos validos a procesar en el arreglo.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);



/**
 * @brief Verifica si los elementos del arreglo se encuentran ordenados de forma ascendente.
 * 
 * @pre arreglo contiene al menos la misma cantidad de elementos que el valor de cantidad (o es NULL si cantidad es 0).
 * @post Retorna true si los elementos contiguos cumplen arreglo[i] <= arreglo[i + 1] o si cantidad <= 1; false si estan desordenados o el arreglo es NULL.
 * 
 * @param arreglo Arreglo de enteros de solo lectura a inspeccionar.
 * @param cantidad Cantidad de elementos validos a procesar en el arreglo.
 * 
 * @return bool true si el arreglo esta ordenado o tiene 1 o menos elementos; false si esta desordenado o si arreglo es NULL.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);



/**
 * @brief Cuenta la cantidad de apariciones de un numero entero dentro de un arreglo.
 * 
 * @pre arreglo contiene al menos la misma cantidad de elementos que el valor de cantidad (o es NULL si cantidad es 0).
 * @post Devuelve la cantidad de veces que se encuenta el valor buscado en el arreglo, o 0 si es arreglo es nulo o si cantidad es 0.
 * 
 * @param arreglo Arreglo de enteros de solo lectura a inspeccionar.
 * @param cantidad Cantidad de elementos validos a procesar en el arreglo.
 * @param buscado Valor entero que se desea contabilizar dentro del arreglo.
 * 
 * @return site_t Cantidad de ocurrencias del valor buscado.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);



/**
 * @brief Elimina in-place todas las apariciones de un valor entero y compacta los elementos restantes. Desplaza los elementos no eliminados hacia el inicio del arreglo sin dejar huecos y preservando su orden relativo original.
 * 
 * @pre arreglo contiene al menos la misma cantidad de elementos que el valor de cantidad (o es NULL si cantidad es 0).
 * @post Modifica el arreglo in-place reubicando los elementos distintos de valor al inicio. Retorna la nueva cantidad de elementos validos, o 0 si el arreglo es NULL o cantidad es 0.
 * 
 * @param arreglo Arreglo de enteros a modificar directamente en memoria (in-place).
 * @param cantidad Cantidad de elementos validos iniciales en el arreglo.
 * @param valor Valor entero que se desea remover del arreglo.
 * 
 * @return size_t Nueva cantidad de elementos validos que contiene el arreglo compactado.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);



 /**
 * @brief Fusiona dos arreglos ordenados ascendentemente en un tercer arreglo destino. Combina los elementos de ambos arreglos manteniendo el orden relativo ascendente hasta agotar los elementos disponibles o alcanzar la capacidad máxima del destino.
 *
 * @pre primero y segundo apuntan a bloques de memoria válidos de al menos cantidad_uno y cantidad_dos elementos respectivamente (o son NULL si sus cantidades son 0).
 * @pre Los arreglos primero y segundo se encuentran ordenados ascendentemente.
 * @pre destino apunta a un bloque de memoria con espacio para al menos capacidad elementos (o es NULL si capacidad es 0).
 * @post Escribe en destino la intercalación ordenada de primero y segundo sin superar capacidad. Retorna la cantidad total de elementos volcados, o 0 si destino es NULL o capacidad es 0.
 *
 * @param primero       Primer arreglo ordenado de entrada.
 * @param cantidad_uno  Cantidad de elementos válidos en el primer arreglo.
 * @param segundo       Segundo arreglo ordenado de entrada.
 * @param cantidad_dos  Cantidad de elementos válidos en el segundo arreglo.
 * @param destino       Arreglo de salida donde se almacenan los elementos combinados.
 * @param capacidad     Capacidad máxima de elementos que puede alojar el arreglo destino.
 *
 * @return size_t Cantidad total de elementos efectivamente escritos en destino.
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno,
                        const int segundo[], size_t cantidad_dos,
                        int destino[], size_t capacidad);

#endif 
