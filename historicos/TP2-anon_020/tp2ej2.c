/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>
#include <stdlib.h>

int producto(int numero, int numero2)
{
    int i = 0;

    if(numero > 0)
    {
        while(numero > 0)
        {
            i = i + numero2;
            numero = numero - 1;
        }
    }
    else if(numero < 0)
    {
        while(numero < 0)
        {
            i = i - numero2;
            numero = numero + 1;
        }
    }
    else 
    {
        return 0;
    }

    return i;
}

int potencia(int numero, int numero2)
{
    int i = 1;

    if(numero > 0)
    {
        while(numero > 0)
        {
            i = producto(i, numero2);
            numero = numero - 1;
        }
    }
    else if(numero < 0)
    {
        while(numero < 0)
        {
            i = producto(i, numero2);
            numero = numero + 1;
        }
    }
    else
    {
        return 0;
    }
    return i;
}

 int main()
{
	int numero1, numero2, base, exponente, resultado1, resultado2;

	printf("\nIngrese el primer numero a multiplicar: ");
	scanf("%d", &numero1);
	printf("\nIngrese el segundo numero a multiplicar: ");
	scanf("%d", &numero2);

	resultado1 = producto(numero1, numero2);
	printf("\nEl resultado de multiplicar %d x %d es: %d", numero1, numero2, resultado1);

	printf("\nIngrese un numero a exponenciar: ");
	scanf("%d", &base);
	printf("\nIngrese el exponente: ");
	scanf("%d", &exponente);

	resultado2 = potencia(exponente, base);
	printf("\nEl resultado de %d elevado a %d es: %d",base, exponente, resultado2);

	return 0;
}
