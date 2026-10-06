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
 * @brief Calcula la suma algebraica de todos los elementos enteros de un arreglo.
 * 
 * Emplea un tipo de retorno 'long long' para prevenir desbordamientos aritméticos.
 * Si el arreglo es nulo o la cantidad es 0, retorna 0.
 * 
 * @pre 'arreglo' es un puntero válido o NULL.
 * @post Retorna la suma total de los elementos.
 * 
 * @param arreglo Puntero al arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos válidos que contiene el arreglo.
 * @return long long Resultado de la suma algebraica de los elementos.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);



/**
 * @brief Localiza el índice de la primera aparición de un valor entero en el arreglo.
 * 
 * Realiza una búsqueda secuencial buscando el elemento indicado.
 * 
 * @pre 'arreglo' es un puntero válido o NULL.
 * @post Retorna el índice en base cero o -1 si no se encuentra.
 * 
 * @param arreglo Puntero al arreglo donde se realizará la búsqueda.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param buscado Valor entero que se desea localizar.
 * @return int Índice de la primera coincidencia, o -1 si no existe o hay argumentos inválidos.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);



/**
 * @brief Invierte el orden de los elementos de un arreglo directamente sobre su memoria.
 * 
 * Intercambia los extremos simétricos in-place.
 * Si el arreglo es nulo o la cantidad es menor o igual a 1, no realiza modificaciones.
 * 
 * @pre 'arreglo' es un búfer modificable válido.
 * @post Los elementos del arreglo quedan ordenados en sentido inverso.
 * 
 * @param arreglo Puntero al arreglo de enteros mutable.
 * @param cantidad Cantidad de elementos que posee el arreglo.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);



/**
 * @brief Verifica si los elementos de un arreglo están ordenados de forma ascendente.
 * 
 * Comprueba que cada par contiguo cumpla la condición de menor o igual.
 * 
 * @pre 'arreglo' es un puntero válido o NULL.
 * @post Retorna true si está ordenado ascendentemente (o cantidad <= 1), false en caso contrario.
 * 
 * @param arreglo Puntero al arreglo de enteros a evaluar.
 * @param cantidad Cantidad de elementos del arreglo.
 * @return true Si el arreglo está ordenado o tiene a lo sumo un elemento.
 * @return false Si algún par está desordenado o el arreglo es nulo.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);



/**
 * @brief Cuenta la cantidad de veces que aparece un valor entero dentro de un arreglo.
 * 
 * Recorre secuencialmente el arreglo contabilizando las coincidencias exactas.
 * 
 * @pre 'arreglo' es un puntero válido o NULL.
 * @post Retorna el número total de ocurrencias encontradas.
 * 
 * @param arreglo Puntero al arreglo de enteros a examinar.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param buscado Valor entero cuya frecuencia se desea contar.
 * @return size_t Número de veces que aparece el valor (0 si es nulo o cantidad es 0).
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);



/**
 * @brief Elimina in-place todas las apariciones de un valor específico en un arreglo.
 * 
 * Compacta los elementos restantes hacia el inicio sin dejar huecos y preservando
 * su orden relativo original.
 * 
 * @pre 'arreglo' es un búfer modificable válido.
 * @post Los elementos distintos al valor especificado quedan agrupados al inicio.
 * 
 * @param arreglo Puntero al arreglo de enteros mutable a compactar.
 * @param cantidad Cantidad original de elementos del arreglo.
 * @param valor Valor entero que se desea remover.
 * @return size_t Nueva cantidad de elementos útiles tras la compactación.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);



/**
 * @brief Fusiona dos arreglos ordenados en un tercer arreglo destino de forma ordenada.
 * 
 * Combina dos secuencias ordenadas de origen manteniendo el orden ascendente,
 * validando estrictamente que la capacidad del destino no sea desbordada.
 * 
 * @pre 'primero', 'segundo' y 'destino' son punteros válidos. Capacidad >= cantidad_uno + cantidad_dos.
 * @post El arreglo destino contiene la unión ordenada de ambas secuencias.
 * 
 * @param primero Puntero al primer arreglo ordenado fuente.
 * @param cantidad_uno Cantidad de elementos del primer arreglo.
 * @param segundo Puntero al segundo arreglo ordenado fuente.
 * @param cantidad_dos Cantidad de elementos del segundo arreglo.
 * @param destino Puntero al búfer donde se depositará la fusión resultante.
 * @param capacidad Tamaño físico total disponible en el búfer destino.
 * @return size_t Cantidad total de elementos volcados en el destino (0 si hay errores).
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad);

#endif 