/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>
#include <stdlib.h>

int divisiones(int n, int m)
{
	int i, resultado;
	
	for(i=m;i<n&&i>0;i++)
	{
		resultado = n / m;
		
	}
	return resultado;
	
}
int main()
{
	int m, n, i, resultado;

	printf("\nIngrese el valor de n: ");
	scanf("%d", &n);
	m = n;

	for(i=0;i<n;i++)
	{
		m--;
		resultado = divisiones(n, m);
		printf("%d dividido %d da %d en numeros enteros\n",n, m, resultado);
		
		
	}

	return 0;
}