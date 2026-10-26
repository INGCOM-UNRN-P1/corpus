/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{
    int numero1, numero2, cociente, resto;

    do {
        printf("Ingrese un numero natural: ");
        scanf("%d", &numero1);
    } while(numero1 <= 0);
    do {
        printf("Ingrese un numero natural: ");
        scanf("%d", &numero2);
    } while(numero2 <= 0);

    cociente = divide_lento(numero1, numero2);
    resto = resto_lento(numero1, numero2);

    printf("Division: %d/%d\nCociente: %d\nResto: %d\n", numero1, numero2, cociente, resto);

    return 1;
}

int divide_lento(int dividendo, int divisor)
{
    int cociente = 0;

    while(dividendo > divisor)
    {
        dividendo -= divisor;
        cociente++;
    }
    return cociente;
}

int resto_lento(int dividendo, int divisor)
{
    while(dividendo > divisor)
        dividendo -= divisor;

    return dividendo;
}
