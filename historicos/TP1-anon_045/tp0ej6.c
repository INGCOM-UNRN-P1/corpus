
#include <stdio.h>

int factorial(int num);

int main(int argc, char *argv[])
{
	int num1; 
	int resultado;

	printf("Ingrese un numero entero:\t");
	scanf("%d", &num1);	
	
	resultado = factorial(num1);
	
	printf("El factorial de %d! es: %d",num1,resultado);
	
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



