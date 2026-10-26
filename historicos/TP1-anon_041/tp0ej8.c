/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 0; 
	int b = 1;
	int i = 0;
	int numero;
	printf("Ingrese un numero entero mayor a 10 para ver los numeros de la sucesion de fibonacci menores a dicho numero: ");
	scanf("%d", &numero);
	if (numero > 10)
	{	
		while (i < numero)
		{	
			printf("%d\n", i);
			i = a + b;
			a = b;
			b = i;
		}
	}
	else
	{
		printf("Usted no ingreso un numero entero mayor a 10!");
	}
	return 0;
}