/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_020
*************************/

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int numero, i, fibonacci = 0, inicial = 0, inicial2 = 1;
	printf("ingrese un numero mayor a 10: ");
	scanf("%d", &numero);
	
	if (numero>=10)
	{
		printf("los numeros de la sucesion de fibonacci son:");
		for(i = 1; i <= numero; i++)
		{
			printf(" %d", fibonacci);
			inicial = inicial2;
			inicial2 = fibonacci;
			fibonacci = inicial + inicial2;
			i = fibonacci;
			
		}
	}
	else
	{
		printf("el numero no es mayor que 10");
	}
	return 0;
}