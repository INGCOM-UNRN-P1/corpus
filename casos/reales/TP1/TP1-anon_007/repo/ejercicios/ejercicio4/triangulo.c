#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool resultado = false;
    if (lado_a > 0 && lado_b > 0 && lado_c > 0)
    {
        if (lado_a < (lado_b + lado_c) && lado_b < (lado_a + lado_c) && lado_c < (lado_a + lado_b))
        {
            resultado = true;
        }
    }
    return resultado;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    int resultado = TIPO_INVALIDO;
    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        if (lado_a == lado_b && lado_b == lado_c)
        {
            resultado = TIPO_EQUILATERO;
        }
        else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c)
        {
            resultado = TIPO_ISOSCELES;
        }
        else
        {
            resultado = TIPO_ESCALENO;
        }
    }
    return resultado;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    bool resultado = false;
    int hipotenusa;
    int cateto1;
    int cateto2;
    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        hipotenusa = lado_a;
        for (int i = 0; i < 3; i++)
        {
            if (hipotenusa < lado_b)
            {
                hipotenusa = lado_b;
            }
            else if (hipotenusa < lado_c)
            {
                hipotenusa = lado_c;
            }
        }
        if (hipotenusa == lado_a)
        {
            cateto1 = lado_b;
            cateto2 = lado_c;
        }
        else if (hipotenusa == lado_b)
        {
            cateto1 = lado_a;
            cateto2 = lado_c;
        }
        else
        {
            cateto1 = lado_a;
            cateto2 = lado_b;
        }
        if ((hipotenusa * hipotenusa) == (cateto1 * cateto1) + (cateto2 * cateto2))
        {
            resultado = true;
        }
    }
    return resultado;
}
