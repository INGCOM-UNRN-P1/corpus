/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numeroin, i;
	double res;
	res = 1;
	printf("Este programa calculara el factorial del numero ingresado.\n");
	printf("Ingresar un numero entero positivo: ");
	scanf("%d", &numeroin);
	if (numeroin <= 0)
	{
		printf("El numero debe ser mayor a 0, vuelva a intentarlo.\n");
		return 0;
	}
	for (i=1;i<=numeroin;i++)
	{
		res = res * i;
	}
	printf("El factorial de %d! es: %.0f\n", numeroin, res);
	while (numeroin != 1)
	{
		res = res / numeroin;
		numeroin--;
		printf("El factorial de %d! es: %.0f\n", numeroin, res);
	}
	
	
	return 0;
}