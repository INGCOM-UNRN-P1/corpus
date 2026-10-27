
#include <stdio.h>
#include <stdlib.h>

int raiz(int numero)
{	
	int i = 0;
	int res;
	if(numero>0)
	{
		do
		{
			i = i +1;
			res = i * i;
		}
		while(numero>res);
		return i;
	}
	else
	{
		printf("el numero no es un numero natural");
	}
	
}

int dosraices(int numero2, int numero3)
{

	int i = 0;
	int j = 0;
	int res;
	if(numero2>0)
	{
		do
		{
			i = i +1;
			res = i * i;
		}
		while(numero2>res);
		return i;
	}
	else
	{
		printf("el numero no es un numero natural");
	}
	
}	
int main(int argc, char *argv[])
{
	int numero, numero2, numero3, resultado1, resultado2;
	printf("ingrese un numero: ");
	scanf("%d", &numero);
	resultado1= raiz(numero);
	printf("la parte entera de la raiz cuadrada de %d es %d", numero, resultado1);
	return 0;
} 

