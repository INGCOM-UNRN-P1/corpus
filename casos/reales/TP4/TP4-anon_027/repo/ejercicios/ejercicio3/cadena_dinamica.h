#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

  
 /** 
 * @brief Calcula su longitud exacta, reserva memoria dinámica en el 
 * heap mediante malloc (longitud + 1 para '\0'), copia la cadena y 
 * retorna el puntero char *
 *
 * @param origen cadena a ser copiada en heap.
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free`.
 * 
 * @return NULL si origen es NULL o falla la
 * asignación.
 *
 * @post debe retornar la cadena clonada en el heap con 
 * el terminador nulo incluido.
 *
 * @invariant 'origen'
*/
char* clonar_cadena(const char *origen);
 

 

 /** 
 * @brief Calcula la longitud combinada necesaria, reserva memoria 
 * exacta en el heap y retorna una nueva cadena con la concatenación 
 * de ambas finalizada en '\0'.
 *
 * @param primera cadena a concatenar con 'segunda'
 * @param segunda cadena a concantenar con 'primera'
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free`.
 * 
 * @return NULL si alguna entrada es NULL o falla la reserva.
 *
 * @post debe retornar una nueva cadena concatenada en heap con su 
 * contenido de 'primera' y 'segunda' finalizado de '\0'
 *
 * @invariant 'primera' y 'segunda'
*/
char* unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
