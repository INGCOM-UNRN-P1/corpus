/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>
#include <stdlib.h>

int cuadrado(int cantidad)
{
	int i, j;
	for(j = 1; j <= cantidad; j++)
	{
		for (i = 1; i<=cantidad;i++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 1;
}

int main()
{
	int cantidad;
	printf("Ingrese el tamaño del cuadrado:\n ");
	scanf("%d", &cantidad);
	
	cuadrado(cantidad);
	
	return 0;
}