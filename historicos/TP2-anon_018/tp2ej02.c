/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
int producto();
double potencia();

int main(int argc, char *argv[])
{
	int numeron, numerom;
	double res;
	printf("El siguiente programa calculara n*m y tambien n^m.\n");
	printf("Tanto n como m deben ser numeros naturales.\n");
	printf("Ingrese un numero n:");
	scanf("%d", &numeron);
	printf("Ingrese un numero m:");
	scanf("%d", &numerom);
	if (numerom>=0 && numeron>=0)
	{
		res = producto(numeron, numerom);
		printf("El resultado de n*m= %.0f\n", res);
		res = potencia(numeron, numerom);
		printf("El resultado de n^m= %.0f\n", res);
	}
	return 0;
}

int producto(int numeron, int numerom)
{//esta funcion devuelve el resultado del producto de dos numeros.
	int resultado;
	resultado = numeron * numerom;
	return resultado;
}
double potencia(int numeron, int numerom)
{//esta funcion realiza la potencia de numeron como base
 // y numerom como exponente.
	int resultado, i = 2;
	double pot = numeron;
	if (numerom == 0)
	{
		resultado = 1;
	}
	if (numerom == 1)
	{
		resultado = numeron;
	}
	while (i <= numerom)
	{
		pot = pot * numeron;
		resultado = pot;
		i++;
	}
	return resultado;
}