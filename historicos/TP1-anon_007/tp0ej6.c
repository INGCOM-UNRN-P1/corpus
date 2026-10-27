
#include <stdio.h>
int main(int argc, char *argv[])
{
	int numero = 0;
	int factorial = 1;
	int i = 2;
	printf("Ingrese un numero entero: ");
	fflush(stdout);
	scanf("%d", &numero);
	for (i; i <= numero; i++)
	{
		factorial = i * factorial;
	}
	printf("El factorial de %d es: %d\n",numero, factorial);
}