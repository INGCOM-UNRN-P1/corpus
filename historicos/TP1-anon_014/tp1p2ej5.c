/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int numero, otronumero, cociente, resto;
    printf("Ingrese el dividendo: ");
    scanf("%d", &numero);
    
    printf("Ingrese el divisor: ");
    scanf("%d", &otronumero);
    
    cociente = divide_lento(numero, otronumero);
    
    resto = resto_lento(numero, otronumero);
    
    printf("El cociente entre %d y %d es: %d y" 
    " tiene resto de: %d", numero, otronumero, cociente, resto);
}

int divide_lento(int dividendo, int divisor)
{
    int cociente = 0;
    
    while(dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
        cociente = cociente + 1;
    }
    return cociente;
   
}

int resto_lento(int dividendo, int divisor)
{
    int resto = 0;
    
    while(dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
        resto = dividendo;
    }
    return resto;
}
