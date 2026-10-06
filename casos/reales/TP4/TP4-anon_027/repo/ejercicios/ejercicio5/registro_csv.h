#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>


 
 /** 
 * @brief recibe const char *linea y char delimitador, junto con
 * un puntero de salida size_t *cantidad_tokens. Separa la línea en sus 
 * diferentes campos, asignando en el heap un arreglo de punteros a cadena 
 * (char **) donde cada elemento apunta a una cadena clonada en heap con 
 * malloc (duplicada con terminador '\0').
 *
 * @param linea cadena a ser modificada 
 * @param delimitador delimita la capacidad de 'cadena'
 * @param cantidad_tokens puntero de salida
 * @pre se debe implementar la tokenización dinámica de una línea CSV  
 * sin utilizar structs.
 * 
 * @return char** o NULL si falla la asignación o la línea es NULL.
 *
 * @post separa la línea en sus diferentes campos y asigna en heap
 * un arreglo de punteros a cadena donde cada elemento apunta a una
 * cadena clonada en heap.
 *
 * @invariant *linea
*/
 char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);
 

/**
 * @brief recibe char ***puntero_arreglo y size_t cantidad.
 * Libera primero cada cadena individual con free, luego libera 
 * el arreglo de punteros, y asigna *puntero_arreglo = NULL.
 *
 * @param puntero_arreglo arreglo a ser liberado.
 * @param cantidad define la capacidad de '***puntero_arreglo'
 * 
 * @pre debe asignarse el puntero a NULL y 'cantidad = 0'
 * una vez liberada su cadena
 * 
 * @return ----------------------------------------------------------
 *
 * @post la función libera la cadena y deja '***puntero_arreglo' 
 * asignado a NULL y su cantidad igual a cero.
 *
 * @invariant -----------------------------------------------------
*/
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);


#endif 
