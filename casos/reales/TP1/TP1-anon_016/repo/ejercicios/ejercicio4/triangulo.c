#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a > 0 && lado_b > 0 && lado_c > 0)
    {
        if (lado_a < lado_b + lado_c &&
        lado_b < lado_a + lado_c &&
        lado_c < lado_a + lado_b)
        {
            return true;
        }
    }

    return false;
    
   

}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if (es_triangulo_valido(lado_a, lado_b,lado_c) == false)
    {
        return TIPO_INVALIDO;
    }
    if(lado_a == lado_b && lado_a == lado_c && lado_b == lado_c)
    {
        return TIPO_EQUILATERO;
    }
    else if(lado_a == lado_b || lado_a == lado_c || lado_b == lado_c)
    {
        return TIPO_ISOSCELES;
    }
    else if (lado_a != lado_b && lado_a != lado_c && lado_b != lado_c)
    {
        return TIPO_ESCALENO;
    }
    
    (void)lado_a;
    (void)lado_b;
    (void)lado_c;
     return TIPO_INVALIDO;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
     if (es_triangulo_valido(lado_a, lado_b,lado_c) == false)
    {
        return false;
    }
    else if((lado_a * lado_a) == (lado_b * lado_b) + (lado_c * lado_c) ||
       (lado_b * lado_b) == (lado_a * lado_a) + (lado_c * lado_c) ||
       (lado_c * lado_c) == (lado_b * lado_b) + (lado_a * lado_a)  )
       {
         return true;
       }

    
    return false;
    (void)lado_a;
    (void)lado_b;
    (void)lado_c;
   
}
