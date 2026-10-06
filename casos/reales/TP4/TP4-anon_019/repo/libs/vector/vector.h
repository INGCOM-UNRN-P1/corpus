#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Reserva un bloque de memoria contigua en el heap inicializado en cero.
 * 
 * @param[in] cantidad Numero de enteros que contendra el bloque.
 * @return int* Puntero al bloque asignado, o NULL si la cantidad es 0 o falla la memoria.
 * 
 * #PRE La 'cantidad' debe ser mayor a 0.
 * #POST Retorna un puntero a un bloque de 'cantidad' enteros inicializados en 0.
 */
int *crear_bloque_enteros(size_t cantidad);

/**
 * @brief Libera la memoria de un bloque y anula el puntero original.
 * 
 * @param[in, out] puntero_bloque Doble puntero al bloque a liberar (int **).
 * 
 * #PRE 'puntero_bloque' no debe ser NULL.
 * #POST La memoria del bloque es liberada (si no era NULL) y el puntero original se anula a NULL.
 */
void liberar_bloque_enteros(int **puntero_bloque);

/**
 * @brief Cambia el tamano de un bloque de memoria previamente asignado.
 * 
 * @param[in] bloque Puntero al bloque original.
 * @param[in] nueva_cantidad Nuevo tamano en cantidad de enteros.
 * @return int* Puntero al nuevo bloque redimensionado, o NULL en caso de error.
 * 
 * #PRE 'nueva_cantidad' debe ser mayor a 0 para preservar el bloque.
 * #POST Si es exitoso, retorna el puntero al bloque redimensionado. Si 'nueva_cantidad' es 0, libera el bloque y retorna NULL.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);

/**
 * @brief Concatena dos bloques de memoria en un bloque nuevo.
 * 
 * @param[in] primero Puntero constante al primer bloque de enteros.
 * @param[in] cant_primero Cantidad de elementos del primer bloque.
 * @param[in] segundo Puntero constante al segundo bloque de enteros.
 * @param[in] cant_segundo Cantidad de elementos del segundo bloque.
 * @return int* Puntero al nuevo bloque fusionado, o NULL en caso de error.
 * 
 * #PRE 'cant_primero' + 'cant_segundo' > 0 y su suma no debe superar SIZE_MAX.
 * #POST Retorna un nuevo bloque en el heap con los elementos de 'primero' seguidos por los de 'segundo'.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo);

/**
 * @brief Agrega un nuevo valor al final del bloque, redimensionandolo automaticamente.
 * 
 * @param[in, out] puntero_bloque Doble puntero al bloque dinamico.
 * @param[in, out] cantidad Puntero a la variable que almacena la cantidad actual de elementos.
 * @param[in] valor El numero entero a insertar al final.
 * @return true si la insercion fue exitosa, false si fallo la reasignacion de memoria.
 * 
 * #PRE 'puntero_bloque' y 'cantidad' no deben ser NULL.
 * #POST Si es exitoso, el bloque se expande en 1, se anade 'valor' al final, se actualiza 'cantidad' y retorna true.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 