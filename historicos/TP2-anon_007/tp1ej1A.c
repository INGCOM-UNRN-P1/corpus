/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
TP - 2
GitHub: anon_007
*************************/
#include <stdio.h>
int raiz(int numero);
int main(int argc, char *argv[])
{
	int numero;
	int mostrar;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%d", &numero);
	mostrar = raiz(numero);
	if (mostrar != numero)
	{
		printf("La raiz cuadrada de %d es: %d\n", numero, mostrar);
	}
	else
	{
		printf("No existe la raiz cuadrada de %d en los numeros naturales", numero);
	}
}
int raiz(int numero)
{
	int i = 0;
	while (i < numero)
	{
		if ((i * i) == numero && i != numero)
		{
			break;
		}
		i++;
	}
	return i;
}