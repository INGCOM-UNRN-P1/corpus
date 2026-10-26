/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_023
*************************/

#include <stdio.h>

int main (int argc, char *argv[]) 
{
	int numero, i, fibonacci = 0, a = 0, b = 1;
	printf("ingrese un numero mayor a 10: ");
	scanf("%d", &numero);
	
	if (numero>=10)
	{
		printf("los numeros de la sucesion de fibonacci menor a %d son:", numero);
		for(i = 1; i <= numero; i++)
		{
			printf(" %d", fibonacci);
			a = b;
			b = fibonacci;
			fibonacci = a + b;
			i = fibonacci;
			
		}
	}
	else
	{
		printf("el numero no es mayor a 10");
	}
	
	return 0;
}