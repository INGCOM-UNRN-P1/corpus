/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica con malloc/calloc/realloc debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - No se emplean estructuras (structs); la gestión se realiza mediante punteros directos
 *   (int*), dobles punteros (int**) y tamaños pasados por parámetro.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>


 /** 
 * @brief Reserva un bloque de memoria contigua en el heap 
 * para almacenar 'cantidad' enteros empleando calloc 
 * (dejando la memoria inicializada en 0).
 *
 * @param cantidad define la cantidad de enteros almacenados en 
 * memoria.
 * 
 * @pre La asignación dinámica con calloc debe validarse contra NULL.
 * 
 * @return el puntero int* al bloque asignado o NULL si 'cantidad' 
 * es 0 o si calloc falla.
 *
 * @post el resultado tiene que ser la reserva de memoria 
 * contigua en el heap. 
 *
 * @invariant -------------------------------------
*/
int *crear_bloque_enteros(size_t cantidad);


 /** 
 * @brief Recibe un doble puntero, libera la memoria a la que apunta 
 * el puntero con 'free' y asigna el mismo a NULL para eliminar de 
 * forma segura el puntero colgante.
 *
 * @param puntero_bloque puntero doble a ser liberada su memoria 
 * apuntada.
 * 
 * @pre Si 'puntero_bloque' es NULL o '*puntero_bloque' ya es NULL, 
 * no debe realizar ninguna acción.
 * 
 * @return --------------------------
 *
 * @post el resultado debe ser la liberación de la memoria del
 *       '**puntero_bloque'.
 *
 * @invariant -----------------------
*/ 
void liberar_bloque_enteros(int **puntero_bloque);





 /** 
 * @brief Redimensiona el bloque apuntado por 'bloque' a 'nueva_cantidad' 
 * enteros mediante 'realloc'.
 *
 * @param bloque puntero que apunta a un bloque de memoria
 * @param nueva_cantidad asigna una nueva cantidad entera al bloque
 * 
 * @pre Si realloc falla, no debe perderse el bloque original y la 
 * función retorna NULL. Si nueva_cantidad es 0, tiene que liberar 
 * memoria y retornar NULL.
 * 
 * @return NULL si 'nueva_cantidad' es 0 o si realloc falla.Tambíen 
 * retorna el puntero a la nueva dirección de memoria ante caso de éxito. 
 *
 * @post el resultado tiene que ser el redimensionamiento del bloque
 * a una nueva cantidad.
 * @invariant -------------------------------------------------------------
*/ 
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);







/** 
 * @brief Recibe dos bloques de enteros en memoria dinámica 
 * (o buffers contiguos) junto con sus cantidades respectivas 
 * (primero, cant_primero, segundo, cant_segundo).Reserva un 
 * nuevo bloque en heap para la suma exacta de elementos, copia los
 * elementos del primer bloque seguidos de los del segundo bloque 
 * y retorna el puntero int* al nuevo bloque.
 *
 * @param primero puntero que apunta a un bloque de memoria
 * @param cant_primero indica la cantidad entera de 'primero'
 * @param segundo puntero que apunta a otro bloque de memoria
 * @param cant_segundo define la cantidad entera de 'segundo'
 * 
 * @pre No se deben emplear estructuras (structs). La gestión se 
 * debe realizar mediante punteros directos (int*), 
 * dobles punteros (int**) y tamaños pasados por parámetro.
 * 
 * @return NULL si ambos son nulos o si falla la memoria.
 *
 * @post el resultado es un nuevo bloque en heap con los 
 * elementos de ambos bloques junto con el retorno del puntero
 * al mismo.
 *
 * @invariant 'primero' y 'segundo'.
 * 
 */ 
 int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                                const int *segundo, size_t cant_segundo);






/** 
 * @brief Recibe un doble puntero al bloque de enteros
 * , un puntero a su tamaño actual y el nuevo 'valor' a agregar. 
 * Redimensiona el bloque en el heap para (*cantidad + 1) 
 * elementos, asigna el nuevo valor en la última posición, actualiza 
 * (*cantidad)++ y actualiza *puntero_bloque con la nueva dirección 
 * si realloc cambió la ubicación física.
 *
 * @param puntero_bloque doble puntero que apunta a un bloque de enteros 
 * @param cantidad puntero que apunta al tamaño actual de 'puntero_bloque'
 * @param valor asigna un nuevo valor a 'puntero_bloque'
 * 
 * @pre Toda asignación dinámica con realloc debe validarse contra NULL.
 * 
 * @return Retorna true ante éxito o false si falla realloc 
 * (preservando el bloque original).
 *
 * @post el resultado tiene que ser el redimensionamiento del bloque
 * con un nuevo tamaño y una posible dirección.
 *
 * @invariant ------------------------------------------------
*/
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, 
int valor);

#endif 
