#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    
    float a = 0.0;
    a = lado_a;
    
    float b = 0.0;
    b  = lado_b;
    
    float c = 0.0;
    c = lado_c;

    int contador = 0;
    float auxiliar = 0.0;
    bool terminar = true;
    while(contador < 3 && terminar != false)
    {
        float suma = 0.0;
        auxiliar = a;
        suma = a + b;
	terminar = suma > c;
        a = b;
        b = c;
	c = auxiliar;
	contador = contador + 1;
    }
	
    return terminar;
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    float a = 0.0;
    a = lado_a;
    
    float b = 0.0;
    b  = lado_b;
    
    float c = 0.0;
    c = lado_c;

    int salida = 0;
    bool evaluar_triangulo = false;
    evaluar_triangulo = es_triangulo_valido(a, b, c);
    if(evaluar_triangulo == true)
    {	    
        if((a == b) && (b == c))
        {
            salida = TIPO_EQUILATERO;
        }
        else if(((a == b) && (a != c)) || ((a == c) && (a != b)) || ((b == c) && (b != a)))
        {
            salida = TIPO_ISOSCELES;
        }  
        else
        {
            salida = TIPO_ESCALENO;
        }
    }
    else
    {
        salida = TIPO_INVALIDO;
    }
    return salida;
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    float a = 0.0;
    a = lado_a;
    float b = 0.0;
    b = lado_b;
    float c = 0.0;
    c = lado_c;
    
    float cuadrado_a = 0.0;
    cuadrado_a = a * a;
    
    float cuadrado_b = 0.0;
    cuadrado_b = b * b;

    float cuadrado_c = 0.0;
    cuadrado_c = c * c;
    
    int contador = 0;
    float auxiliar = 0.0;
    bool terminar = false;
    if((a > 0) && (b > 0) && (c > 0))
	    
    {
        while(contador < 3 && terminar != true)
        {
            auxiliar = cuadrado_a;
            float suma = 0.0;
            suma = cuadrado_a + cuadrado_b;
            if(suma == cuadrado_c)
            {
                contador = contador + 3;
                terminar = true;
            }
            cuadrado_a = cuadrado_b;
            cuadrado_b = cuadrado_c;
            cuadrado_c = auxiliar;
            contador = contador + 1;
        }
    }
    

    return terminar;
}

