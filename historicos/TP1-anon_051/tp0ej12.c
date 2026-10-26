/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int comparacion(int entero_a, int entero_b);
int main(int argc, char *argv[])
{
	int entero_a = 0;
	int entero_b = 0;
	int total;
	printf("Ingrese un numero entero: ");
	scanf("%d", &entero_a);
	printf("Ingrese otro numero entero: ");
	scanf("%d", &entero_b);
	total = comparacion(entero_a, entero_b);
	return total;
}
int comparacion(int entero_a, int entero_b)
{
	if (entero_a < entero_b)
	{
		printf("-1");
	}
	if (entero_a == entero_b)
	{
		printf("0");
	}
	if (entero_a > entero_b)
	{
		printf("1");
	}
}

