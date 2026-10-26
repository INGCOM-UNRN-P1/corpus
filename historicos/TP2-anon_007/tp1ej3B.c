/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
TP - 2
GitHub: anon_007
*************************/
#include <stdio.h>
double factorial(int numero);
double combinatorio(int numero, int otro_numero);
int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	double mostrar;
	while(1)
	{
		printf("Ingrese un numero n: ");
		fflush(stdout);
		scanf("%d", &numero);
		printf("Ingrese otro numero k: ");
		fflush(stdout);
		scanf("%d", &otro_numero);
		if (otro_numero <= numero && numero >= 0 && otro_numero >= 0)
		{
			break;
		}
		else
		{
			printf("k debe ser menor o igual a n \n y debe ser un numero natural");
		}
	}
	mostrar = combinatorio(numero, otro_numero);
	printf("El combinatorio entre %d y %d es: %0.lf", numero, otro_numero, mostrar);
}
double combinatorio(int numero, int otro_numero)
{
	return factorial(numero)/(factorial(otro_numero) * factorial(numero - otro_numero));
}
double factorial(int numero)
{
	double factorial = 1;
	for (int i = 2; i <= numero; i++)
	{
		factorial = i * factorial;
	}
	return factorial;
}