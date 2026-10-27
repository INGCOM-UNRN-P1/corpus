

#include <stdio.h>

int asteriscos(int numero_n);


int main()
{
	int numero_n;
	int retorno;
	
	printf("Ingrese un numero natural --> ");
	scanf("%d", &numero_n);
	
	retorno = asteriscos(numero_n);
}


int asteriscos(int numero_n)
{
	int i = 1;

	for (i; i <= numero_n; i++)
	{
		printf("*");
	}
}