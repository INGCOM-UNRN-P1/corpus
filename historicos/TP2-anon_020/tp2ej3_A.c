
#include <stdio.h>
#include <stdlib.h>


int factorial(int numero)
{
	int calculo_fact = 1, i;

	for(i = 1; i <= numero; i++)
	{
		calculo_fact  = calculo_fact * i;
	}

	return calculo_fact;
}

int main()
{
	int numero, resultado;
	printf("\nIngrese un entero para calcular su factorial: ");
	scanf("%d", &numero);

	resultado = factorial(numero);

	printf("\nEl factorial de %d! es: %d\n", numero, resultado);

	return 0;
}