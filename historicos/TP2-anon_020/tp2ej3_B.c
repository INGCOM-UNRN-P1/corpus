
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
int combinatorio(int n, int k)
{
	int formula;

	if(k <= n)
	{
		formula = factorial(n)/(factorial(k) * factorial(n - k));
	}
	else
	{
		return -1;
	}

	return formula;
}

int main()
{
	int n, k, resultado;

	printf("\nIngrese el valor de n: ");
	scanf("%d", &n);
	printf("\nIngrese el valor de k: ");
	scanf("%d", &k);

	resultado = combinatorio(n, k);

	printf("\nEl resultado de la formula combinatoria es: %d\n", resultado);

	return 0;
}