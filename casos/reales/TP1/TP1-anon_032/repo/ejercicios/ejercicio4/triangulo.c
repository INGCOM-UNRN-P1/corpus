#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool cumple_desigualdad = false;
    if (lado_b + lado_c > lado_a &&
        lado_c + lado_a > lado_b &&
        lado_a + lado_b > lado_c)
    {
        cumple_desigualdad = true;
    }

    bool lados_validos = false;
    if (lado_a > 0 && lado_b > 0 && lado_c > 0)
    {
        lados_validos = true;
    }

    if (cumple_desigualdad && lados_validos)
    {
        return true;
    }
    return false;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    int tipo = TIPO_INVALIDO;

    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        if (lado_a == lado_b && lado_b == lado_c)
        {
            tipo = TIPO_EQUILATERO;
        }
        else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c)
        {
            tipo = TIPO_ISOSCELES;
        }
        else
        {
            tipo = TIPO_ESCALENO;
        }
    }

    return tipo;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        float raiz_cuadrada_a = lado_a * lado_a;
        float raiz_cuadrada_b = lado_b * lado_b;
        float raiz_cuadrada_c = lado_c * lado_c;
        //TODO: Implementar tolerancia
        if (raiz_cuadrada_a == raiz_cuadrada_b + raiz_cuadrada_c ||
            raiz_cuadrada_c == raiz_cuadrada_b + raiz_cuadrada_a ||
            raiz_cuadrada_b == raiz_cuadrada_a + raiz_cuadrada_c)
        {
            return true;
        }
    }

    return false;
}
