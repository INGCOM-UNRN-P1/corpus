#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Copia 'cantidad' de elementos desde un arreglo de origen hacia uno de destino.
 *
 * @details Copia los datos elemento a elemento mediante aritmética de punteros,
 *          desplazando directamente los punteros de origen y destino con el
 *          operador de incremento (++).
 *
 * @param[in] origen Puntero constante al primer elemento del arreglo fuente.
 * @param[out] destino Puntero al primer elemento del arreglo donde se copiarán los datos.
 * @param[in] cantidad de elementos a copiar.
 *
 * @pre 'origen' debe apuntar a un arreglo con al menos 'cantidad' elementos válidos.
 * @pre 'destino' debe apuntar a un bloque de memoria con capacidad suficiente.
 * @post Si la función retorna true, el contenido de 'destino' será idéntico a 'origen'.
 *
 * @return 'true' si ambos punteros son distintos de NULL; 'false' en caso contrario.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);


/**
 * @brief Invierte los elementos de un arreglo in-place.
 *
 * @details Utiliza dos punteros (uno al inicio y otro al final del arreglo)
 *          que van convergiendo con 'inicio++' y 'fin--'. Intercambia los valores
 *          apuntados apoyándose en la función 'intercambiar'.
 *
 * @param[in,out] arreglo Puntero al primer elemento del arreglo a invertir.
 * @param[in] cantidad de elementos en el arreglo.
 *
 * @pre 'arreglo' debe apuntar a una dirección de memoria válida si 'cantidad' > 0.
 * @post Los elementos del arreglo quedan ordenados en sentido inverso.
 *
 * @return 'true' si 'arreglo' no es NULL; 'false' en caso contrario.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);


#endif 
