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
 * @brief Toma un arreglo para sumar todos sus elementos
 * @param arreglo Secuencia a la que se le debe aplicar la sumatoria
 * @param cantidad Límite superior predefinido de la estructura
 * @pre El arreglo no puede estar vacío y su límite superior no puede estar en 0
 * @post En caso de que el arreglo sea invalido se devuelve 0
 * @return La sumatoria de todos los números dentro del arreglo
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);

/**
 * @brief Se busca la primera aparición de un elemento dado
 * @param arreglo Secuencia en la que se debe buscar el número
 * @param cantidad Tamaño del arreglo predefinido para evitar desbordamientos
 * @param buscado Número a encontrar en la secuencia
 * @pre El número debe existir dentro de la secuencia
 * @post Si el número no está en la secuencia se devuelve -1
 * @return La primera posición en la que se encontró al elemento 
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);

/**
 * @brief Se modifica un arreglo para poner sus valores en lugares opuestos
 * @param arreglo Secuencia a invertir 
 * @param cantidad Tamaño del arreglo predefinido para evitar desbordamientos
 * @pre El arreglo debe contener algo y debe tener más de un elemento
 * @post En caso de un arreglo no operable no cambia nada
 */
void arreglo_invertir(int arreglo[], size_t cantidad);

/**
 * @brief Se verifica que un arreglo sea estrictamente ascendente
 * @param arreglo Número a verificar como ordenado
 * @param cantidad Tamaño del arreglo predefinido para evitar desbordamientos
 * @pre El arreglo debe contener más de un elemento
 * @post Devuelve falso para arreglos vacíos y verdadero si tiene un elemento
 * @return Verdadero o falso dependiendo de si está ordenado o no
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);

/**
 * @brief Cuenta la cantidad de elementos que coinciden con un elemento dado
 * @param arreglo Secuencia en la que buscar coincidencias
 * @param cantidad Tamaño del arreglo predefinido para evitar desbordamientos
 * @param buscado Elemento a contar dentro del arreglo
 * @pre El arreglo no puede estar vacío ni su cantidad puede ser 0
 * @post De estar vacío o declarar 0 cantidad devuelve 0
 * @return Devuelve la cantidad de coincidencias con el número solicitado
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);

/**
 * @brief Se eliminan todas las ocurrencias de un elemento en un arreglo
 * @param arreglo Secuencia en la que hay que eliminar una serie de valores
 * @param cantidad Tamaño del arreglo predefinido para evitar desbordamientos
 * @param buscado Elemento a eliminar de la secuencia
 * @pre El arreglo no puede estar vacío, ni su cantidad puede ser 0
 * @post En caso de estar vacío o que su cantidad sea 0 devuelve 0
 * @return La cantidad de elementos restantes en el arreglo sin el número
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Fusiona dos arreglos con un orden estrictamente ascendente
 * @param primer Secuencia predefinida a fusionar con otra
 * @param cantidad_uno Número de elementos en el primer arreglo inicial
 * @param segundo Otra secuencia predefinida a fusionar con otra 
 * @param cantidad_dos Número de elementos en el segundo arreglo inicial
 * @param destino Arreglo final donde debe estar la fusión de ambos arreglos
 * @param capacidad Capacidad máxima de destino
 * @pre Los dos primeros arreglos no pueden estar vacíos en simultaneo
 * @post En caso que ambas secuencias iniciales esten vacias se devuelve 0
 * @return Devuelve la cantidad de elementos ingresados en destino
 */

size_t arreglo_fusionar(const int primer[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad);

#endif 
