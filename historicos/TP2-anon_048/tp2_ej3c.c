/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
fergim92
*************************/

#include <stdio.h>

int solicitarNumero();
int factorial(int numero);
int combinatorio(int n, int k);
int imprimirValoresMenores(int k, int n);

int main(int argc, char *argv[])
{
    int	n, k;
	
	printf("Digite un numero entero positivo: ");
	n = solicitarNumero();
	do
    {
    	printf("Digite otro numero entero positivo y menor o igual al primero: ");
    	k = solicitarNumero();
	}
	while(k > n);
	printf("Combinatorios de k menores a n:\n");
    imprimirValoresMenores(n, k);
	
	return 0;
}


int factorial(int numero)
{
	int i, factorial;
	factorial = 1;
	
	for(i = 1; i <= numero; i++)
	{	
		factorial = factorial * i;
	}

	return factorial;
}



int combinatorio(int n, int k)
{
	int combinatorio = 0,
		factorialN   = 0,
	    factorialK   = 0,
	    factorialNK  = 0,
		resta        = 0;
		
	factorialN = factorial(n);
	factorialK = factorial(k);
	resta = n - k;
	factorialNK = factorial(resta);
	combinatorio = factorialN / (factorialK * factorialNK);
	
	return combinatorio;
}


int solicitarNumero()
{
	int n;
	
		do
	{
		scanf("%d", &n);
		if(n < 1)
		{
		printf("Entero positivo!: ");
		}
	}
	while(n < 1);
}

imprimirValoresMenores(int n, int k)
{
	int i, combinatorioN;
	i = 1;
	combinatorioN = 0;
	
	while(i < n)
	{
		combinatorioN = combinatorio(n, i);
		printf("%d\n", combinatorioN);
		i = i +1;
	}
}
