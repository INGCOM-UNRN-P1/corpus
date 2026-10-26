/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int bucle(int entero, int guardador);
int main(int argc, char *argv[])
{
	int entero = 0;
	int guardador = 0;
	int total;
	printf("Ingrese un entero para determinar si es mayor a 100 \n");
	scanf("%d", &entero);
	total = bucle(entero, guardador);
	return total;
	
}
int bucle(int entero, int guardador)
{
	while (entero < 100)
	{
		printf("El numero es menor a 100 \n");
		printf("Ingrese otro entero para determinar si es mayor a 100 \n");
		scanf("%d", &entero);
		if (entero > 100)
		{
			break;
		}
	}
	printf("el numero %d es mayor a 100", entero); 
}