/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_048
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int	numero, i, a, b, c;
	
	a = 0;
	b = 1;
	c = 1;
	
	do
	{
		printf("Ingrese un numero entero mayor a 10: ");
		scanf("%d", &numero);
	}
	while(numero <= 10);
	
	printf("Los numeros de la sucesion de fibonacci menor a %d son: %d", numero, a);
	
	while(c < numero)
	{
		printf(",%d", c);
		c = a + b;
		a = b;
		b = c;
	}
		
	return 0;
}
