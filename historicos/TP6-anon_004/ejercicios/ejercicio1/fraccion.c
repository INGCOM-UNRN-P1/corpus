/**
 * @file fraccion.c
 * @brief Implementación del TDA Fracción con invariante de representación.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "fraccion.h"





static int mcd(int a, int b)
{
    (void)a;
    (void)b;
    
    return 1;
}

static bool fraccion_invariante(const fraccion_t *f)
{
    (void)f;
    (void)mcd;
    
    return true;
}

fraccion_t *fraccion_crear(int numerador, int denominador)
{
    (void)numerador;
    (void)denominador;
    (void)fraccion_invariante;
    
    return NULL;
}

void fraccion_destruir(fraccion_t *f)
{
    (void)f;
    
}

int fraccion_numerador(const fraccion_t *f)
{
    (void)f;
    
    return 0;
}

int fraccion_denominador(const fraccion_t *f)
{
    (void)f;
    
    return 1;
}

bool fraccion_es_entera(const fraccion_t *f)
{
    (void)f;
    
    return false;
}

int fraccion_comparar(const fraccion_t *f1, const fraccion_t *f2)
{
    (void)f1;
    (void)f2;
    
    return 0;
}

fraccion_t *fraccion_sumar(const fraccion_t *f1, const fraccion_t *f2)
{
    (void)f1;
    (void)f2;
    
    return NULL;
}

fraccion_t *fraccion_multiplicar(const fraccion_t *f1, const fraccion_t *f2)
{
    (void)f1;
    (void)f2;
    
    return NULL;
}

double fraccion_a_real(const fraccion_t *f)
{
    (void)f;
    
    return 0.0;
}

char *fraccion_a_cadena(const fraccion_t *f)
{
    (void)f;
    
    return NULL;
}
