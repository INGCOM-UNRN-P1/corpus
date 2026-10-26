/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero;
	int i;
	int factorial = 1;
	
	printf("Ingrese un numero para calcular su factorial \n");
	scanf("%d", &numero);

	for (i=1;i<=numero;i++)
		{
		factorial = factorial * i;
		printf("El factorial de %d es: %d \n", i,factorial);
		}
		
	return 0;

}

