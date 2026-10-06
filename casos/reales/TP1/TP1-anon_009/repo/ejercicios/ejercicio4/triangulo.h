#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <stdbool.h>

#define TIPO_INVALIDO 0
#define TIPO_EQUILATERO 1
#define TIPO_ISOSCELES 2
#define TIPO_ESCALENO 3


bool es_triangulo_valido(float lado_a, float lado_b, float lado_c);


int clasificar_triangulo(float lado_a, float lado_b, float lado_c);


bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c);

#endif 
