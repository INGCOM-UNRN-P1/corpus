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
 * @brief Reserva un bloque contiguo de enteros en el heap, inicializado en cero.
 * Utiliza calloc para reservar espacio para exactamente @p cantidad enteros.
 * El llamador es responsable de liberar el bloque con liberar_bloque_enteros().
 * @param cantidad Cantidad de enteros que debe contener el bloque.
 * @return Puntero al primer elemento del bloque reservado, con todos sus
 *         elementos en 0; o NULL si @p cantidad es 0 o si calloc falla.
 * @pre Ninguna: cualquier valor de @p cantidad es aceptado.
 * @post Si el retorno no es NULL, el bloque tiene espacio para @p cantidad
 *       enteros y todos valen 0.
 * @post Si el retorno es NULL, no se reservó memoria.
 */
int *crear_bloque_enteros(size_t cantidad);



 /**
 * @brief Libera un bloque dinámico de enteros y deja el puntero en NULL.
 * Libera con free la memoria a la que apunta @p *puntero_bloque y luego asigna
 * NULL a esa variable del llamador, evitando que quede un puntero colgante
 * (regla 0x3002h). Es seguro llamarla sobre un bloque ya liberado o nunca
 * reservado: en esos casos no realiza ninguna acción.
 * @param puntero_bloque Dirección de la variable que contiene el puntero al
 *        bloque (es decir, se pasa &bloque). Puede ser NULL.
 * @pre Si @p puntero_bloque no es NULL y @p *puntero_bloque no es NULL,
 *      @p *puntero_bloque debe haber sido obtenido con crear_bloque_enteros(),
 *      redimensionar_bloque_enteros() o una asignación dinámica equivalente.
 * @post Si @p puntero_bloque no es NULL, @p *puntero_bloque vale NULL.
 * @post La memoria del bloque, si existía, queda liberada y no debe volver
 *       a usarse.
 * @note No retorna valor. Llamarla con @p puntero_bloque == NULL o con
 *       @p *puntero_bloque == NULL no produce ningún efecto.
 */
void liberar_bloque_enteros(int **puntero_bloque);


/**
 * @brief Redimensiona un bloque dinámico de enteros a una nueva cantidad.
 *
 * Utiliza realloc para ajustar el bloque a @p nueva_cantidad enteros. Si el
 * bloque debe crecer, los elementos nuevos quedan sin inicializar; los
 * elementos existentes se conservan hasta el menor de los dos tamaños. El
 * bloque puede cambiar de dirección, por lo que el llamador debe usar el
 * puntero devuelto y descartar el anterior solo si la operación tuvo éxito.
 *
 * @param bloque Puntero al bloque actual, obtenido de una asignación dinámica.
 *        Si es NULL, la función se comporta como una reserva nueva.
 * @param nueva_cantidad Cantidad de enteros que debe contener el bloque.
 *        Si es 0, el bloque se libera.
 *
 * @return Puntero al bloque redimensionado, que puede diferir de @p bloque;
 *         NULL si @p nueva_cantidad es 0 (el bloque fue liberado) o si
 *         realloc falla (en ese caso @p bloque sigue siendo válido y
 *         conserva su contenido).
 *
 * @pre @p bloque es NULL o proviene de crear_bloque_enteros(),
 *      redimensionar_bloque_enteros() o una asignación dinámica equivalente.
 * @post Si el retorno no es NULL, el bloque devuelto tiene espacio para
 *       @p nueva_cantidad enteros.
 * @post Si @p nueva_cantidad es 0, @p bloque queda liberado y no debe
 *       volver a usarse.
 * @post Si realloc falla, @p bloque no se modifica y el llamador sigue
 *       siendo responsable de liberarlo.
 *
 * @warning No hacer bloque = redimensionar_bloque_enteros(bloque, n): si
 *          falla, se perdería la única referencia al bloque original.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);





#endif 
