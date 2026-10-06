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
 *@brief Crea un bloque contiguo de enteros en el heap, inicializando en 0.
 *reserv memoria para @p cantidad enteros mediante calloc, por lo que todos los elementos del bloque quedan en 0
*@param cantidad cantidad de enteros que debe alojar el bloque
*@return puntero al bloque reservado, o NULL si @p cantidad es 0 o si calloc falla
*@note el llamador es responsable de liberar el bloque con liberar_bloque_enteros().
*/
int *crear_bloque_enteros(size_t cantidad);


 /**
 *@brief libera un bloque de enteros y deja el puntero del llamador en NULL
 *@param puntero_bloque direccion del puntero al bloque a liberar.
 *Si es NULLm o si @c *puntero_bloque ya es NULL, no se realiza ninguna accion
 *@post si se libero memoria, @c *pnutero_bloque vale NULL (sin puntero colgante)
 */
void liberar_bloque_enteros(int **puntero_bloque);


 /**
 *@brief redimensiona un bloque de entero del head mediante realloc
 *los elementos existentes se conservan hasta el menor entre el tamaño viejo y el nuevo. los elementos agregados quedan sin inicializar
 *@param bloque bloque a redimensionar (puede ser NULL en cuyo caso se reserva una nuevo)
 *@param nueva_cantidad nueva cantidad de enteros del bloque
 *@return puntero al bloque redimensionado (posiblemente en otra direccion), o NULL si:
 *- @p nueva_cantidad es 0: el bloque se libera con free
 *- realloc falla (o el tamaño solicitado desborda size_t): el bloque original no se libera y sigue siendo valido para el llamador.
 *@warning tras un retorno exitoso, @p bloque puede haber quedado invalido: el llamador debe usar unicamente el puntero retornado.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);


 /**
 *@brief concatea dos bloques de enteros en un nuevo bloque del heap
 *reserva exactamente @p cant_primero + @p cant_segundo enteros, copia primero
 *los elementos de @p primero y a continuacion los de @p segundo. los bloques de entrada no se modifican ni se liberan
 *@param primero primer bloque (puede ser NULL solo si @p cant_primero es 0).
 *@param cant_segundo cantidad de elementos de @p segundo
 *@return puntero al nuevo bloque fusionado, o NULL si:
 *- ambos bloques son NULL
 *- un bloque es NULL pero su cantidad es distinta de 0 (parametros invalidos)
 *- la cantidad total es 0 o desborda size_t
 *- falla la reserva de memoria
 *@note el llamador es responsable de liberar el resultado con liberar_bloque_enteros()
 */
 int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo);


 /**
 *@brief agrega un entero al final de bloque dinamico, redimensionandolo
 *redimensiona el bloque a (*cantidad + 1) elementos, escribe @p valor en la ultima posicion e incrementa @c *cantidad. si realloc mueve el bloque, @c *punero_bloque se actualiza ocn la nueva direccion.
 *@param puntero_bloque direccion del puntero al bloque. @c *puntero_bloque puede ser NULL solo si @c *cantidad es 0 (bloque vacio)
 *@param cantidad direccion de la cantidad actual de elementos
 *@param valor valor a insertar al final
 *@return true si se inserto el valor; false si algun puntero de parametro es NULL, si el estado es inconsistente (bloque NULL con cantidad distinta de 0), si el tamaño desborda size_t o si falla realloc. en caso de falla, el bloque original y @c *cantidad quedan intactos
 *@note crecimiento incremental: un realloc por insercion.
 */
 bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);
 
#endif 
