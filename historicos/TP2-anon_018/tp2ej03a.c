

#include <stdio.h>
double factorial();

int main(int argc, char *argv[])
{
	int numero;
	double res;
	printf("El siguiente programa calculara el factorial de un numero,\n");
	printf("Ingrese un numero mayor a 0: ");
	scanf("%d", &numero);
	if (numero>=0)
	{
		res = factorial(numero);
		printf("El resultado de %d!= %.0f\n",numero, res);
	}
	return 0;
}
double factorial(int numero, double resultado)
{//esta funcion retorna el factorial de numero.
	int i;
	resultado = 1;
	for (i=1;i<=numero;i++)
	{
		resultado = resultado * i;
	}
	return resultado;
}
