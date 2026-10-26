/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int es_primo(int numero);
int main(int argc, char *argv[])
{
	int numero = 0;
	int total;
	printf("Ingrese un numero para saber si es primo o no, en caso de serlo se muestra 1, caso contrario 0:");
	scanf("%d", &numero);
	total = es_primo(numero);
	return total;
}
int es_primo(int numero)
{
	int contador = 0;
	int i = 0;
	for(i=1;i<=numero;i++)
	{
		if (numero%i == 0)
		{
			contador++;
		}
	}
	if (contador == 2)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}
