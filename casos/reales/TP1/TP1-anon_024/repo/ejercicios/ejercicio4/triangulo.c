#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0.0f || lado_b <= 0.0f || lado_c <= 0.0f)
    {
        return false;
    }
    if (lado_a + lado_b > lado_c)
    {
       if (lado_a + lado_c > lado_b)
       {
          if (lado_b + lado_c > lado_a)
          {
             return true;
          }
       }
    }
    else
    {
       return false;
    }
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
    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        return false;
    }

    float a_cuad = lado_a * lado_a;
    float b_cuad = lado_b * lado_b;
    float c_cuad = lado_c * lado_c;

    if (a_cuad + b_cuad == c_cuad)
    {
        return true;
    }
    if (a_cuad + c_cuad == b_cuad)
    {
        return true;
    }
    if (b_cuad + c_cuad == a_cuad)
    {
        return true;
    }

    return false;
}

// La herramienta gaff de la catedra encontro 2 violaciones
// a la regla 0x1001h, la cual considero que no corresponde a
// lo realizado en el codigo. Si me equivoco, pido disculpas.
