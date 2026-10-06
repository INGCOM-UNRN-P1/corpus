/**
 * @file arreglos.h
 * @brief Biblioteca de manipulación y procesamiento de arreglos
 *  de enteros (int).
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos,
 *  de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - Todo arreglo viene acompañado por su cantidad de
 *  elementos válidos (size_t cantidad).
 * - Arreglos de solo lectura (const int arreglo[]) 
 * para funciones que no modifican datos.
 * - Arreglos mutables (int arreglo[]) para funciones
 *  que modifican contenido in-place.
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Se calcula la suma algebraica de todos los elementos
 *  enteros del arreglo.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede ser 0.
 * @post Devuelve la suma acumulada de los elementos een el rango
 * [0, cantidad -1]
 * @param arreglo Es el arreglo.
 * @param cantidad Es la cantidad de elementos del arreglo.
 * @return Se devuelve la suma obtenida de los elementos del arreglo.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);


/**
 * @brief Se busca un valor determinado por el usuario, recorriendo la cadena,
 * si se encuentra se retorna la posicion donde se encontro dicha coincidencia. 
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede ser 0.
 * @post devuelve el indicede la primera aparicion del numero
 * entero buscado en el arreglo.
 * @param arreglo Es el arreglo que se utilizara para buscar la coincidencia.
 * @param cantidad Es la cantidad de elementos del arreglo.
 * @param buscado Es el numero que se busca en el arreglo
 * @return Si no se encuentra el numero, se retorna -1,
 * sino se devuelve la posicion en la que se encontro dicha coincidencia.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief invierte el orden de los elementos del arreglo, in place,
 * es decir se guarda el valor viejo en una variable y
 * se va reemplazando secuencialmente, intercambiando los extremos del arreglo
 * (de afuera hacia adentro), de manera simetrica, es decir, la ultima con la
 * primera, la segunda con la ante ultima, y asi suceesivamente,
 * hasta alcanzar cantidad/2.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede menor ser a 2.
 * @post invierte el orden de los elementos del arreglo.
 * @param arreglo Es el arreglo original (a invertir)
 * @param cantidad es la cantidad de los elemenetos del arreglo.
 * @param auxiliar Es la variable temporal que guarda el valor de una
 * posicion antes de reemplazar.
 * @return se de3evuelve un nuevo arreglo, que es un "espejo" del anterior
 * (porque sus elementos fueron invertidos).
 */
void arreglo_invertir(int arreglo[], size_t cantidad);


/**
 * @brief Se verifica que el arreglo este ordenado de manera ascendente o no.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' si la cantidad es menor o igual a 1 el
 * arreglo ya estara ordenado.
 * @post verifica que el arreglo este ordenado.
 * @param arreglo Es el arreglo.
 * @param cantidad es la cantidad de los elemenetos del arreglo.
 * @return 'false' si no esta ordenado, 'true' si el arreglo esta ordenado.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);


/**
 * @brief Se recorre el arreglo para saber cuentas veces aparece
 * un valor buscado.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede ser 0.
 * @post cuantas veces aparece el valor buscado en el arreglo.
 * @param arreglo Es el arreglo.
 * @param cantidad es la cantidad de los elemenetos del arreglo.
 * @param buscado es el valor que se busca saber su cantidad de
 * apariciones en el arreglo.
 * @param contador es en donde se guarda la cantida de veces que
 * aparece 'buscado' en el arreglo.
 * @return devuelve la cantidad de veces que aparece 'buscado' en el arreglo.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief busca un valor del arreglo y se eliminan todas
 * sus apariciones en el arreglo.
 * @pre 'arreglo' no puede ser NULL.
 * @pre 'cantidad' no puede ser 0.
 * @post eliminar todas las apariciones de 'valor' en el arreglo. 
 * @param arreglo Es el arreglo.
 * @param cantidad Es la cantidad de los elemenetos del arreglo.
 * @param valor Es el numero a eliminar del arreglo. 
 * @return devuelve un nuevo arreglo sin 'valor'.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);


/**
 * @brief se fusionan dos arreglos apra generar uno nuevo,
 * a partir de los otros dos.
 * @pre 'primero' no puede ser NULL.
 * @pre 'segundo' no puede ser NULL.
 * @pre 'cantidad_uno' no puede ser 0.
 * @pre 'cantidad_dos' no puede ser 0.
 * @post concatenar o fusionar ambos arreglos en uno nuevo
 * ordenados de manera ascedente.
 * @param primero Es el primer arreglo.
 * @param cantidad_uno Es la cantidad de los elemenetos del arreglo primero. 
 * @param segundo Es el segundo arreglo.
 * @param cantidad_dos Es la cantidad de los elemenetos del arreglo segundo.
 * @param destino Es el nuevo arreglo resultante de la fusion de los otros 2.
 * @param capacidad Es la capacidad disponible del arreglo destino.
 * @return La cantidad de elementos correctamente copiados en 'destino'
 * o 0 si algún arreglo es NULL o la capacidad es 0.
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno,
    const int segundo[], size_t cantidad_dos, int destino[],
    size_t capacidad);
#endif 
