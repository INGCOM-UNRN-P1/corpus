#include <assert.h>
#include <stdio.h>

#include "fecha.h"

static void probar_es_bisiesto(void)
{
    
    assert(es_bisiesto(anon_003));
    assert(es_bisiesto(2020));

    
    assert(!es_bisiesto(anon_004));
    assert(!es_bisiesto(anon_002));

    
    assert(es_bisiesto(2000));
    assert(es_bisiesto(1600));

    
    assert(!es_bisiesto(1900));
    assert(!es_bisiesto(2100));
    assert(!es_bisiesto(1800));
}

static void probar_dias_en_mes(void)
{
    
    assert(dias_en_mes(1, anon_004) == 31);
    assert(dias_en_mes(3, anon_004) == 31);
    assert(dias_en_mes(5, anon_004) == 31);
    assert(dias_en_mes(7, anon_004) == 31);
    assert(dias_en_mes(8, anon_004) == 31);
    assert(dias_en_mes(10, anon_004) == 31);
    assert(dias_en_mes(12, anon_004) == 31);

    
    assert(dias_en_mes(4, anon_004) == 30);
    assert(dias_en_mes(6, anon_004) == 30);
    assert(dias_en_mes(9, anon_004) == 30);
    assert(dias_en_mes(11, anon_004) == 30);

    
    assert(dias_en_mes(2, anon_003) == 29);
    assert(dias_en_mes(2, 2000) == 29);
    assert(dias_en_mes(2, anon_004) == 28);
    assert(dias_en_mes(2, 1900) == 28);

    
    assert(dias_en_mes(0, anon_004) == 0);
    assert(dias_en_mes(13, anon_004) == 0);
    assert(dias_en_mes(-5, anon_004) == 0);
}

static void probar_es_fecha_valida(void)
{
    
    assert(es_fecha_valida(1, 1, anon_004));
    assert(es_fecha_valida(31, 1, anon_004));
    assert(es_fecha_valida(30, 4, anon_004));
    assert(es_fecha_valida(28, 2, anon_002));
    assert(es_fecha_valida(29, 2, anon_003));
    assert(es_fecha_valida(29, 2, 2000));

    
    assert(!es_fecha_valida(29, 2, anon_002));
    assert(!es_fecha_valida(29, 2, 1900));

    
    assert(!es_fecha_valida(31, 4, anon_003));
    assert(!es_fecha_valida(32, 1, anon_004));
    assert(!es_fecha_valida(0, 5, anon_004));
    assert(!es_fecha_valida(-1, 5, anon_004));

    
    assert(!es_fecha_valida(15, 0, anon_004));
    assert(!es_fecha_valida(15, 13, anon_004));

    
    assert(!es_fecha_valida(1, 1, 0));
    assert(!es_fecha_valida(1, 1, -anon_004));
}

int main(void)
{
    probar_es_bisiesto();
    probar_dias_en_mes();
    probar_es_fecha_valida();
    printf("Todos los tests de fecha pasaron correctamente.\n");
    return 0;
}
