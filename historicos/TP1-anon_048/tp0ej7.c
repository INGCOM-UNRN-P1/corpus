/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
fergim92
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int	numero, i, factorial;
	
	do
	{
		printf("Digite un numero entero positivo para calcular su factorial: ");
		scanf("%d", &numero);
	}
	while(numero < 1);
	
	while(numero > 0)
	{
		factorial = 1;
		for(i = 1; i <= numero; i++)
		{	
			factorial = factorial * i;
		}
		printf("El factorial de %d es %d\n", numero, factorial);
		numero = numero - 1;
	}	
	return 0;
}
