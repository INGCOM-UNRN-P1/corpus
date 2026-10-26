/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero = 0;
	int factorial = 1;
	int i = 2;
	printf("Ingrese un numero entero: ");
	fflush(stdout);
	scanf("%d", &numero);
	while (numero >= 1)
	{
		for (i; i <= numero; i++)
		{
			factorial = i * factorial;
		}
		printf("El factorial de %d es: %d\n",numero, factorial);
		numero--;
		factorial = 1;
		i = 2;
	}
}