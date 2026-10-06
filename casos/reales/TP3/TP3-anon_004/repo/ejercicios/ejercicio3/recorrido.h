#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia los elementos de un arreglo a otro usando avance estricto de punteros.
 *
 * @pre origen y destino apuntan a secuencias contiguas de al menos cantidad enteros sin solapamiento.
 * @post Copia cantidad enteros desde origen hacia destino y retorna true; retorna false si algun puntero es NULL.
 *
 * @param destino Puntero al arreglo donde se recibiran los elementos.
 * @param origen Puntero de solo lectura al arreglo fuente de datos.
 * @param cantidad Cantidad de elementos a transferir.
 *
 * @return bool true si la copia se realizo correctamente, false ante error de parametros.
 */
bool copiar_arreglo(int *destino, const int *origen, size_t cantidad);

/**
 * @brief Invierte in-place un arreglo mediante dos punteros convergentes reutilizando intercambiar.
 *
 * @pre arreglo apunta a una secuencia de memoria valida de cantidad enteros.
 * @post Invierte el orden de los elementos in-place; no produce cambios si arreglo es NULL o cantidad <= 1.
 *
 * @param arreglo Puntero al inicio del arreglo a invertir.
 * @param cantidad Cantidad de elementos en el arreglo.
 */
void invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
