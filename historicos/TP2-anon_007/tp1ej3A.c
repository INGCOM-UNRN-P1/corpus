
#include <stdio.h>
int factorial(int numero);
int main(int argc, char *argv[])
{
	int numero;
	int mostrar;
	printf("Ingrese un numero natural: ");
	fflush(stdout);
	scanf("%d", &numero);
	mostrar = factorial(numero);
	printf("%d! = %d", numero, mostrar);
}
int factorial(int numero)
{
	int factorial = 1;
	for (int i = 2; i <= numero; i++)
	{
		factorial = i * factorial;
	}
	return factorial;
}