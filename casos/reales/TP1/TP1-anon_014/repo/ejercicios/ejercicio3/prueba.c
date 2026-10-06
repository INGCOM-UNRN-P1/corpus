#include <assert.h>
#include <stdio.h>

#include "fecha.h"

static void probar_es_bisiesto(void)
{
    
    assert(es_bisiesto(2024));
    assert(es_bisiesto(2020));

    
    assert(!es_bisiesto(2026));
    assert(!es_bisiesto(2023));

    
    assert(es_bisiesto(2000));
    assert(es_bisiesto(1600));

    
    assert(!es_bisiesto(1900));
    assert(!es_bisiesto(2100));
    assert(!es_bisiesto(1800));
}

static void probar_dias_en_mes(void)
{
    
    assert(dias_en_mes(1, 2026) == 31);
    assert(dias_en_mes(3, 2026) == 31);
    assert(dias_en_mes(5, 2026) == 31);
    assert(dias_en_mes(7, 2026) == 31);
    assert(dias_en_mes(8, 2026) == 31);
    assert(dias_en_mes(10, 2026) == 31);
    assert(dias_en_mes(12, 2026) == 31);

    
    assert(dias_en_mes(4, 2026) == 30);
    assert(dias_en_mes(6, 2026) == 30);
    assert(dias_en_mes(9, 2026) == 30);
    assert(dias_en_mes(11, 2026) == 30);

    
    assert(dias_en_mes(2, 2024) == 29);
    assert(dias_en_mes(2, 2000) == 29);
    assert(dias_en_mes(2, 2026) == 28);
    assert(dias_en_mes(2, 1900) == 28);

    
    assert(dias_en_mes(0, 2026) == 0);
    assert(dias_en_mes(13, 2026) == 0);
    assert(dias_en_mes(-5, 2026) == 0);
}

static void probar_es_fecha_valida(void)
{
    
    assert(es_fecha_valida(1, 1, 2026));
    assert(es_fecha_valida(31, 1, 2026));
    assert(es_fecha_valida(30, 4, 2026));
    assert(es_fecha_valida(28, 2, 2023));
    assert(es_fecha_valida(29, 2, 2024));
    assert(es_fecha_valida(29, 2, 2000));

    
    assert(!es_fecha_valida(29, 2, 2023));
    assert(!es_fecha_valida(29, 2, 1900));

    
    assert(!es_fecha_valida(31, 4, 2024));
    assert(!es_fecha_valida(32, 1, 2026));
    assert(!es_fecha_valida(0, 5, 2026));
    assert(!es_fecha_valida(-1, 5, 2026));

    
    assert(!es_fecha_valida(15, 0, 2026));
    assert(!es_fecha_valida(15, 13, 2026));

    
    assert(!es_fecha_valida(1, 1, 0));
    assert(!es_fecha_valida(1, 1, -2026));
}

int main(void)
{
    probar_es_bisiesto();
    probar_dias_en_mes();
    probar_es_fecha_valida();
    printf("Todos los tests de fecha pasaron correctamente.\n");
    return 0;
}
