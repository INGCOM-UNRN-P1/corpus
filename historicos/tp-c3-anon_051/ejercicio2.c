
#include <stdio.h>
#include <stdlib.h>
typedef struct division
{
    int cociente;
    int resto;
}division_t;

typedef struct fraccion
{
    int dividendo;
    int divisor;
}fraccion_t;

division_t division_lenta(fraccion_t f1)
{
    
    int guardardivisor = 0;
    int resultado = 0;
    division_t div;
    div.cociente = 0;
    div.resto = 0;
    guardardivisor = f1.dividendo;
    resultado = f1.dividendo;
    while(abs(guardardivisor) >= abs(f1.divisor))
    {
        div.cociente = div.cociente + 1;
        guardardivisor = abs(guardardivisor) - abs(f1.divisor);
    }
    if(f1.dividendo < 0 || f1.divisor < 0)
    {
        if(f1.dividendo < 0 && f1.divisor < 0)
        {
            div.cociente = div.cociente *-1;
        }
        div.cociente = div.cociente *-1;
    }
    
    while(abs(resultado) >= abs(f1.divisor)){
        resultado = abs(resultado) - abs(f1.divisor);
    }
    if(f1.dividendo < 0 || f1.divisor < 0)
    {
        if(f1.dividendo < 0 && f1.divisor < 0)
        {
            resultado = resultado *-1;
        }
        resultado = resultado *-1;
    }
    div.resto = resultado;
    
    return div;
    
}

int main()
{    
    fraccion_t f1;
    printf("Ingrese un numero entero de dividendo: \n");
    scanf(" %d", &f1.dividendo);
    printf("Ingrese un numero entero de divisor: \n");
    scanf(" %d", &f1.divisor);
    
    division_t devolver = division_lenta(f1);
    printf("El cociente da : %d y el resto da : %d \n", devolver.cociente, devolver.resto);
}