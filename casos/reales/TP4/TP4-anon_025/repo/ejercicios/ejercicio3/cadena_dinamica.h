#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Clona una cadena origen reservando memoria dinamica exacta en el heap
 * 
 * @param origen Cadena a clonar
 * 
 * @return char* Nueva cedena en heap o NULL si hay error
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas reservadas en un epacio en el heap
 * 
 * @param primera Pimera parte de la cadena
 * @param segunda Segunda parte de la cadena
 * 
 * @return char* Nueva cadena combinada en heap o NULL si hay error
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
