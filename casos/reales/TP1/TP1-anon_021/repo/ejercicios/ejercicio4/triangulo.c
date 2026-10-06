#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool valido=false;
    if(lado_a > 0.0f && lado_b > 0.0f && lado_c > 0.0f)
    {
        if ((lado_a + lado_b > lado_c)&& (lado_a + lado_c > lado_b)
            && (lado_b +lado_c > lado_a))//desigualdad triangular
        {
            valido= true;
        }
    }
    return valido;
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
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    bool es_rectangulo = false;

    if (es_triangulo_valido(lado_a, lado_b, lado_c))//evaluo pitagoras si es valido
    {
        float a2 = lado_a * lado_a;
        float b2 = lado_b * lado_b;
        float c2 = lado_c * lado_c;
        
        if ((a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2))
        {
            es_rectangulo = true;
        }
    }

    return es_rectangulo;
}