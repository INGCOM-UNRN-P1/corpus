#include "triangulo.h"
#include <math.h>

#define TOLERANCIA_PITAGORAS 0.001f

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    bool lados_positivos = lado_a > 0.0f && lado_b > 0.0f && lado_c > 0.0f;
    bool desigualdad_triangular = lado_a < lado_b + lado_c
        && lado_b < lado_a + lado_c
        && lado_c < lado_a + lado_b;

    return lados_positivos && desigualdad_triangular;
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
        else if (lado_a == lado_b || lado_b == lado_c || lado_a == lado_c)
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
        float mayor = lado_a;
        float menor_1 = lado_b;
        float menor_2 = lado_c;

        if (lado_b > mayor)
        {
            mayor = lado_b;
            menor_1 = lado_a;
            menor_2 = lado_c;
        }
        if (lado_c > mayor)
        {
            mayor = lado_c;
            menor_1 = lado_a;
            menor_2 = lado_b;
        }

        float suma_catetos_cuadrado = menor_1 * menor_1 + menor_2 * menor_2;
        float hipotenusa_cuadrado = mayor * mayor;
        float diferencia = fabsf(suma_catetos_cuadrado - hipotenusa_cuadrado);

        es_rectangulo = diferencia < TOLERANCIA_PITAGORAS * hipotenusa_cuadrado;
    }

    return es_rectangulo;
}
