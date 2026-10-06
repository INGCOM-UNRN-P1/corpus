#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Realiza una copia de un arreglo utilizando punteros y aritmetica de punteros.
 *          Los arreglos no debe ser NULL y la cantidad de elementos debe ser mayor a 0.
 * @param arreglo_origen[int] direccion a un arreglo de enteros.
 * @param arreglo_destino[int][in] arreglo al que se le van a ingresar elementos de origen.
 * @param capacidad_origen[size_t] de elementos en origen.
 * @param capacidad_destino[size_t] de elementos en destino
 * @return True si el arreglo se copio correctamente.
 *          False si los parametros son invalidos o si no se pudo copiar el arreglo.
 */
 bool copiar_arreglo(const int *arreglo_origen, int *arreglo_destino,
                    size_t capacidad_origen, size_t capacidad_destino);
/**
 * @brief Invierte in-place un arreglo de enteros utilizando dos punteros.
 *          El puntero tiene que ser distinto de NULL y cantidad mayor a 0.
 * @param arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @return arreglo[out] con los elementos invertidos.
 */
void invertir_arreglo(int *arreglo, size_t capacidad);
#endif 
