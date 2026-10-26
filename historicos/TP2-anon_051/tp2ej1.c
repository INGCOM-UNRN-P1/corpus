/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/

#include <stdio.h>
int cuenta(int numero_n, int numero_m);
int main(int argc, char *argv[])
{
	int numero_n = 0;
	int numero_m = 0;
	int total;
	printf("Ingrese un numero natural: ");
	scanf("%d", &numero_n);
	printf("Ingrese otro numero natural: ");
	scanf("%d", &numero_m);
	total = cuenta(numero_n, numero_m);
	return total;
}
int cuenta(int numero_n, int numero_m)
{
	int i = 0;
	for (i=0 ; i<numero_n; i++)
	{
		if (i*i == numero_n)
		{
			printf("La raiz de %d es %d \n", numero_n, i);
			break;
		}
		if (i*i >= numero_n)
		{
			printf("La parte entera de la raiz de %d es %d \n", numero_n, i-1);
			break;
		}
	}
	for (i=0 ; i<numero_m; i++)
	{
		if (i*i == numero_m)
		{
			printf("La raiz de %d es %d \n", numero_m, i);
			break;
		}
		if (i*i >= numero_m)
		{
			printf("La parte entera de la raiz de %d es %d \n", numero_m, i-1);
			break;
		}
	}
	return i;
}