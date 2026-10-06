#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>


/**
 * buscar_primero: busca la primera aparición de un valor en un arreglo de enteros
 *    recorriéndolo con aritmética de punteros. En lugar de retornar un índice numérico,
 *    debe retornar un puntero constante (const int *) a la posición exacta en memoria
 *    donde se encuentra el elemento, o NULL si no existe o ante parámetros inválidos.
 */

 /**
  * distancia_punteros: función utilitaria que recibe el puntero al inicio del
 *    arreglo y un puntero a un elemento interno (obtenido por ejemplo mediante
 *    buscar_primero), y calcula su índice o distancia relativa mediante la resta
 *    de punteros (p - inicio). Si alguno es NULL o el elemento está antes del inicio,
 *    retorna -1.
*/


/**
 * @brief Busca la primera aparicion de un valor en un arreglo de enteros.
 *
 * @param inicio El puntero al primer elemento de un arreglo.
 * @param cantidad La cantidad de elementos donde se desea buscar.
 * @param valor El valor que se desea buscar.
 * @pre El puntero a inicio no debe ser nulo y cantidad no debe ser cero.
 * @return Retorna un puntero al primer elemento encontrado o un puntero nulo
 * si no se encuentra. En caso de error si inicio es nulo, o cantidad es cero se retorna
 * un puntero nulo.
 */
const int *buscar_primero(const int inicio[], size_t cantidad, int valor);

/**
 * @brief Determina el índice relativo de un elemento.
 *
 * @param inicio El inicio relativo del arreglo.
 * @param elemento El elemento con el que se calculara su indice relativo.
 * @pre Elemento debe ser mayor a inicio y ningun parametro debe ser nulo
 * @post Se calculara la distancia entre los punteros y se devolvera en un tipo ptrdiff_t.
 * @return Devuelve un puntero de tipo ptrdiff_t si la funcion se completo correctamente
 * o un puntero nulo si inicio es mayor o igual a elemento o si los punteros pasados
 * por parametro son nulos.
 */
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);
#endif 
