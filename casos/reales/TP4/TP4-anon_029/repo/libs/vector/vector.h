/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros
 *  en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica con malloc/calloc/realloc debe validarse
 *  contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - No se emplean estructuras (structs); la gestión se realiza mediante
 *  punteros directos
 *   (int*), dobles punteros (int**) y tamaños pasados por parámetro.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Crea un bloque de memoria de enteros.
 * @pre 'cantidad' no puede ser 0.
 * @pre 'bloque' no puede ser NULL.
 * @post devuelve el puntero int al bloque asignado.
 * @param cantidad Es la cantidad de elementos de la memoria que se le pediran
 *  al heap para ser reservados.
 * @return Retorna el puntero int *al bloque asignado, o NULL si la cantidad
 *  es 0 o si calloc falla.
 */
int *crear_bloque_enteros(size_t cantidad);


/**
 * @brief libera la memoria de un bloque dinamico  y asigna NULL al puntero
 *  para evitar que este se vuelva un puntero colgante.
 * @pre '*puntero_bloque' y 'puntero_bloque' no puedene ser NULL.
 * @post Libera el espacio que ocupaba en la memoria 'puntero_bloque'
 *  y se asegura que su puntero apunte a NULL.
 * @param puntero_bloque Es el puntero del puntero que apunta al bloque.
 */
void liberar_bloque_enteros(int **puntero_bloque);


/**
 * @brief Cambia el tamanio del bloque original mediante realoc.
 * @post Si cantidad es 0 o realloc falla, el bloque original no se modifica
 *  y retorna NULL.En caso contrario, retorna el bloque con el nuevo tamaño.
 * @param bloque Es el bloque original de memoria
 * @param nueva_cantidad Es el nuevo tamanio que requerira el bloque.
 * @return  Si realloc falla, se conserva el bloque original y la función
 *  retorna NULL.Ante exito, retorna el puntero a la nueva dirección de
 *  memoria.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);


/**
 * @brief Reserva un espacio en la memoria que es la suma de dos bloques,
 *  copia los elementos del primer bloque, seguidos por los del segundo bloque.
 * @pre Ni 'primero', ni 'segundo' pueden ser NULL
 * @post Devuelve la direccion de memoria en donde se encuentra el nuevo
 *  bloque.
 * @param primero es el primer bloque de memoria.
 * @param segundo es el segundo bloquee de memoria.
 * @param cant_primero es la cantidad de elementos que se encuentan en
 *  'primero'.
 * @param cant_segundo es la cantidad de elementos que se encuentan en
 *  'segundo'.
 * @return Devuelve la direccion de meemoria del neuvo bloquee conformado
 *  por 'primero' y 'seegundo'.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);


/**
 * @brief Inserta un nuevo entero al final de un bloque dinamico,
 *  ampliando la memoria.
 * @pre puntero_bloque no debe ser NULL.
 * @pre cantidad no debe ser NULL.
 * @post Si la reasignacion es exitosa se increementa 'cantidad' en uno,
 *  se agrega 'valor' en el final del nuevoe spacio dee memoria.
 * @param puntero_bloque Puntero al puntero del bloque dinámico (int **).
 * @param cantidad Puntero a la variable que almacena la cantidad
 *  actual de elementos.
 * @param valor Entero a insertar al final del bloque.
 * @return Retorna true ante exito dee insercion y false si falla realloc.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor);
#endif 
