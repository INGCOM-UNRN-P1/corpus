#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool lados_positivos = false;
    bool cumple_desigualdad = false;

    lados_positivos = lado_a > 0.0f
        && lado_b > 0.0f
        && lado_c > 0.0f;

    cumple_desigualdad = lado_a + lado_b > lado_c
        && lado_a + lado_c > lado_b
        && lado_b + lado_c > lado_a;

    return lados_positivos && cumple_desigualdad;
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
    bool es_rectangulo = false;

    if (es_triangulo_valido(lado_a, lado_b, lado_c))
    {
        float hipotenusa = lado_a;
        float cateto_uno = lado_b;
        float cateto_dos = lado_c;

        if (lado_b > hipotenusa)
        {
            hipotenusa = lado_b;
            cateto_uno = lado_a;
            cateto_dos = lado_c;
        }

        if (lado_c > hipotenusa)
        {
            hipotenusa = lado_c;
            cateto_uno = lado_a;
            cateto_dos = lado_b;
        }

        es_rectangulo = cateto_uno * cateto_uno
            + cateto_dos * cateto_dos
            == hipotenusa * hipotenusa;
    }

    return es_rectangulo;
}