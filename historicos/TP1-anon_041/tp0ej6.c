
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long long int numero;
	unsigned long long int multiplicar;
	unsigned long long int factorial = 1;
	printf("Ingrese un numero entero para saber su factorial: !");
	scanf("%llu", &numero);
	for (multiplicar = 1; multiplicar <= numero; multiplicar++)
	{
		factorial = factorial * multiplicar;
	}
	printf("El factorial de %llu es: %llu\n", numero, factorial);
	
	return 0;
}