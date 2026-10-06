#include "triangulo.h"

bool es_triangulo_valido(float lado_a, float lado_b, float lado_c)
{
    if (lado_a > 0 && lado_b > 0 && lado_c > 0){
        if ((lado_a + lado_b)> lado_c){
            if ((lado_a + lado_c)> lado_b)
            {
                if ((lado_b + lado_c)>lado_a){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
            
        }else{
            return false;
        }
    } else{
        return false;
    }
}

int clasificar_triangulo(float lado_a, float lado_b, float lado_c)
{
    if(es_triangulo_valido(lado_a, lado_b, lado_c) == true){
        if(lado_a == lado_b && lado_a == lado_c){
            return TIPO_EQUILATERO;
        } else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c){
            return TIPO_ISOSCELES;
        } else{
            return TIPO_ESCALENO;
        }
    }else {
    return TIPO_INVALIDO;
    }
}

bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c)
{
    if (es_triangulo_valido (lado_a , lado_b, lado_c) == true){
        float lado_a_cuadrado = lado_a * lado_a;
        float lado_b_cuadrado = lado_b * lado_b;
        float lado_c_cuadrado = lado_c * lado_c;
        if(lado_a_cuadrado == (lado_b_cuadrado + lado_c_cuadrado) || 
             lado_b_cuadrado == (lado_a_cuadrado + lado_c_cuadrado) || 
             lado_c_cuadrado == (lado_a_cuadrado + lado_b_cuadrado)){
            return true;
        } else{
            return false;
        }
    }else{
        return false;
    }
    
}
