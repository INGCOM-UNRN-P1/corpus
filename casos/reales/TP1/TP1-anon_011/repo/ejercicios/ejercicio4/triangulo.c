#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool res = true;

    if (lado_a <= 0 || lado_b <= 0 || lado_c <= 0)
    {
        res = false;
    }

    if (lado_a >= lado_b + lado_c)
    {
        res = false;
    }

    if (lado_b >= lado_a + lado_c)
    {
        res = false;
    }

    if (lado_c >= lado_a + lado_b)
    {
        res = false;
    }

    return res;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    int res = TIPO_INVALIDO;

    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        if (lado_a == lado_b && lado_b == lado_c)
        {
            res = TIPO_EQUILATERO;
        }
        else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c)
        {
            res = TIPO_ISOSCELES;
        }
        else
        {
            res = TIPO_ESCALENO;
        }
    }

    return res;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    bool res = false;
    const float tolerancia = 0.0001f;

    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        float cuadrado_a = lado_a * lado_a;
        float cuadrado_b = lado_b * lado_b;
        float cuadrado_c = lado_c * lado_c;

        float diferencia_1 = cuadrado_a + cuadrado_b - cuadrado_c;
        float diferencia_2 = cuadrado_a + cuadrado_c - cuadrado_b;
        float diferencia_3 = cuadrado_b + cuadrado_c - cuadrado_a;

        if ((diferencia_1 >= -tolerancia) && (diferencia_1 <= tolerancia))
        {
            res = true;
        }
        else if ((diferencia_2 >= -tolerancia) && (diferencia_2 <= tolerancia))
        {
            res = true;
        }
        else if ((diferencia_3 >= -tolerancia) && (diferencia_3 <= tolerancia))
        {
            res = true;
        }
    }

    return res;
}