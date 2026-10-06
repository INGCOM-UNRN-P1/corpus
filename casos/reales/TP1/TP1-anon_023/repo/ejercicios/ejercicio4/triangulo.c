#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0.0f || lado_b <= 0.0f || lado_c <= 0.0f)
    {
        return false;
    }

    return (lado_a < lado_b + lado_c) &&
           (lado_b < lado_a + lado_c) &&
           (lado_c < lado_a + lado_b);
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return TIPO_INVALIDO;
    }

    if (lado_a == lado_b && lado_b == lado_c)
    {
        return TIPO_EQUILATERO;
    }

    if (lado_a == lado_b || lado_b == lado_c || lado_a == lado_c)
    {
        return TIPO_ISOSCELES;
    }

    return TIPO_ESCALENO;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return false;
    }

    float a2 = lado_a * lado_a;
    float b2 = lado_b * lado_b;
    float c2 = lado_c * lado_c;
    return (a2 == b2 + c2) || (b2 == a2 + c2) || (c2 == a2 + b2);
}
