/**
 * @file tiempo_seg.c
 * @brief Implementación B: Representación compacta (segundos totales).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "tiempo.h"






tiempo_t *tiempo_crear(unsigned int horas, unsigned int minutos, unsigned int segundos)
{
    (void)horas;
    (void)minutos;
    (void)segundos;
    
    return NULL;
}

void tiempo_destruir(tiempo_t *t)
{
    (void)t;
    
}

unsigned int tiempo_horas(const tiempo_t *t)
{
    (void)t;
    
    return 0;
}

unsigned int tiempo_minutos(const tiempo_t *t)
{
    (void)t;
    
    return 0;
}

unsigned int tiempo_segundos(const tiempo_t *t)
{
    (void)t;
    
    return 0;
}

unsigned long tiempo_en_segundos(const tiempo_t *t)
{
    (void)t;
    
    return 0;
}

void tiempo_incrementar(tiempo_t *t, unsigned int segundos_extra)
{
    (void)t;
    (void)segundos_extra;
    
}
