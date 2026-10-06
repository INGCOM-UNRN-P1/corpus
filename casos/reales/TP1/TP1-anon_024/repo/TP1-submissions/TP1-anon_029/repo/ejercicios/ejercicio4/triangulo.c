#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
<<<<<<< HEAD
    (void)lado_a;
    (void)lado_b;
    (void)lado_c;
    return false;
=======
    if (lado_a <= 0.0f || lado_b <= 0.0f || lado_c <= 0.0f)
    {
        return false;
    }
    if (lado_a >= (lado_b + lado_c) ||
        lado_b >= (lado_a + lado_c) ||
        lado_c >= (lado_a + lado_b))
    {
        return false;
    }
    else
    {
        return true;
    }
>>>>>>> 45f4143 (Entrega tp 1 completa)
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
<<<<<<< HEAD
    (void)lado_a;
    (void)lado_b;
    (void)lado_c;
    return TIPO_INVALIDO;
=======
    if (es_triangulo_valido(lado_a, lado_b, lado_c) == false)
    {
        return TIPO_INVALIDO;
    }

    else if (lado_a == lado_b && lado_b == lado_c)
    {
        return TIPO_EQUILATERO;
    }
    else if (lado_a == lado_b || lado_b == lado_c || lado_a == lado_c)
    {
        return TIPO_ISOSCELES;
    }
    else
    {
        return TIPO_ESCALENO;
    }
>>>>>>> 45f4143 (Entrega tp 1 completa)
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
<<<<<<< HEAD
    (void)lado_a;
    (void)lado_b;
    (void)lado_c;
    return false;
=======
    if (es_triangulo_valido(lado_a, lado_b, lado_c) == false)
    {
        return TIPO_INVALIDO;
    }
    else if (((lado_a * lado_a) == ((lado_b * lado_b) + (lado_c * lado_c)))
    || ((lado_b * lado_b) == ((lado_a * lado_a) + (lado_c * lado_c)))
    || ((lado_c * lado_c) == ((lado_a * lado_a) + (lado_b * lado_b))))
    {
        return true;
    }
    else
    {
        return false;
    }
>>>>>>> 45f4143 (Entrega tp 1 completa)
}
