#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

 
/**
 * @brief Copia los elementos de un arreglo origen a un arreglo destino.
 *
 * Recorre ambos arreglos en simultáneo, exclusivamente con aritmética de
 * punteros (sin `[]`), avanzando origen y destino con `++`.
 *
 * @param[in]  origen   Arreglo de enteros a copiar (solo lectura).
 * @param[in]  cantidad Cantidad de elementos a copiar.
 * @param[out] destino  Arreglo donde se escribe la copia.
 *
 * @pre Si 'origen' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y legibles.
 * @pre Si 'destino' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y modificables (de igual o mayor tamaño que 'cantidad').
 * @pre 'origen' y 'destino' son arreglos distintos, sin compartir ningun
 * espacio de memoria entre sí.
 *
 * @post Si retorna true, cada uno de los primeros 'cantidad' elementos de
 * 'destino' es igual al elemento correspondiente de 'origen'.
 * @post El contenido de 'origen' no se modifica.
 * @post Si 'cantidad' es 0, 'destino' no se modifica.
 * @post Si retorna false, 'destino' no se modifica.
 *
 * @return true si pudo copiar, o si 'cantidad' es 0; false si 'origen' o
 * 'destino' es NULL.
 */
bool copiar_arreglo(const int *origen, size_t cantidad, int *destino);


/**
 * @brief Invierte in-place el orden de los elementos de un arreglo de enteros.
 *
 * Utiliza dos punteros que convergen desde los extremos ('inicio' avanzando
 * con `++`, 'fin' retrocediendo con `--`), apoyándose en 'intercambiar' de
 * libpunteros para permutar los valores.
 *
 * @param[in, out] arreglo  Arreglo de enteros a invertir.
 * @param[in]      cantidad Cantidad de elementos del arreglo.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y modificables.
 *
 * @post Si retorna true, el elemento que estaba en la posición 'i' pasa a
 * estar en la posición `cantidad - 1 - i`, para cada 'i' entre 0 y
 * 'cantidad' - 1.
 * @post Los valores finales son una permutación de los originales: no se
 * introducen valores nuevos.
 *
 * @return true si pudo invertir el arreglo; false si 'arreglo' es NULL.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);


#endif 
