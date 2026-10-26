/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>

int factorial(int n)
{
	int i;
	int factorial = 1;
	
	for (i=1;i<=n;i++)
		{
		factorial = factorial * i;
		}
		
	return factorial;
}

int combinatorio(int n, int k)
{
	int n_fact, k_fact, n_menos_k_fact;
	int n_menos_k = n - k;

	n_fact = factorial(n);
	k_fact = factorial(k);
	n_menos_k_fact = factorial(n_menos_k);
	
	int resultado_combinatorio = n_fact/(k_fact * n_menos_k_fact);
	
	return resultado_combinatorio;
}

int main(int argc, char *argv[])
{
	int n, k, contador;
	
	printf("Ingrese el primer numero (n) para hacer el combinatorio #");
	scanf("%d", &n);
	
	printf("Ingrese el segundo numero (k) para hacer el combinatorio, este debe ser menor o igual a n, #");
	scanf("%d", &k);	
	
	if (n>=k)
	{
		while (k != 0)
			{
			int resultado_combinatorio = combinatorio(n, k);
	
			printf("El combinatorio de %d y %d es #%d \n", n, k, resultado_combinatorio);
			
			k--;
			}
	}
	else
	{
	printf("El numero k (%d) es mayor que el numero n(%d), por favor ingrese numero validos \n", k, n);
	}
	
}
