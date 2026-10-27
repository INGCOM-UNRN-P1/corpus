
#include <stdio.h>
#include <stdlib.h>

void linea(int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf("*");
	}
	printf("\n\n");
}

void cuadrado(int n)
{
	int i, j;
	for(j = 0; j < n; j++)
	{
		for (i = 0;i < n;i++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("\n");
}

void triangulo(int n)
{
	int i, j;
	
	for (i = 0; i<n;i++)
	{
		for(j=0;j<i+1;j++)
			printf("* ");
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int n;
	printf("Ingrese n: ");
	scanf("%d", &n);
	
	linea(n);
	cuadrado(n);
	triangulo(n);
	
	return 0;
}