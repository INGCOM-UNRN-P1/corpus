
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










int main(int argc, char *argv[])
{
	int numero, numero2, resultado1, resultado2;
	printf("ingrese un numero para calcular su raiz cuadrada: ");
	scanf("%d", &numero);
	printf("ingrese otro numero para calcular su raiz cuadrada: ");
	scanf("%d", &numero2);
	resultado1= raiz(numero);
	resultado2= raiz(numero2);
	
	
	printf("la parte entera de la raiz cuadrada de %d es %d\n", numero, resultado1);
	printf("la parte entera de la raiz cuadrada de %d es %d", numero2, resultado2);
	return 0;
} 

