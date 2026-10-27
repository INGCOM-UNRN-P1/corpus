

#include <stdio.h>

int raizcuadrada(int numero);

int main()
{
	int numerouno;
	int numerodos;
	int resultadouno;
	int resultadodos;
	
	printf("Ingrese dos numeros naturales:\n");
	scanf("%d", &numerouno);
	scanf("%d", &numerodos);

	resultadouno = raizcuadrada(numerouno);
	resultadodos = raizcuadrada(numerodos);
	
	printf("La raiz cuadrada(parte entera) de %d es: %d\n", numerouno, resultadouno);
	printf("La raiz cuadrada(parte entera) de %d es: %d", numerodos, resultadodos);
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