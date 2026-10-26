/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
#define ALMACENAMIENTO 300
int factorial (int numero_entero, int i);
int main(int argc, char *argv[])
{
	int numero_entero = 0;
	int i = 0;
	int total;
	printf("Ingrese un numero entero para calcular su factorial \n");
	scanf("%d", &numero_entero);
	total = factorial(numero_entero, i);
	return total;
}
int factorial (int numero_entero, int i)
{
	double suma = 1;
	double vector[ALMACENAMIENTO];
	int f = 0;
	for (i=1;i<=numero_entero;i++)
	{
		suma = suma * i;
		vector[ALMACENAMIENTO] = suma;
		vector[i] = vector[ALMACENAMIENTO];
	}
	printf("El factorial de %d es %f \n", numero_entero, suma);
	for (f=numero_entero-1;f>=1;f--)
	{
		printf("El factorial de %d es %f \n", f, vector[f]);
	}
}
