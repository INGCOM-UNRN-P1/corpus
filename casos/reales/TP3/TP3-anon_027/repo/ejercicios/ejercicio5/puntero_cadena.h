#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>


 /** 
 * @brief Copia 'origen' en 'destino' utilizando exclusivamente 
 * aritmética de punteros.
 *
 * @param origen   arreglo a ser recorrido y copiado.
 * @param capacidad  define la cantidad de elementos de 'arreglo'.
 * @param destino puntero que guarda una copia de 'origen'.
 * 
 * @pre No está permitido utilizar Arreglos de Longitud Variable
 *       y/o memoria dinámica y hay que garantizar terminación 
 * nula '\0' dentro del rango seguro [0, capacidad - 1].
 * 
 * @return 'true' si cupo completa o 'false' si hubo truncamiento 
 * o parámetros inválidos.
 *
 * @post el resultado tiene que ser la copia de elementos
 * de 'origen' a 'destino' usando punteros:(*dst++ = *src++). 
 *
 * @invariant 'origen'.
 */
bool copiar_con_punteros(const char *origen, size_t capacidad, 
                     char *destino);
   
 
  


 /** 
 * @brief Avanza un puntero auxiliar hasta el terminador '\0'
 *  de destino y a continuación copia los caracteres de origen 
 * con punteros, respetando la capacidad máxima.
 *
 * @param origen cadena a ser recorrida y concatenada con 
 * 'destino'.
 * 
 * @param capacidad  define la cantidad de elementos de 'origen'.
 * @param destino cadena a ser concatenada con 'origen'.
 * 
 * @pre No está permitido utilizar Arreglos de Longitud Variable
 *       y/o memoria dinámica.También hay que garantizar 
 *      terminador nulo si 'capacidad' > 0.
 * 
 * @return 'true' si no truncó, 'false' si truncó.
 *
 * @post el resultado tiene que ser la fusión de 'origen' 
 * y 'destino'dentro de una capacidad preestablecida anteriormente.
 *
 * @invariant 'origen'.
*/
bool concatenar_con_punteros( const char *origen, size_t capacidad, 
                            char *destino);

#endif 
