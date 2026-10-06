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
 * @brief Calcula la suma algebraica de los elementos de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros de solo lectura a sumar. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 *
 * @pre Ninguna; la función es segura ante 'arreglo == NULL' o 'cantidad == 0'.
 * @post El arreglo no es modificado.
 *
 * @return La suma de todos los elementos de 'arreglo'. Retorna 0 si
 *         'arreglo' es NULL o si 'cantidad' es 0.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);


/**
 * @brief Busca la primera aparición de un valor dentro de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros de solo lectura donde buscar. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 * @param buscado Valor entero a buscar dentro de 'arreglo'.
 *
 * @pre Ninguna; la función es segura ante 'arreglo == NULL'.
 * @post El arreglo no es modificado.
 *
 * @return El índice en base cero (0 <= índice < cantidad) de la primera
 *         aparición de 'buscado'. Si 'arreglo' es NULL o si 'cantidad' es 0
 *         retorna -1.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Invierte el orden de los elementos de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros mutable a invertir. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 *
 * @pre Ninguna; la función es segura ante 'arreglo == NULL'.
 * @post Si 'arreglo != NULL' y 'cantidad > 1', los elementos quedan en
 *       orden inverso al original. Si 'arreglo == NULL' o 'cantidad <= 1',
 *       el arreglo permanece sin cambios.
 *
 * @return No retorna valor (void).
 */
void arreglo_invertir(int arreglo[], size_t cantidad);


/**
 * @brief Verifica si los elementos de un arreglo están ordenados ascendentemente.
 *
 * @param arreglo Arreglo de enteros de solo lectura a verificar. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 *
 * @pre Ninguna; la función es segura ante 'arreglo == NULL'.
 * @post El arreglo no es modificado.
 *
 * @return true si arreglo[i] <= arreglo[i + 1] para cada elemento del
 *         arreglo, o si 'cantidad <= 1'. Retorna false si existe algún
 *         par fuera de orden, o si 'arreglo' es NULL.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);


/**
 * @brief Cuenta las apariciones de un valor dentro de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros de solo lectura a recorrer. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en el arreglo.
 * @param buscado Valor entero cuyas apariciones en el arreglo se desean contar.
 *
 * @pre Ninguna; la función es segura ante 'arreglo == NULL'.
 * @post El arreglo no es modificado.
 *
 * @return La cantidad de veces que 'buscado' aparece en 'arreglo'.
 *         Retorna 0 si 'arreglo' es NULL o si 'cantidad' es 0.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Elimina todas las apariciones de un valor en un arreglo,
 *        compactando los elementos restantes hacia el inicio.
 *
 * @param arreglo Arreglo de enteros mutable a compactar. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en 'arreglo' antes de compactar.
 * @param valor Valor entero a eliminar de 'arreglo'.
 *
 * @pre Ninguna; la función es segura ante 'arreglo == NULL'.
 * @post Los elementos distintos de 'valor' quedan compactados al inicio,
 *       preservando su orden relativo original. Las posiciones sobrantes
 *       al final no están definidas.
 *
 * @return La nueva cantidad de elementos válidos en 'arreglo' luego de
 *         compactar (siempre <= cantidad). Retorna 0 si 'arreglo' es NULL.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);


/**
 * @brief Fusiona dos arreglos ordenados ascendentemente en un tercer arreglo
 *        destino, manteniéndolo ordenado.
 *
 * @param primero Primer arreglo de solo lectura, ya ordenado ascendentemente.
 *                Puede ser NULL si 'cantidad_uno' es 0.
 * @param cantidad_uno Cantidad de elementos válidos en 'primero'.
 * @param segundo Segundo arreglo de solo lectura, ya ordenado ascendentemente.
 *                Puede ser NULL si 'cantidad_dos' es 0.
 * @param cantidad_dos Cantidad de elementos válidos en 'segundo'.
 * @param destino Arreglo mutable donde se vuelca la fusión ordenada.
 * @param capacidad Capacidad máxima (en elementos) de 'destino'.
 *
 * @pre 'primero' y 'segundo' deben estar ordenados ascendentemente.
 * @post 'destino' contiene, en orden ascendente, tantos elementos de
 *       'primero' y 'segundo' como hayan podido volcarse sin exceder
 *       'capacidad'. Si 'capacidad' es insuficiente para volcar todos los
 *       elementos de ambos, el resto simplemente no se copia (truncamiento
 *       silencioso, informado a través del valor de retorno).
 *
 * @return La cantidad de elementos efectivamente volcados en 'destino'
 *         (siempre <= capacidad).
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad);

#endif 
