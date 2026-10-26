

#include <stdio.h>
#define TRUE 1
#define FALSE 0


int es_primo(int numero)
{
	int i;
	
	if (numero < 2)
	{
		return 0;
	}
	
	else if (numero == 2)
	{
		return 1;
	}
	if (numero == 4)
	{
		return 0;
	}
	
	for(i = 2; i < numero / 2; i++)
	{
		if (numero % i == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	int numero;
	int resultado;
	
	printf("Ingrese un numero para saber si es primo: \n");
	scanf("%d", &numero);
	
	resultado = es_primo(numero);
	
	if(resultado==TRUE)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	
	return 0;
}