#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "estadistica.h"

#define EPSILON 0.001f

static bool son_cercanos(float obtenido, float esperado)
{
    return fabsf(obtenido - esperado) < EPSILON;
}

static void probar_calcular_promedio(void)
{
    
    assert(son_cercanos(calcular_promedio(15.0f, 3), 5.0f));
    assert(son_cercanos(calcular_promedio(10.0f, 4), 2.5f));

    
    assert(son_cercanos(calcular_promedio(42.0f, 1), 42.0f));

    
    assert(son_cercanos(calcular_promedio(-15.0f, 3), -5.0f));
    assert(son_cercanos(calcular_promedio(0.0f, 5), 0.0f));

    
    assert(son_cercanos(calcular_promedio(100.0f, 0), 0.0f));
    assert(son_cercanos(calcular_promedio(100.0f, -2), 0.0f));
}

static void probar_actualizar_minimo(void)
{
    
    assert(son_cercanos(actualizar_minimo(10.0f, 5.0f), 5.0f));
    assert(son_cercanos(actualizar_minimo(5.0f, 10.0f), 5.0f));

    
    assert(son_cercanos(actualizar_minimo(7.0f, 7.0f), 7.0f));

    
    assert(son_cercanos(actualizar_minimo(-2.0f, -10.0f), -10.0f));
    assert(son_cercanos(actualizar_minimo(-10.0f, -2.0f), -10.0f));

    
    assert(son_cercanos(actualizar_minimo(0.0f, 4.0f), 0.0f));
    assert(son_cercanos(actualizar_minimo(0.0f, -4.0f), -4.0f));
}

static void probar_actualizar_maximo(void)
{
    
    assert(son_cercanos(actualizar_maximo(10.0f, 15.0f), 15.0f));
    assert(son_cercanos(actualizar_maximo(15.0f, 10.0f), 15.0f));

    
    assert(son_cercanos(actualizar_maximo(8.0f, 8.0f), 8.0f));

    
    assert(son_cercanos(actualizar_maximo(-20.0f, -5.0f), -5.0f));
    assert(son_cercanos(actualizar_maximo(-5.0f, -20.0f), -5.0f));

    
    assert(son_cercanos(actualizar_maximo(0.0f, -5.0f), 0.0f));
    assert(son_cercanos(actualizar_maximo(0.0f, 5.0f), 5.0f));
}

int main(void)
{
    probar_calcular_promedio();
    probar_actualizar_minimo();
    probar_actualizar_maximo();
    printf("Todos los tests de estadistica pasaron correctamente.\n");
    return 0;
}
