#include <assert.h>
#include <stdio.h>
#include "consola.h"

static void probar_esta_en_rango_entero(void)
{
    
    assert(esta_en_rango_entero(10, 10, 20));
    assert(esta_en_rango_entero(15, 10, 20));
    assert(esta_en_rango_entero(20, 10, 20));
    assert(!esta_en_rango_entero(9, 10, 20));
    assert(!esta_en_rango_entero(21, 10, 20));

    
    assert(esta_en_rango_entero(-5, -5, 5));
    assert(esta_en_rango_entero(0, -5, 5));
    assert(esta_en_rango_entero(5, -5, 5));
    assert(!esta_en_rango_entero(-6, -5, 5));
    assert(!esta_en_rango_entero(6, -5, 5));

    
    assert(esta_en_rango_entero(-20, -20, -10));
    assert(esta_en_rango_entero(-15, -20, -10));
    assert(esta_en_rango_entero(-10, -20, -10));
    assert(!esta_en_rango_entero(-21, -20, -10));
    assert(!esta_en_rango_entero(-9, -20, -10));

    
    assert(esta_en_rango_entero(7, 7, 7));
    assert(!esta_en_rango_entero(6, 7, 7));
    assert(!esta_en_rango_entero(8, 7, 7));

    
    assert(!esta_en_rango_entero(10, 20, 10));
}

static void probar_esta_en_rango_flotante(void)
{
    
    assert(esta_en_rango_flotante(1.5f, 1.5f, 4.5f));
    assert(esta_en_rango_flotante(3.0f, 1.5f, 4.5f));
    assert(esta_en_rango_flotante(4.5f, 1.5f, 4.5f));
    assert(!esta_en_rango_flotante(1.49f, 1.5f, 4.5f));
    assert(!esta_en_rango_flotante(4.51f, 1.5f, 4.5f));

    
    assert(esta_en_rango_flotante(-2.5f, -2.5f, 2.5f));
    assert(esta_en_rango_flotante(0.0f, -2.5f, 2.5f));
    assert(esta_en_rango_flotante(2.5f, -2.5f, 2.5f));
    assert(!esta_en_rango_flotante(-2.51f, -2.5f, 2.5f));
    assert(!esta_en_rango_flotante(2.51f, -2.5f, 2.5f));

    
    assert(esta_en_rango_flotante(-10.5f, -10.5f, -5.5f));
    assert(esta_en_rango_flotante(-7.2f, -10.5f, -5.5f));
    assert(esta_en_rango_flotante(-5.5f, -10.5f, -5.5f));
    assert(!esta_en_rango_flotante(-10.51f, -10.5f, -5.5f));
    assert(!esta_en_rango_flotante(-5.49f, -10.5f, -5.5f));

    
    assert(esta_en_rango_flotante(0.0f, 0.0f, 0.0f));
    assert(!esta_en_rango_flotante(0.001f, 0.0f, 0.0f));
    assert(!esta_en_rango_flotante(-0.001f, 0.0f, 0.0f));

    
    assert(!esta_en_rango_flotante(5.0f, 10.0f, 2.0f));
}

int main(void)
{
    printf("Ejecutando pruebas unitarias de la libreria consola...\n");
    probar_esta_en_rango_entero();
    probar_esta_en_rango_flotante();
    printf("Todos los tests de la libreria consola pasaron exitosamente.\n");
    return 0;
}
