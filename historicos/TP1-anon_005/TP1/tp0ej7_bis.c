/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 7 - Factorial*reload
*************************/
#include <stdio.h>
 
int factorial(int num1)
{
	int i;
	int resultado=1;
	for (i = 1; i < num1+1; i++)
	{
		resultado = resultado*i;
		printf("El factorial de %d!: %d \n",i, resultado);
	}	
	return 0;
}

int main(int argc, char *argv[])
{
	int numero;
	printf("Ingrese un numero entero \n");
	scanf("%d",&numero);
	printf("numero: %d\n", numero);
	int resultado = factorial(numero);
	return 0;
}