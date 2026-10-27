/**
 * @file conjunto.c
 * @brief Implementación del TDA Conjunto Finito con invariante de unicidad.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "conjunto.h"







conjunto_t *conjunto_crear(size_t capacidad)
{
    (void)capacidad;
    
    return NULL;
}

void conjunto_destruir(conjunto_t *c)
{
    (void)c;
    
}

size_t conjunto_cardinal(const conjunto_t *c)
{
    (void)c;
    
    return 0;
}

bool conjunto_esta_vacio(const conjunto_t *c)
{
    (void)c;
    
    return true;
}

bool conjunto_pertenece(const conjunto_t *c, int elemento)
{
    (void)c;
    (void)elemento;
    
    return false;
}

bool conjunto_es_subconjunto(const conjunto_t *a, const conjunto_t *b)
{
    (void)a;
    (void)b;
    
    return false;
}

bool conjunto_agregar(conjunto_t *c, int elemento)
{
    (void)c;
    (void)elemento;
    
    return false;
}

bool conjunto_eliminar(conjunto_t *c, int elemento)
{
    (void)c;
    (void)elemento;
    
    return false;
}

conjunto_t *conjunto_union(const conjunto_t *a, const conjunto_t *b)
{
    (void)a;
    (void)b;
    
    return NULL;
}

conjunto_t *conjunto_interseccion(const conjunto_t *a, const conjunto_t *b)
{
    (void)a;
    (void)b;
    
    return NULL;
}
