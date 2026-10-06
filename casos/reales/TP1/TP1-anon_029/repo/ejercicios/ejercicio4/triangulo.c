#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0.0f || lado_b <= 0.0f || lado_c <= 0.0f)
    {
        return false;
    }
    if (lado_a >= (lado_b + lado_c) ||
        lado_b >= (lado_a + lado_c) ||
        lado_c >= (lado_a + lado_b))
    {
        return false;
    }
    else
    {
        return true;
    }
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
    else if (lado_a == lado_b || lado_b == lado_c || lado_a == lado_c)
    {
        return TIPO_ISOSCELES;
    }
    else
    {
        return TIPO_ESCALENO;
    }
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    if (es_triangulo_valido(lado_a, lado_b, lado_c) == false)
    {
        return TIPO_INVALIDO;
    }
    else if (((lado_a * lado_a) == ((lado_b * lado_b) + (lado_c * lado_c)))
    || ((lado_b * lado_b) == ((lado_a * lado_a) + (lado_c * lado_c)))
    || ((lado_c * lado_c) == ((lado_a * lado_a) + (lado_b * lado_b))))
    {
        return true;
    }
    else
    {
        return false;
    }
}
