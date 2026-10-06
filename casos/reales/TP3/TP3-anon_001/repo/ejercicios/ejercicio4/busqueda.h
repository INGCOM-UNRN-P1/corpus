#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>




/**
 * @brief Busca la primera aparición de un valor en un arreglo de enteros.
 *
 * @details Recorre el arreglo mediante aritmética de punteros y retorna la dirección
 *          de memoria exacta de la primera coincidencia del valor buscado.
 *
 * @param[in] arreglo Puntero constante al primer elemento del arreglo.
 * @param[in] cantidad de elementos que integran el arreglo.
 * @param[in] buscado Valor entero que se desea buscar.
 *
 * @pre Si 'arreglo' no es NULL, debe apuntar a un bloque de memoria accesible de al menos 'cantidad' elementos.
 * @post El contenido del arreglo permanece inalterado.
 *
 * @return Puntero constante (const int *) a la primera posición de memoria donde se encuentra el valor,
 *          NULL si el valor no existe en el arreglo o si 'arreglo' es NULL.
 */
const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado);

/**
 * @brief Calcula el índice o distancia relativa entre el inicio de un arreglo y un puntero interno.
 *
 * @details Realiza la resta de punteros (p - inicio) para obtener la diferencia en cantidad
 *          de elementos entre la posición apuntada por 'p' y la base del arreglo.
 *
 * @param[in] inicio Puntero constante al primer elemento del arreglo.
 * @param[in] p Puntero constante a un elemento interno del arreglo.
 *
 * @pre 'inicio' y 'p' deben apuntar al mismo bloque de memoria coherente.
 * @post Ningún elemento en memoria es modificado.
 *
 * @return La distancia o índice en posiciones (>= 0) si los datos son válidos,
 *         o -1 si alguno es NULL o si 'p' se encuentra antes de 'inicio'.
 */
long distancia_punteros(const int *inicio, const int *p);


#endif 
