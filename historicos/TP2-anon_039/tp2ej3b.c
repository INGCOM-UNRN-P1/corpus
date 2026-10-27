
#include <stdio.h>

int factorial(int n);
int combinatorio(int n, int k);

int main(int argc, char *argv[])
{
	int n;
	int k;
	int resultado_combinatorio;
	
	while(1)
	{
		printf("Ingrese el primer numero (n): ");
		scanf("%d", &n);
		if (n > 0)
		{
			break;
		}
		else
		{
			printf("Ingrese un numero natural\n");
		}
	}
	while(1)
	{
		printf("Ingrese el segundo numero (k) que debe ser menor o igual al anterior: ");
		scanf("%d", &k);
		if ( k <= n)
		{
			break;
		}
		else
		{
			printf("Ingrese un menor o igual al primero\n");
		}
	}
	
	resultado_combinatorio = combinatorio(n, k);
	printf("El resultado es %d", resultado_combinatorio);
}

int combinatorio(int n, int k)
{
	int factorial_n = factorial(n);
	int factorial_k = factorial(k);
	int factorial_nk = factorial(n-k);
	int resultado_combinatorio;
	
	resultado_combinatorio = factorial_n / (factorial_k * factorial_nk);
	return resultado_combinatorio;
}

int factorial(int n)
{
	long long int i;
	unsigned long long int resultado = 1;
	
	for(i = 1;i <= n;i++)
	{
		resultado = resultado * i;
	}
	
	return resultado;
}