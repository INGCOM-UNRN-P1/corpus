

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>



int *crear_bloque_enteros(size_t cantidad);



void liberar_bloque_enteros(int **puntero_bloque);



int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);



int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                               const int *segundo, size_t cant_segundo);



 
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
