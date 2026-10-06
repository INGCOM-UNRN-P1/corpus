#include "triangulo.h"
#include <math.h>

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if(lado_a >= 0 && lado_b >= 0 && lado_c >= 0)
    {
        if((lado_a + lado_b > lado_c ) && (lado_b + lado_c > lado_a) && (lado_a + lado_c > lado_b))
        {
            return true;
        }
    }
    return false;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if(!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return TIPO_INVALIDO;
    }
    else if(lado_a == lado_b && lado_a == lado_c)
    {
        return TIPO_EQUILATERO;
    }
    else if((lado_a == lado_b && lado_a != lado_c) || (lado_a == lado_c && lado_a != lado_b) || (lado_b == lado_c && lado_a != lado_b))
    {
        return TIPO_ISOSCELES;
    }
    else if (lado_a != lado_b && lado_a != lado_c && lado_b != lado_c)
    {
        return TIPO_ESCALENO;
    }
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    if(es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        if(lado_a > lado_b && lado_a > lado_c)
        {
            float c = lado_a * lado_a;
            float a = lado_b * lado_b;
            float b = lado_c * lado_c;
            if(a + b == c)
            {
                return true;
            }
        }
        else if( lado_b > lado_a && lado_b > lado_c)
        {
            float c = lado_b * lado_b;
            float a = lado_a * lado_a;
            float b = lado_c * lado_c;
            if(a + b == c)
            {
                return true;
            }
        }
        else if(lado_c > lado_a && lado_c > lado_b)
        {
            float c = lado_c * lado_c;
            float a = lado_a * lado_a;
            float b = lado_b * lado_b;
            if(a + b == c)
            {
                return true;
            }
        }
    }
    return false;
}
