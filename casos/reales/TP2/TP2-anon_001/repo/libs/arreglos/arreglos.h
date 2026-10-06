/**
 * @file arreglos.h
 * @brief Biblioteca de manipulación y procesamiento de arreglos de enteros (int).
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - Todo arreglo viene acompañado por su cantidad de elementos válidos (size_t cantidad).
 * - Arreglos de solo lectura (const int arreglo[]) para funciones que no modifican datos.
 * - Arreglos mutables (int arreglo[]) para funciones que modifican contenido in-place.
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>




 /**
 * @brief Calcula la suma acumulada de los elementos de un arreglo de enteros.
 * @pre Si `arreglo` no es NULL, debe apuntar a un bloque de memoria
 *     válido con al menos `cantidad` elementos accesibles para lectura.
 * @post El contenido del arreglo original no es modificado (`const`).
 * @param arreglo de enteros a sumar. Puede ser NULL.
 * @param cantidad de elementos válidos a procesar dentro del arreglo.
 * 
 * @return long long La suma de todos los elementos. 
 *         Retorna 0 si `arreglo` es NULL o si `cantidad` es 0.
 */

long long arreglo_sumar(const int arreglo[], size_t cantidad);




/**
 * @brief Busca la primera aparición de un elemento en el arreglo.
 *
 * @param arreglo de enteros sobre el cual realizar la búsqueda.
 * @param cantidad de elementos a evaluar en el arreglo.
 * @param buscado Valor entero que se desea localizar.
 * 
 * @pre Si `arreglo` no es NULL, debe apuntar a un bloque de memoria
 *      válido con al menos `cantidad` elementos accesibles para lectura.
 * @post El contenido del arreglo permanece inalterado (`const`).
 * 
 * @return int El índice en base cero de la primera aparición del elemento.
 *         Retorna -1 si el elemento no se encuentra, si `arreglo` es NULL
 *         o si `cantidad` es 0.
 */

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);




 /**
 * @brief Invierte el orden de los elementos del arreglo en su misma memoria (in-place).
 *
 * @param arreglo de enteros a invertir.
 * @param cantidad de elementos en el arreglo
 * 
 * @pre Si `arreglo` no es NULL y `cantidad > 1`, debe apuntar a un bloque
 *      de memoria válido con al menos `cantidad` elementos accesibles para lectura/escriturs
 * @post Los elementos del arreglo quedan ordenados en sentido inverso al original.
 */


void arreglo_invertir(int arreglo[], size_t cantidad);





 /**
 * @brief Verifica si los elementos del arreglo se encuentran ordenados de forma ascendente.
 *
 * @param arreglo de enteros a verificar.
 * @param cantidad de elementos en el arreglo
 * 
 * @pre Si `arreglo` no es NULL y `cantidad > 1`, debe apuntar a un bloque
 *      de memoria válido con al menos `cantidad` elementos accesibles para lectura.
 * @post El contenido del arreglo permanece inalterado (`const`).
 * 
 * @return true Si el arreglo está ordenado de forma ascendente o si `cantidad <= 1`.
 *         false Si algún par contiguo está fuera de orden o si `arreglo` es NULL.
 */

bool arreglo_ordenado(const int arreglo[], size_t cantidad);



 /**
 * @brief Cuenta las ocurrencias de un número entero dentro de un arreglo.
 *
 * @param arreglo de enteros a evaluar.
 * @param cantidad de elementos en el arreglo.
 * @param buscado Valor entero a contar.
 * 
 * @pre Si `arreglo` no es NULL y `cantidad > 0`, debe apuntar a un bloque
 *      de memoria válido con al menos `cantidad` elementos accesibles para lectura.
 * @post El contenido del arreglo permanece inalterado (`const`)
 * 
 * @return size_t Cantidad de veces que aparece el elemento buscado.
 *                Retorna 0 si el elemento no se encuentra, si `arreglo` es NULL
 *                o si `cantidad` es 0.
 */

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);



 /**
 * @brief Elimina in-place todas las apariciones de un valor dentro de un arreglo.
 *
 * Compacta los elementos restantes hacia el inicio del arreglo preservando
 * su orden relativo original y sin utilizar memoria dinámica auxiliar.
 *
 * @param arreglo de enteros a compactar.
 * @param cantidad inicial de elementos en el arreglo.
 * @param valor entero que se desea eliminar del arreglo
 * 
 * @pre Si `arreglo` no es NULL y `cantidad > 0`, debe apuntar a un bloque
 *      de memoria válido de al menos `cantidad` elementos en lectura/escritura.
 * @post Los elementos distintos a `valor` quedan agrupados al inicio del arreglo.
 * 
 * @return size_t Nueva cantidad de elementos válidos en el arreglo compactado.
 *                Retorna 0 si `arreglo` es NULL o si `cantidad` es 0.
 */

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);



#endif 
