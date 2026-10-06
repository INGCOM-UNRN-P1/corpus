#include "triangulo.h"
#include <stdbool.h>

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0.0f || lado_b <= 0.0f || lado_c <= 0.0f)
    {
        return false;
    }

    return (lado_a + lado_b > lado_c) &&
           (lado_a + lado_c > lado_b) &&
           (lado_b + lado_c > lado_a);
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

    if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c)
    {
        return TIPO_ISOSCELES;
    }

    return TIPO_ESCALENO;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    float cuadrado_a = 0.0f;
    float cuadrado_b = 0.0f;
    float cuadrado_c = 0.0f;

    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return false;
    }

    cuadrado_a = lado_a * lado_a;
    cuadrado_b = lado_b * lado_b;
    cuadrado_c = lado_c * lado_c;

    return (cuadrado_a + cuadrado_b == cuadrado_c) ||
           (cuadrado_a + cuadrado_c == cuadrado_b) ||
           (cuadrado_b + cuadrado_c == cuadrado_a);
}