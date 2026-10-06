#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool positivo = (lado_a > 0.0f) && (lado_b > 0.0f) && (lado_c > 0.0f);
    bool desigualdad = (lado_a + lado_b > lado_c) && (lado_a + lado_c > lado_b) &&
         (lado_b + lado_c > lado_a);

    return (positivo && desigualdad);
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    int tipo = TIPO_INVALIDO;

    if (!es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        tipo = TIPO_INVALIDO;
    } 
    else if (lado_a == lado_b && lado_b == lado_c)
    {
        tipo = TIPO_EQUILATERO;
    } 
    else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c)
    {
        tipo = TIPO_ISOSCELES;
    } 
    else if (lado_a != lado_b && lado_b != lado_c)
    {
        tipo = TIPO_ESCALENO;
    }

    return tipo;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    bool es_rectangulo = false;

    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        float cateto_a = lado_a * lado_a;
        float cateto_b = lado_b * lado_b;
        float cateto_c = lado_c * lado_c;

        if (cateto_a + cateto_b == cateto_c || cateto_a + cateto_c == cateto_b || cateto_b + cateto_c == cateto_a)
        {
            es_rectangulo = true;
        }
    }

    return es_rectangulo;
}
