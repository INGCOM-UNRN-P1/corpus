/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int factorial(int n);

int main(int argc, char *argv[])
{
	int n;
	unsigned long long int resultado_factorial;
	while(1)
    {
        printf("Ingrese un numero natural para saber su factorial: ");
        scanf("%d", &n);
        if(n > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0\n");
        }
    }
	resultado_factorial = factorial(n);
	printf("%llu", resultado_factorial);
	
	return 0;
}


int factorial(int n)
{
	unsigned long long int multiplicar;
	unsigned long long int factorial = 1;
	for (multiplicar = 1; multiplicar <= n; multiplicar++)
	{
		factorial = factorial * multiplicar;
	}
	
	return factorial;
}