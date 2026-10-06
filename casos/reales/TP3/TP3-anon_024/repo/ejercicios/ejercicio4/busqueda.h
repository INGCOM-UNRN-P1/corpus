#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * =========================================================================
 * Ejercicio 4: Búsqueda con Punteros y Retorno de Puntero
 * =========================================================================
 * Busca la primera aparición de un valor entero en un arreglo.
 *
 * @param arreglo puntero al primer elemento de la secuencia a examinar.
 * @param cantidad de enteros presentes dentro del contenedor.
 * @param valor entero cuyo puntero a la primera posicion se desea ubicar.
 * @pre El puntero arreglo debe apuntar a una secuencia valida de al menos
 *      cantidad elementos si cantidad > 0.
 * @post La secuencia evaluada permanece inalterada durante la busqueda.
 * @returns Puntero constante al elemento donde ocurre la primera coincidencia.
 *          Retorna NULL si el valor no esta presente o si el parametro
 *          arreglo es nulo.
*/
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/**
 * Calcula la distancia relativa o indice entre el inicio de una secuencia y un
 * elemento interno.
 *
 * @param inicio del primer elemento de la secuencia de referencia.
 * @param elemento puntero a la posicion dentro de la memoria a evaluar.
 * @pre inicio y elemento deben pertenecer a la misma secuencia de memoria
 *      contigua para que la resta sea valida.
 * @post La memoria referenciada no sufre ninguna modificacion.
 * @returns La distancia en número de elementos (elemento - inicio). Retorna -1
 *          si inicio o elemento son nulos, o si elemento apunta a una
 *          posición previa a inicio.
*/
ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
