#include "conversor.h"

#define FACTOR_NUMERADOR 9.0f
#define FACTOR_DENOMINADOR 5.0f
#define DESPLAZAMIENTO_FAHRENHEIT 32.0f

float celsius_a_fahrenheit(float celsius)
{
    float resultado = (celsius * FACTOR_NUMERADOR / FACTOR_DENOMINADOR)
        + DESPLAZAMIENTO_FAHRENHEIT;
    return resultado;
}

float fahrenheit_a_celsius(float fahrenheit)
{
    float resultado = (fahrenheit - DESPLAZAMIENTO_FAHRENHEIT)
        * FACTOR_DENOMINADOR / FACTOR_NUMERADOR;
    return resultado;
}
