#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Se copian los elementos del arreglo origen a destino,
 * avanzando mediante arigmetica de punteros.
 * @pre 'origen', 'destino' no pueden ser NULL, 'capacidad' no puede ser 0.
 * @post Se devuelve true si la copia fue exitosa,
 *  y false si no fue exitosa la copia.
 * @param arreglo es el arreglo.
 * @param destino es el nuevo arreglo donde se copiara el arreglo.
 * @param capcidad es la cantidad de elementos del arreglo.
 * @return Se devuelve true si la copia fue exitosa,
 *  y false si no fue exitosa la copia.
 */
bool copiar_arreglo(const int *arreglo, int *destino, size_t capacidad);

/**
 * @brief Se invierte el arrelgo.
 * @pre 'arreglo' no puede ser NULL y 'capacidad' no puede ser 0.
 * @post se devuelve true si la inversion fue exitosa,
 * y false si no se pudo hacer correctamente la inversion.
 * @param arreglo es el arreglo.
 * @param capacidad Es la cantidad de elementos en el arreglo.
 * @return Devuelve true si la inversion fue exitosa,
 * y false si no se pudo hacer correctamente la inversion.
 */
bool arreglo_invertir(int *arreglo, size_t capacidad);
#endif 
