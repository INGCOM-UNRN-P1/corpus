#include "triangulo.h"
#include <math.h>
#define EPSILON 0.0001f

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a <= 0.0f || lado_b <=0.0f || lado_c <=0.0f){
        return false;
    }
    return (lado_a + lado_b > lado_c) && (lado_a + lado_c > lado_b) && (lado_b + lado_c > lado_a);
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if (!es_triangulo_valido(lado_a, lado_b, lado_c)){
        return TIPO_INVALIDO;
    }

    if (lado_a == lado_b && lado_b == lado_c){
        return TIPO_EQUILATERO;
    } else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c){
        return TIPO_ISOSCELES;
    } else{
        return TIPO_ESCALENO;
    }
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    if (!es_triangulo_valido(lado_a, lado_b, lado_c)){
        return false;
    }

    float lado_a_cuadrado = lado_a * lado_a;
    float lado_b_cuadrado = lado_b * lado_b;
    float lado_c_cuadrado = lado_c * lado_c;

    return (fabsf((lado_a_cuadrado + lado_b_cuadrado) - lado_c_cuadrado) < EPSILON) || (fabsf((lado_a_cuadrado + lado_c_cuadrado) - lado_b_cuadrado) < EPSILON) ||(fabsf((lado_b_cuadrado + lado_c_cuadrado) - lado_a_cuadrado) < EPSILON);
}
