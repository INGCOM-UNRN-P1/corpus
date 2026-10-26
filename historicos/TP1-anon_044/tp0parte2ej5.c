/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_044
*************************/
#include <stdio.h>

int divisiones(int dividendo, int divisor, int op)
{
    
    volatile int i;
    volatile int cociente = -1;
    volatile int resto;
    volatile int ret;

    for(i = dividendo; i >= 0; i -= divisor)
    {
        cociente++;
    }
    resto = i + divisor;
    
    if(!op)
    {
        ret = cociente;
    }
    else 
    {
        ret = resto;
    }

    return ret;
}

int divide_lento(int dividendo, int divisor)
{
    return divisiones(dividendo, divisor, 0);
}

int resto_lento(int dividendo, int divisor)
{
    return divisiones(dividendo, divisor, 1);
}

int main()
{
    int dividendo, divisor;

    printf("Inserte el dividendo: ");
    scanf("%d", &dividendo);
    printf("Inserte el divisor: ");
    scanf("%d", &divisor);

    printf("cociente: %d\nresto:%d\n\n", divide_lento(dividendo, divisor), resto_lento(dividendo, divisor));

    return 0;
}
