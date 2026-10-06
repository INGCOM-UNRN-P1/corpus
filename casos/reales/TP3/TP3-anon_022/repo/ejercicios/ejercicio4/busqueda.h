#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Busca la primera aparición de un valor entero en un arreglo,
 *        recorriéndolo mediante aritmética de punteros.
 *
 * @pre Si 'arreglo' no es NULL, debe apuntar a un bloque contiguo de al menos
 *      'cantidad' elementos enteros válidos.
 *
 * @post El arreglo no es modificado.
 *
 * @param arreglo de enteros donde se realizará la búsqueda.
 * @param cantidad de elementos válidos del arreglo.
 * @param buscado Valor entero que se desea encontrar.
 *
 * @return Puntero constante a la primera aparición del valor buscado.
 *         Retorna NULL si 'arreglo' es NULL, 'cantidad' es 0 o el valor
 *         buscado no se encuentra.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado);

/**
 * @brief Calcula la distancia entre un elemento de un arreglo y su inicio
 *        mediante resta de punteros.
 *
 * @pre Si 'inicio' y 'elemento' no son NULL, ambos deben apuntar a elementos
 *      del mismo arreglo, o 'elemento' puede apuntar al elemento siguiente
 *      al último.
 *
 * @post El arreglo no es modificado.
 *
 * @param inicio Puntero al primer elemento del arreglo.
 * @param elemento Puntero al elemento cuya distancia respecto de 'inicio'
 *                 se desea calcular.
 *
 * @return Distancia en cantidad de elementos entre 'inicio' y 'elemento'.
 *         Retorna -1 si alguno de los punteros es NULL o si 'elemento'
 *         se encuentra antes de 'inicio'.
 */
long distancia_punteros(const int *inicio, const int *elemento);

#endif 