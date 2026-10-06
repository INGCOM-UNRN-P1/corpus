#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdbool.h>
#include <stddef.h>




const int *buscar_primero(const int *arreglo, size_t cantidad, int buscado);


ptrdiff_t distancia_punteros(const int *inicio, const int *elemento);

#endif 
