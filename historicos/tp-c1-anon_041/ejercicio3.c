

#include <stdio.h>


int signo(int numero)
{
	int comparacion = numero + numero;
	
	if (numero > comparacion)
	{
		return -1;
	}
	
	else if (numero < comparacion)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}


int main()
{
	int numero;
	int resultado;
	printf("Ingrese un número para saber si es cero, positivo o negativo: \n");
	scanf("%d", &numero);
	resultado = signo(numero);
	
	if (resultado > 0)
	{
		printf("El número %d es positivo\n", numero);
	}
	
	else if(resultado < 0)
	{
		printf("El número %d es negativo\n", numero);
	}
	
	else
	{
		printf("El numero %d es igual a cero\n", numero);
	}
	
	return 0;
}