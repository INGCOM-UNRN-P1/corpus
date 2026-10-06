#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"




/**
 * @brief Calcula el valor mínimo, máximo y el promedio de un arreglo de enteros.
 *
 * @details Utiliza la función 'obtener_min_max' para determinar los valores
 *          extremos (mínimo y máximo) y recorre el arreglo utilizando únicamente
 *          aritmética de punteros pura para acumular el total y calcular el
 *          promedio en formato flotante (double).
 *
 * @param[in] arreglo Puntero constante al primer elemento del arreglo de enteros.
 * @param[in] cantidad de elementos contenidos en el arreglo.
 * @param[out] minimo Puntero a la variable donde se almacenará el valor mínimo.
 * @param[out] maximo Puntero a la variable donde se almacenará el valor máximo.
 * @param[out] promedio Puntero a la variable donde se almacenará el promedio calculado.
 *
 * @pre El arreglo debe ser válido y contener al menos un elemento ('cantidad' > 0).
 * @pre Los punteros de salida ('minimo', 'maximo' y 'promedio') deben apuntar a direcciones válidas.
 * @post Si retorna true, '*minimo', '*maximo' y '*promedio' contendrán los resultados.
 *
 * @return 'true' si el cálculo fue exitoso; 'false' si algún puntero es NULL o si 'cantidad' es 0.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);


/**
 * @brief Cuenta los elementos de un arreglo que pertenecen al intervalo cerrado [limite_inf, limite_sup].
 *
 * @details Recorre el arreglo apuntado por 'arreglo' utilizando aritmética
 *          de punteros y evalúa si cada elemento se
 *          encuentra dentro del rango inclusivo. Guarda el total hallado en la
 *          dirección apuntada por 'coincidencias'.
 *
 * @param[in] arreglo Puntero constante al primer elemento del arreglo.
 * @param[in] cantidad de elementos que integran el arreglo.
 * @param[in] limite_inf Cota inferior del intervalo.
 * @param[in] limite_sup Cota superior del intervalo 
 * @param[out] coincidencias Puntero a la variable de tipo size_t donde se guardará la cantidad de elementos hallados.
 *
 * @pre El puntero 'arreglo' debe apuntar a un arreglo válido de al menos 'cantidad' elementos.
 * @pre El puntero 'coincidencias' debe apuntar a una variable válida de tipo size_t.
 * @post Si la función retorna true, '*coincidencias' contendrá la cantidad de valores en el rango.
 *
 * @return 'true' si 'arreglo' y 'coincidencias' son distintos de NULL; 'false' en caso contrario.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);






#endif 
