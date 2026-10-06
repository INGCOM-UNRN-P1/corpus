#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0 || lado_b <= 0 || lado_c <= 0)
    {
        return false;
    }

    if (lado_a + lado_b <= lado_c)
    {
        return false;
    }

    if(lado_a + lado_c <= lado_b)
    {
        return false;
    }

    if (lado_b + lado_c <= lado_a)
    {
        return false;
    }

    return true;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return TIPO_INVALIDO;
    }

    bool ab_iguales = lado_a == lado_b;
    bool bc_iguales = lado_b == lado_c;
    bool ac_iguales = lado_a == lado_c;

    if (ab_iguales && bc_iguales && ac_iguales)
    {
        return TIPO_EQUILATERO;
    }

    if (ab_iguales || bc_iguales || ac_iguales)
    {
        return TIPO_ISOSCELES;
    }

    return TIPO_ESCALENO;

}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    float a_cuadrado;
    float b_cuadrado;
    float c_cuadrado;

    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return false;
    }
    
    a_cuadrado = ((float)(int)(lado_a * lado_a * 100)) / 100.0f;
    b_cuadrado = ((float)(int)(lado_b * lado_b * 100)) / 100.0f;
    c_cuadrado = ((float)(int)(lado_c * lado_c * 100)) / 100.0f;

    return (a_cuadrado == b_cuadrado + c_cuadrado) ||
           (b_cuadrado == a_cuadrado + c_cuadrado) ||
           (c_cuadrado == a_cuadrado + b_cuadrado);
}