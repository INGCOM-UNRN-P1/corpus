/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_023
*************************/
#include <stdio.h>
#include <stdlib.h>

int producto(int numero, int numero2)
{
	int i, resultado;
	resultado = 0;

	if(numero > 0 && numero2 > 0)
	{
		for(i=0;i<numero2;i++)
		{
			resultado = resultado + numero;
		}
		return resultado;
	}
	else 
	{
		printf("Alguno de los numeros ingresados no es un numero natural.");
		return 0;
	}
}

int potencia(int numero, int numero2)
{
	int i, resultado;
	resultado = 1;

	if(numero > 0 && numero2 >0)
	{
		for(i=0;i<numero2;i++)
		{
			resultado = producto(resultado,numero);
		}
		return resultado;
	}
	else 
	{
		printf("Alguno de los numeros ingresados no es un numero natural.");
		return 0;
	}
}

int main(int argc, char *argv[])
{
	int numero1, numero2, resultado1, resultado2;

	printf("\nIngrese numero natural n: ");
	scanf("%d", &numero1);
	printf("\nIngrese numero natural m: ");
	scanf("%d", &numero2);

	resultado1 = producto(numero1, numero2);
	resultado2 = potencia(numero1, numero2);
	printf("\n%d x %d = %d", numero1, numero2, resultado1);
	printf("\n%d ^ %d = %d",numero1, numero2, resultado2);

	return 0;
}
