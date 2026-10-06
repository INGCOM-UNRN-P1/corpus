/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros en heap
 * sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica con malloc/calloc/realloc debe validarse contra
 * NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - No se emplean estructuras (structs); la gestión se realiza mediante
 * punteros directos (int*), dobles punteros (int**) y tamaños pasados por
 * parámetro.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Crea un bloque contiguo de memoria dinámica para almacenar enteros en
 * el heap.
 *
 * Utiliza 'calloc' para reservar el bloque y asegura que la memoria quede
 * limpia e inicializada en 0.
 *
 * @param cantidad de enteros que contendrá el bloque dinámico.
 *
 * @return int *Puntero al inicio del bloque de enteros reservado.
 *         Devuelve NULL si 'cantidad' es 0 o si la asignación con 'calloc'
 * falla.
 */

int *crear_bloque_enteros(size_t cantidad);


void liberar_bloque_enteros(int **puntero_bloque);



/**
 * @brief Redimensiona un bloque de enteros en memoria dinámica.
 *
 * Cambia el tamaño del bloque apuntado por 'bloque' para que contenga
 * 'nueva_cantidad' de enteros utilizando realloc.Si 'nueva_cantidad' es 0,
 * libera la memoria del bloque original y retorna NULL.Si la reasignación
 * falla, el bloque original no se pierde ni se modifica, y la función retorna
 * NULL.
 *
 * @param bloque Puntero al bloque de enteros a redimensionar.
 * @param nueva_cantidad total de enteros que tendrá el bloque.
 * @return int *Puntero a la nueva dirección de memoria del bloque
 * redimensionado, o NULL si falla la reasignación o si nueva_cantidad es 0.
 */

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);



/**
 * @brief Fusiona y concatena dos bloques de enteros en un nuevo bloque en el
 * heap.
 *
 * Reserva memoria dinámica para un nuevo bloque que contendrá la suma exacta
 * de los elementos de ambos bloques recibidos.Copia secuencialmente los
 * elementos del primer bloque y, a continuación, los del segundo.Los bloques
 * originales no se modifican al estar declarados como constantes.
 *
 * @param primero Puntero al primer bloque de enteros (constante).
 * @param cant_primero Cantidad de elementos del primer bloque.
 * @param segundo Puntero al segundo bloque de enteros (constante).
 * @param cant_segundo Cantidad de elementos del segundo bloque.
 * @return int *Puntero al nuevo bloque de memoria fusionado.Retorna NULL
 *         si la cantidad total de elementos a fusionar es 0 o si falla la
 * reserva de memoria.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);



/**
 * @brief Agrega un nuevo entero al final de un bloque de memoria dinámica.
 *
 * Redimensiona el bloque apuntado por '*puntero_bloque' para alojar un elemento
 * adicional ((*cantidad) + 1). Si la reasignación es exitosa, inserta 'valor'
 * en la última posición, actualiza la dirección almacenada en '*puntero_bloque'
 * e incrementa en uno el valor de '*cantidad'.En caso de fallo o si los
 * punteros recibidos son NULL, el bloque original no se modifica.
 *
 * @param puntero_bloque Doble puntero al bloque de enteros en memoria dinámica.
 * @param cantidad Puntero al contador con la cantidad de elementos actuales del
 * bloque.
 * @param valor entero que se agregará al final del bloque.
 * @return true Si la memoria se redimensionó y el valor se insertó con éxito.
 * @return false Si 'puntero_bloque' o 'cantidad' son NULL, o si falla
 * 'realloc'.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor);

#endif 
