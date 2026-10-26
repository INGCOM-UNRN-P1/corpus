/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_039 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero = 0;
	unsigned long long int factorial = 1;
	int i = 1;
	
	printf("Ingrese el numero entero para calcular su factorial: ");
	scanf("%d", &numero);
	
	for (i; i <= numero; i++)
	{
		factorial = factorial * i;
		
		printf("El factorial de %d!= %llu\n", i, factorial);
	}
	
	return 0;
}