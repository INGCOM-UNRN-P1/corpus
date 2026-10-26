/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/
#include <stdio.h>
#include <stdlib.h>

int triangulo(int altura)
{
	int i, j;
	
	for ( i = 1; i<=altura;i++)
	{
		for(j=1;j<=altura-i;j++)
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
	return 1;
}
int main()
{
	int altura;
	printf("Ingrese la altura del triangulo de asteriscos:\n ");
	scanf("%d", &altura);
	
	triangulo(altura);
	
	return 0;
}