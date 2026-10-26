


#include <stdio.h>

int factorial(int numero);

int main()
{
    int	numero, resultado_factorial;
	
	do
	{
		printf("Digite un numero entero positivo para calcular su factorial: ");
		scanf("%d", &numero);
	}
	while(numero < 1);

	resultado_factorial = factorial(numero);
    printf("El factorial de %d es %d\n", numero, resultado_factorial);

	return 0;
}


int factorial(int numero)
{
    int i;
	int factorial = 1;

    for(i = 1; i <= numero; i++)
	{	
		factorial = factorial * i;
	}
    return factorial;
}
