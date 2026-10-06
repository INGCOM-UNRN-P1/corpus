#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0 || lado_b <= 0 || lado_c <= 0)
    {
        return false;
    }
    else if (lado_a >= (lado_b + lado_c) || lado_b >= (lado_a + lado_c) || lado_c >= (lado_a + lado_b))
    {
        return false;
    }
    else
    {
        return true;
    }
    // (void)lado_a;
    // (void)lado_b;
    // (void)lado_c;
    // return false;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if (es_triangulo_valido(lado_a, lado_b, lado_c) == false)
    {
        return TIPO_INVALIDO;
    }
    else if (lado_a == lado_b && lado_b == lado_c)
    {
        return TIPO_EQUILATERO;
    }
    else if (lado_a != lado_b && lado_b != lado_c && lado_a != lado_c)
    {
        return TIPO_ESCALENO;
    }
    else
    {
        return TIPO_ISOSCELES;
    }
    // (void)lado_a;
    // (void)lado_b;
    // (void)lado_c;
    // return TIPO_INVALIDO;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    float a_cuadrado = ((int)(lado_a * lado_a * 100)) / 100;
    float b_cuadrado = ((int)(lado_b * lado_b * 100)) / 100;
    float c_cuadrado = ((int)(lado_c * lado_c * 100)) / 100;
    if (es_triangulo_valido(lado_a, lado_b, lado_c) == false)
    {
        return false;
    }
    else if (a_cuadrado == (b_cuadrado + c_cuadrado) ||
        b_cuadrado == (a_cuadrado + c_cuadrado) ||
        c_cuadrado == (a_cuadrado + b_cuadrado))
    {
        return true;
    }
    else
    {
        return false;
    }
    
    // (void)lado_a;
    // (void)lado_b;
    // (void)lado_c;
    // return false;
}
