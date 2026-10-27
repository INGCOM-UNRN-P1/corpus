

#include <stdio.h>

int raizcuadrada(int numero);

int main()
{
	int numero;
	int resultado;
	
	printf("Ingrese un numero natural --> ");
	scanf("%d", &numero);

	resultado = raizcuadrada(numero);
	printf("La raiz cuadrada(parte entera) de %d es: %d", numero, resultado);
}


int raizcuadrada(int numero)
{
	int i = 1;
	int res;

	for (i; i <= numero; i++)
	{
		if(i * i <= numero)
		{
			res = i;
		}
		else
		{
		;
		}
	}
	return res;
}