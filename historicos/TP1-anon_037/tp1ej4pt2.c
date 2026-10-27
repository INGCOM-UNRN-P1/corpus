

#include <stdio.h>

int es_primo(int numero);

int main()
{
	int numero;
	int resultado;
	
	printf("Ingrese un numero para comprobar si es primo --> ");
	scanf("%d", &numero);
	
	resultado = es_primo(numero);
	
	if (resultado == 0)
	{
		printf("El numero ingresado es primo.");
	}
	
	else
	{
		printf("El numero ingresado no es primo.");
	}
}

int es_primo(int numero)
{
	int i;
	int res = 0;
	
	for (i = 2; i < numero; i++)
	{	
		if (numero % i == 0)
		{
			res += 1;
		}
	}
	
	return res;
}