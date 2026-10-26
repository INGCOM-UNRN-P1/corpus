/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>

int factorial(int numero);
int producto(int factor, int otrofactor);


int main()
{
	int numero;
	int resultado;
	
	printf("Ingrese un numero natural --> ");
	scanf("%d", &numero);
	
	resultado = factorial(numero);
	printf("El factorial de %d es: %d", numero, resultado);
}


int factorial(int numero)
{
	int i = 1;
	int factorial = 1;

	for (i; i <= numero; i++)
	{
		factorial = producto(factorial, i);
	}
	return factorial;
}



int producto(int factor, int otrofactor)
{
	int i = 1;
	int res = factor;

	for (i; i < otrofactor; i++)
	{
		res = res + factor;
	}
	return res;
}