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


/** * @brief Calcula y retorna la suma algebraica de todos los elementos del arreglo. 
* 
* @param arreglo Arreglo de enteros a sumar (lectura exclusivamente). 
* @param cantidad Cantidad de elementos válidos en el arreglo. 
* 
* @pre Si cantidad > 0, el arreglo debe buscar a un bloque de memoria válido.
*
* @post El contenido del arreglo permanece inalterado. 
* 
* @return La suma total de los elementos o 0 si el arreglo es NULL o cantidad es 0. 
*/ 

long long arreglo_sumar(const int arreglo[], size_t cantidad);


/** 
* @brief Localiza el índice en base cero de la primera aparición de un valor en el arreglo. 
* 
* @param arreglo Arreglo de enteros en el que se realizará la búsqueda (exclusivamente de lectura). 
* @param cantidad Cantidad de elementos válidos presentes en el arreglo. 
* @param buscado Número entero a localizar. 
* 
* @pre Si cantidad > 0, el puntero 'arreglo' debe apuntar a un bloque de memoria válido. * @post El contenido del arreglo permanece inalterado. 
* 
* @return El índice en base cero de la primera coincidencia, o -1 si el valor no existe, 
* si 'arreglo' es NULL o si 'cantidad' es 0. 
*/ 

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


/** 
* @brief Invierte el orden de los elementos del arreglo directamente sobre su misma memoria (in-place). 
*            Si el arreglo es NULL o cantidad <= 1, la función no realiza ninguna modificación. 
* 
* @param arreglo Arreglo de enteros a invertir (se modifica in-place). 
* @param cantidad Cantidad de elementos válidos presentes en el arreglo. 
* 
* @pre Si cantidad > 0, el arreglo debe buscar  un bloque de memoria válido de al menos 'cantidad' elementos.
*
* @post Los elementos en 'arreglo' quedan ordenados en sentido inverso al original. 
*/ 
void arreglo_invertir(int arreglo[], size_t cantidad);


/** 
* @brief Verifica si los elementos del arreglo se encuentran ordenados de forma ascendente. Se considera orden ascendente cuando arreglo[i] <= arreglo[i + 1] para todo par contiguo. 
* 
* @param arreglo Arreglo de enteros a verificar (lectura exclusivamente). 
* @param cantidad Cantidad de elementos válidos presentes en el arreglo. 
* 
* @pre Si cantidad > 0, el puntero 'arreglo' debe apuntar a un bloque de memoria válido. 
*
* @post El contenido del arreglo permanece inalterado. 
* 
* @return true si el arreglo está ordenado ascendente o si cantidad <= 1 (y arreglo != NULL), 
* false si está desordenado o si 'arreglo' es NULL. 
*/
bool arreglo_ordenado(const int arreglo[], size_t cantidad);


/** 
* @brief Cuenta y retorna la cantidad de veces que aparece un entero buscado en el arreglo. 
* 
* @param arreglo Arreglo de enteros a examinar (exclusivamente de lectura). 
* @param cantidad Cantidad de elementos válidos presentes en el arreglo. 
* @param buscado Número entero cuya frecuencia se desea contabilizar. 
* 
* @pre Si cantidad > 0, el arreglo debe buscar a un bloque de memoria válido.
*
* @post El contenido del arreglo permanece inalterado. 
* 
* @return La cantidad de ocurrencias del valor buscado (size_t), 
* o 0 si el valor no aparece, si 'arreglo' es NULL o si 'cantidad' es 0. 
*/

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);


/** 
* @brief Elimina in-place todas las apariciones de un valor, compactando el arreglo.  Desplaza los elementos restantes hacia el inicio conservando su orden relativo 
* original y sin dejar huecos intermediarios. 
* 
* @param arreglo Arreglo de enteros a compactar. 
* @param cantidad Cantidad inicial de elementos válidos en el arreglo. 
* @param valor Número entero que se desea eliminar del arreglo. 
* 
* @pre Si cantidad > 0, el puntero 'arreglo' debe apuntar a un bloque de memoria válido.
*
* @post El arreglo contiene únicamente los elementos distintos a 'valor' preservando su orden. 
* 
* @return La nueva cantidad de elementos válidos (size_t) tras la compactación, 
* o 0 si 'arreglo' es NULL o si todos sus elementos fueron eliminados. 
*/ 

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);


/**
 * @brief Combina los elementos de dos arreglos previamente ordenados de forma ascendente
 * en un arreglo destino, manteniendo el orden ascendente de los elementos.
 * La cantidad de elementos almacenados está limitada por la capacidad del arreglo
 * destino.
 *
 * @param primero Arreglo ordenado ascendentemente que se desea fusionar.
 * @param cantidad_uno Cantidad de elementos del primer arreglo.
 * @param segundo Arreglo ordenado ascendentemente que se desea fusionar.
 * @param cantidad_dos Cantidad de elementos del segundo arreglo.
 * @param destino Arreglo donde se almacenaran los elementos fusionados.
 * @param capacidad Cantidad maxima de elementos que puede almacenar destino.
 *
 * @return Cantidad de elementos almacenados en destino.
 *
 * @pre Si cantidad_uno es mayor que 0, primero debe apuntar a un arreglo
 *      con al menos cantidad_uno elementos validos.
 * @pre Si cantidad_dos es mayor que 0, segundo debe apuntar a un arreglo
 *      con al menos cantidad_dos elementos validos.
 * @pre Los arreglos primero y segundo deben estar ordenados ascendentemente.
 *
 * @post Los elementos copiados a destino quedan ordenados ascendentemente.
 * @post Nunca se almacenan mas de capacidad elementos en destino.
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad);

#endif 