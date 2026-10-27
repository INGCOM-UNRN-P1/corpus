
#include <stdio.h>
 
int factorial(int num1);

int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero entero \n");
	scanf("%d",&numero);
	printf("numero: %d\n", numero);
	int resultado = factorial(numero);
	return 0;
}

int factorial(int num1)
{
	int i;
	int j;
	int resultado=1;
	for (i = 1; i < num1+1; i++)
		{
			resultado = resultado*i;	
		}
	for (j= num1; j>0; j--)
	{
		printf("El factorial de %d!: %d \n",j, resultado);	
		resultado = resultado/j;
	}	
	return 0;
}