/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int factorial(int numero);

int main()

{
	int numero;
	int resultado;
	printf("ingrese un numero para su saber su factorial: ");
	scanf("%d",&numero);
	
	resultado=factorial(numero);
	printf("%d",resultado);
	
	
	
}

int factorial(int numero)
{
	int contador=1;
	int resultado=1;
	while (contador<=numero)
	{
		resultado=resultado*contador;
		contador=contador+1;
	}
	
	return resultado;
}