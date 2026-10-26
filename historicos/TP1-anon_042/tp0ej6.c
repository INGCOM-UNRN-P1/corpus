/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
*************************/
#include <stdio.h>
int factorial(int numero);
int main(int argc, char *argv[])
{
	int numero;
	int resultado;
	printf("Ingresar un numero: ");
	scanf("%d", &numero);
	resultado = factorial(numero);
	return resultado;
}

int factorial(int numero)
{
	int total = 1;
	int i;
	for(i=1;i <= numero;i++)
	{
		total = total * i;
	}
	printf("El factorial de %d es: %d", numero, total);
}