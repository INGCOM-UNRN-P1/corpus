/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>
int es_primo(int numero);
int main(int argc, char *argv[])
{
	int numero = 0;
	int resultado = 0;
	
	printf("Ingrese un numero entero para analizar si es primo (1) o si no lo es (0): #");
	scanf("%d%", &numero);
	
	resultado = es_primo(numero);
	printf("%d", resultado);
	
	return 0;
}

int es_primo(int numero)
{
	int i = 2;
	
	for (i; i < numero; i++)
	{
		if ((numero % i) == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}