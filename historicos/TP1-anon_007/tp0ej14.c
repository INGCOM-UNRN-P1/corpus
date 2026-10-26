/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);
int main(int argc, char *argv[])
{
	int dividendo;
	int divisor;
	int mostrar_division;
	int mostrar_resto;
	printf("Ingrese su dividendo: ");
	fflush(stdout);
	scanf("%d", &dividendo);
	while(1)
	{
		printf("Ingrese su divisor: ");
		fflush(stdout);
		scanf("%d", &divisor);
		if (divisor <= 0)
		{
			printf("Debe ser un numero natural mayor a 0. \n");
		}
		else
		{
			if (dividendo < divisor)
			{
				printf("El dividendo no puede ser menor que el divisor. \n");
			}
			else
			{
				break;
			}
		}
	}
	mostrar_division = divide_lento(dividendo, divisor);
	mostrar_resto = resto_lento(dividendo, divisor);
	printf("Resultado:    %d/%d = %d   RESTO: %d", dividendo, divisor, mostrar_division, mostrar_resto);
}
int divide_lento(int dividendo, int divisor)
{
	int i;
	for (i = 0; dividendo >= divisor; i++)
	{
		dividendo = dividendo - divisor;
	}
	return i;
}
int resto_lento(int dividendo, int divisor)
{
	int i;
	for (i = 0; dividendo >= divisor; i++)
	{
		dividendo = dividendo - divisor;
	}
	return dividendo;	
}