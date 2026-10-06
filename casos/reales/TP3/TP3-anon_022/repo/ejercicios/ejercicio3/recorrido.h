#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia una cantidad de elementos enteros desde un arreglo origen
 *        hacia un arreglo destino utilizando exclusivamente aritmética
 *        de punteros.
 *
 * @pre 'origen' debe apuntar a una región de memoria válida que contenga
 *      al menos 'cantidad' elementos enteros.
 * @pre 'destino' debe apuntar a una región de memoria válida con capacidad
 *      para almacenar al menos 'cantidad' elementos enteros.
 *
 * @post Los primeros 'cantidad' elementos de 'destino' son iguales a los
 *       correspondientes elementos de 'origen'. Si 'cantidad' es 0,
 *       no se modifica el destino.
 *
 * @param origen Arreglo del que se obtienen los elementos.
 * @param cantidad Número de elementos a copiar.
 * @param destino Arreglo donde se almacenan los elementos copiados.
 *
 * @return true si 'origen' y 'destino' son válidos y la copia se realiza.
 *         false si alguno de los punteros es nulo.
 */
bool copiar_arreglo(const int *origen, size_t cantidad, int *destino);

/**
 * @brief Invierte in-place el orden de los elementos de un arreglo entero
 *        mediante dos punteros que convergen desde sus extremos.
 *
 * @post Los elementos quedan en orden inverso al original. Si 'arreglo'
 *       es nulo o contiene uno o ningún elemento, no se modifica.
 *
 * @param arreglo cuyo orden se desea invertir.
 * @param cantidad Número de elementos válidos.
 */
void invertir_arreglo(int *arreglo, size_t cantidad);

#endif 