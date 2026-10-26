/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long long int numero;
	unsigned long long int multiplicar;
	unsigned long long int factorial;
	int decreciente = 1;
	printf("Ingrese un numero entero para saber su factorial: !");
	scanf("%llu", &numero);
	while(numero >= decreciente)
	{
		factorial = 1;
		for (multiplicar = 1; multiplicar <= numero; multiplicar++)
		{
			factorial = factorial * multiplicar;
		}
		numero = numero - 1;
		printf("El factorial de %llu es: %llu\n", numero+1, factorial);
	}
	
	return 0;
}
