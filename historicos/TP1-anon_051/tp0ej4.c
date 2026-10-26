/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int multiplo(int numero_entero, int i);
int main(int argc, char *argv[])
{
	int total;
	int i;
	int numero_entero;
	printf("ingrese un numero entero mayor a 100 \n");
	scanf("%d", &numero_entero);
	total = multiplo(numero_entero, i);
	return total;
}
int multiplo (int numero_entero, int i)
{
	if (numero_entero < 100)
	{
		printf("El numero entero tiene que ser mayor a 100 \n");
		return 0;
	}
	for (i=2;i<7;i++)
	{
		if (numero_entero %i == 0)
		{
			printf("Es multiplo de %i : SI \n", i);
		}
		else
		{
			printf("Es multiplo de %i : NO \n", i);
		}
	}
}