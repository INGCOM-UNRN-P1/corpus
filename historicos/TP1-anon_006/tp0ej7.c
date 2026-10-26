/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/



#include <stdio.h>

double Factorial(int numero);

int main()
{
	int numero;
	double factorial;
	int i;
	
	printf("\nIngrese un numero para cualcular su factorial: ");
	scanf("%d", &numero);
	printf("\nEl numero ingresado es %d", numero);
	
	for(i=numero; i>0; i--)
	{
		factorial = Factorial(i);
		printf("\nEl factorial de %d! es: %.0lf", i, factorial);
	}
	
	printf("\n");
}

double Factorial(int numero)
{
	int i;
	double factorial = 1;
	
	for(i = 1; i<numero+1; i++)
	{
		factorial *= i;
	}	
	
	return factorial;
}
