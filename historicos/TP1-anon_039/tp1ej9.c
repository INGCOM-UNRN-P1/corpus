
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	unsigned long long int numero = 0;
	
	printf("Ingrese un numero entero mayor a 100: # ");
	scanf("%llu", &numero);
	
	while (numero < 100)
	{
		printf("El numero %llu no es mayor a 100\n", numero);
		printf("Ingrese un numero entero mayor a 100: # ");
		scanf("%llu", &numero);
	}
	
	printf("El numero %llu es mayor a 100.", numero);
	
	return 0;
}