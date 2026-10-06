#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Calcula el promedio aritmetico de los valores contenidos en un arreglo de enteros.
 *
 * @pre arreglo contiene al menos cantidad elementos validos en memoria (o es NULL si cantidad es 0).
 * @post Retorna el promedio aritmetico como double de los elementos, o 0.0 si el arreglo es nulo o cantidad es 0.
 *
 * @param arreglo  Arreglo de numeros enteros de solo lectura a promediar.
 * @param cantidad Cantidad de elementos validos a procesar en el arreglo.
 *
 * @return double Promedio aritmetico de los valores, o 0.0 si no hay elementos o el arreglo es invalido.
 */
double calcular_promedio(const int arreglo[], size_t cantidad);



/**
 * @brief Determina si un numero entero se encuentra dentro de un arreglo.
 *
 * @pre arreglo contiene al menos cantidad elementos validos en memoria (o es NULL si cantidad es 0).
 * @post Retorna true si valor pertenece a los elementos validos del arreglo; false si no pertenece, si arreglo es NULL o cantidad es 0.
 *
 * @param arreglo  Arreglo de numeros enteros de solo lectura donde buscar.
 * @param cantidad Cantidad de elementos validos a inspeccionar en el arreglo.
 * @param valor    Numero entero que se desea comprobar si esta presente.
 *
 * @return bool true si el elemento buscado existe en el arreglo; false en caso contrario.
 */
bool contiene_valor(const int arreglo[], size_t cantidad, int valor);

#endif
