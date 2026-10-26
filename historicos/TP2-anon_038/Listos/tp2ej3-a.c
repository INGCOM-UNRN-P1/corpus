/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>

int factorial(int n)
{
	int i;
	int factorial = 1;
	
	for (i=1;i<=n;i++)
		{
		factorial = factorial * i;
		}
		
	return factorial;
}

int main(int argc, char *argv[])
{
	int n;

	printf("Ingrese un numero para calcular su factorial \n");
	scanf("%d", &n);

	int resultado_factorial = factorial(n);
	
	printf("El factorial es: %d \n", resultado_factorial);

	return 0;

}
