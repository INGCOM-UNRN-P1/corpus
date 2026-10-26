/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
fergim92
*************************/

#include <stdio.h>

int solicitarNumero();
int factorial(int numero);


int main(int argc, char *argv[])
{
    int	n, factorialN;
	
	printf("Digite un numero entero positivo: ");
	n = solicitarNumero();
	factorialN = factorial(n);
	printf("El factorial de %d es %d\n", n, factorialN);

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
