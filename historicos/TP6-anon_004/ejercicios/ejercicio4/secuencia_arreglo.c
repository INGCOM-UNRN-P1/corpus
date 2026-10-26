/**
 * @file secuencia_arreglo.c
 * @brief Implementación del TDA Secuencia sobre memoria contigua (Arreglo dinámico).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "secuencia.h"






secuencia_t *secuencia_crear(size_t capacidad)
{
    (void)capacidad;
    
    return NULL;
}

void secuencia_destruir(secuencia_t *sec)
{
    (void)sec;
    
}

bool secuencia_obtener(const secuencia_t *sec, size_t indice, int *destino)
{
    (void)sec;
    (void)indice;
    (void)destino;
    
    return false;
}

size_t secuencia_largo(const secuencia_t *sec)
{
    (void)sec;
    
    return 0;
}

bool secuencia_esta_vacia(const secuencia_t *sec)
{
    (void)sec;
    
    return true;
}

bool secuencia_insertar(secuencia_t *sec, size_t pos, int valor)
{
    (void)sec;
    (void)pos;
    (void)valor;
    
    return false;
}

bool secuencia_eliminar(secuencia_t *sec, size_t pos, int *dato_extraido)
{
    (void)sec;
    (void)pos;
    (void)dato_extraido;
    
    return false;
}

char *secuencia_a_cadena(const secuencia_t *sec)
{
    (void)sec;
    
    return NULL;
}
