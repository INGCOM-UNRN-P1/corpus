/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
int compara(int numero, int otro_numero);
int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	int mostrar;
	printf("Ingresa un numero: ");
	fflush(stdout);
	scanf("%d", &numero);
	printf("Ingresa otro numero: ");
	fflush(stdout);
	scanf("%d", &otro_numero);
	mostrar = compara(numero, otro_numero);
	printf("La comparación dió: %d", mostrar);
}
int compara(int numero, int otro_numero)
{
	if (numero == otro_numero)
	{
		return 0;
	}
	else
	{
		if (numero < otro_numero)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
}
