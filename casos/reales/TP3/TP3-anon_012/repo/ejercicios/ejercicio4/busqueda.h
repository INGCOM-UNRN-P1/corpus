#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>



/** 
* @brief Busca la primera aparición de un valor en un arreglo de enteros. 
* Recorre el arreglo mediante aritmética de punteros pura. Si encuentra el valor 
* buscado, retorna un puntero constante a dicha posición en memoria. 
* 
* @param arreglo Puntero al primer elemento del arreglo (lectura exclusivamente). 
* @param cantidad Cantidad de elementos a examinar en el arreglo. 
* @param valor Número entero que se desea localizar. 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a un bloque de memoria válido. 
* @post El contenido del arreglo permanece inalterado. 
* 
* @return Puntero constante (const int *) a la primera ubicación del valor hallado, 
* o NULL si el elemento no existe, si 'arreglo' es NULL o si 'cantidad' es 0. 
*/ 
const int *buscar_primero(const int *arreglo, size_t cantidad, int valor);

/** 
* @brief Calcula la distancia relativa o índice de un elemento respecto al inicio del arreglo.  
* 
* @param inicio Puntero constante a la dirección inicial del arreglo (lectura exclusivamente). 
* @param elemento Puntero constante a un elemento interno del arreglo (lectura exclusivamente). 
* 
* @pre Si ambos punteros son válidos, 'elemento' debe apuntar a 'inicio' o a una dirección posterior. 
* @post Ningún bloque de memoria resulta modificado. 
* 
* @return Distancia o índice en posiciones (ptrdiff_t >= 0), 
* o -1 si 'inicio' o 'elemento' son NULL o si 'elemento' apunta antes de 'inicio'. 
*/

ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
