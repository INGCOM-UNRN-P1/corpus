
#include <stdio.h>
 
int fibonacci(int num);

int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero entero mayor a 10: \n");
	scanf("%d",&numero);
	printf("numero: %d\n", numero);
	int resultado = fibonacci(numero);
	return 0;
}


int fibonacci(int num)
{
	int primero = 0;
	int segundo = 1;
	int resultado = 1;
	if(num > 10)
	{
		printf("Los numeros de la sucesion de fibonacci menor a %d son: 0, ", num);
		while(resultado < num)
		{
			if(resultado <= (num - segundo))
			{
				printf("%d, ", resultado);
				resultado = primero + segundo;
				primero = segundo;
				segundo = resultado;
			}
			else if(resultado >= (num - segundo))
			{
				printf("%d ", resultado);
				resultado = primero + segundo;
				primero = segundo;
				segundo = resultado;
			}
		}
	}
	else
	{
	printf("El numero ingresado es invalido \n");	
	}
	return 0;
}

