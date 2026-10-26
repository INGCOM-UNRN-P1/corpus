/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero = 0;
	int multiplo = 2;
	while (numero <= 100)
	{
		printf("Ingrese un numero entero mayor a 100: ");
		fflush(stdout);
		scanf("%d", &numero);
		if (numero > 100)
		{
			break;
		}
	}
	for(multiplo = 2; multiplo <= 6; multiplo++)
	{
		if (numero % multiplo == 0)
		{
			printf("Es multiplo de %d: SI \n", multiplo);
		}
		else
		{
			printf("Es multiplo de %d: NO \n", multiplo);
		}
	}
}