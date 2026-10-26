
#include <stdio.h>

int factorial(int num);

int main(int argc, char *argv[])
{
	int num1; 
	int resultado;

	printf("Ingrese un numero entero:\t");
	scanf("%d", &num1);	
	
	for (int i=num1; i>=1; i-=1)
	{
		resultado = factorial(i);
	
		printf("El factorial de %d! es: %d \n",i,resultado);
	}
	
}

int factorial(int num1)
{
	int factorial = 1;
	for (int i=1; i<(num1+1); i+=1)
	{

		factorial = factorial*i;

	}
	
	return factorial;
}



