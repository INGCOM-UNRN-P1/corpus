/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);
int comprobar_divisor(int numero);
int convertir_a_positivo(int numero);

int main(int argc, char *argv[])
{

    int dividendo;
    int divisor;
    int cociente;
    int resto;

    printf("Ingrese el dividendo: \n\t");
    scanf("%d", &dividendo);
    printf("Ingrese el divisor: \n\t");
    scanf("%d", &divisor);

    if(comprobar_divisor(divisor) == 0)
    {
        printf("El divisor no puede ser 0!");
        return 0;
    }

    cociente = divide_lento(dividendo, divisor);
    resto = resto_lento(dividendo, divisor);
    printf("El cociente es: {%d} \nY el resto: {%d}", cociente, resto);

    
}

int comprobar_divisor(int numero)
{
    if(numero == 0)
    {
        return 0;
    }
    return 1;

}
int convertir_a_positivo(int numero)
{
    if(numero < 0)
    {
        numero = numero * -1;
        return numero;
    }
    return numero;
}

int divide_lento(int dividendo, int divisor)
{
    int i = 0;
    int cambio_signo = 1;
    if(dividendo == 0)
    {
        return 0;
    }
    if((dividendo * divisor) < 0)
    {
        cambio_signo = -1;
        dividendo = convertir_a_positivo(dividendo);
        divisor = convertir_a_positivo(divisor);
    }
    while(dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
        i++;
    }

    i = i * cambio_signo;
    return i;
}

int resto_lento(int dividendo, int divisor)
{
    int i = 0;
    if(dividendo == 0)
    {
        return 0;
    }
    if (dividendo < 0 || divisor < 0)
    {
        dividendo = convertir_a_positivo(dividendo);
        divisor = convertir_a_positivo(divisor);
    }

    while(dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
    }
    return dividendo;

}
