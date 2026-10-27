
#include <stdio.h>
#include <stdlib.h>

long long factorial(int n)
{
	long long fact = 1;
	int i;

	for(i = 1; i <= n; i++)
	{
		fact  = fact * i;
	}

	return fact;
}

long combinatorio(int n, int k)
{
	long res;

	if(k <= n)
	{
		res = factorial(n)/(factorial(k) * factorial(n - k));
	}
	else
	{
		return -1;
	}

	return res;
}

void combinatorio_sucesivo(int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("\nCombinatorio (%d,%d) = %ld",n,i,combinatorio(n,i));
	}
}

int main(int argc, char *argv[])
{
	int n,k;
	long long resultado;
	long combina;
	printf("\nIngrese un numero n: ");
	scanf("%d", &n);
	printf("\nIngrese un numero k: ");
	scanf("%d", &k);

	resultado = factorial(n);
	printf("%d! = %lld",n,resultado);
	combina = combinatorio(n,k);
	printf("\nCombinatorio (%d,%d) = %ld",n,k,combina);
	printf("\n\nCombinatorio sucesivo:");
	combinatorio_sucesivo(n);

	return 0;
}