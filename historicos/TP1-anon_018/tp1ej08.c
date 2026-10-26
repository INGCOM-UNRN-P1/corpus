/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
#define SIZE 1000

int main(int argc, char *argv[])
{
	int numeroin, i, n;
	double fib1, fib2, res;
	printf("El programa imprimira los numeros de la susecion ");
	printf("Fibonacci hasta el numero ingresado. \n");
	printf("Ingrese un numero mayor a 100: ");
	scanf("%d", &numeroin);
	if (numeroin < 100)
	{
		printf("El numero debe ser mayor que 100, intente nuevamente.\n");
		return 0;
	}
	double fibonacci [SIZE];
	fib1 = 0;
	fib2 = 1;
	fibonacci [0] = fib1;
	fibonacci [1] = fib2;
	i = 1;
	res = fib1 + fib2;
	while (res < numeroin)
	{
		fibonacci [i] = res;
		res = fib1 + fib2;
		fib1 = fib2;
		fib2 = res;
		i++;
	}
	printf("Los numeros de la sucesion de fibonacci menor a %d son: ", numeroin);
	for (n=0;n<i;n++)
	{
		printf("%.0f; ", fibonacci[n]);
	}
	printf("\n");
	return 0;
}